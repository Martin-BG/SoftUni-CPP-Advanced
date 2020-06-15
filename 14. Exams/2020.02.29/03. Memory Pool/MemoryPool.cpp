#include <cstring>
#include "MemoryPool.h"

MemoryPool::MemoryPool(const int memoryPoolSize) :
    _memoryBuffer(new int[memoryPoolSize]{ }),
    _isMemoryBufferOccupied(new bool[memoryPoolSize]{ }),
    _MEMORY_POOL_SIZE(memoryPoolSize) { }

MemoryPool::~MemoryPool() {
  delete[] _isMemoryBufferOccupied;
  delete[] _memoryBuffer;
}

ErrorCode MemoryPool::requestMemory(MemoryNode& outNode) {
  if (outNode.size > _MEMORY_POOL_SIZE) {
    return REQUEST_FAILURE_BIGGER_THAN_BUFFER;
  }

  for (int i = 0, free = 0, startIndex = -1; i < _MEMORY_POOL_SIZE; ++i) {
    if (!_isMemoryBufferOccupied[i]) {
      ++free;
      if (startIndex == -1) {
        startIndex = i;
      }
    } else {
      free = 0;
      startIndex = -1;
    }

    if (free >= outNode.size) {
      outNode.bufferStartIndex = startIndex;
      outNode.memory = &_memoryBuffer[startIndex];
      occupyMemory(outNode);
      break;
    }
  }

  return (outNode.bufferStartIndex == -1)
         ? REQUEST_FAILURE_NOT_ENOUGH_MEMORY
         : REQUEST_SUCCESS;
}


void MemoryPool::releaseMemory(const MemoryNode& outNode) {
  std::memset(&_isMemoryBufferOccupied[outNode.bufferStartIndex],
              false,
              sizeof(bool) * outNode.size);
}

void MemoryPool::zeroMemoryValue(const MemoryNode& node) {
  std::memset(&_memoryBuffer[node.bufferStartIndex],
              0,
              sizeof(int) * node.size);
}

void MemoryPool::occupyMemory(const MemoryNode& node) {
  std::memset(&_isMemoryBufferOccupied[node.bufferStartIndex],
              true,
              sizeof(bool) * node.size);
}
