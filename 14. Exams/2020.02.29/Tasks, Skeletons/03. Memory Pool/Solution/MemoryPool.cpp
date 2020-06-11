#include "MemoryPool.h"

MemoryPool::MemoryPool(const int memoryPoolSize) :
    _memoryBuffer(new int[memoryPoolSize]{ }),
    _isMemoryBufferOccupied(new bool[memoryPoolSize]{ }),
    _MEMORY_POOL_SIZE(memoryPoolSize) {

}

MemoryPool::~MemoryPool() {
  delete[] _memoryBuffer;
  _memoryBuffer = nullptr;

  delete[] _isMemoryBufferOccupied;
  _isMemoryBufferOccupied = nullptr;
}

ErrorCode MemoryPool::requestMemory(MemoryNode& outNode) {
  if (outNode.size > _MEMORY_POOL_SIZE) {
    return ErrorCode::REQUEST_FAILURE_BIGGER_THAN_BUFFER;
  }

  bool hasRequestSucceeded = false;
  int checkedFreeSlots = 0;

  //search for a free node
  for (int i = 0; i < _MEMORY_POOL_SIZE; ++i) {
    if (i + outNode.size > _MEMORY_POOL_SIZE) {
      break; //not enough remaining size
    }

    hasRequestSucceeded = true;
    checkedFreeSlots = 0;

    do {
      if (_isMemoryBufferOccupied[i + checkedFreeSlots]) {
        //slot is already occupied
        hasRequestSucceeded = false;
        break;
      }

      ++checkedFreeSlots;
    } while (checkedFreeSlots != outNode.size);

    if (hasRequestSucceeded) {
      outNode.bufferStartIndex = i;
      outNode.memory = &_memoryBuffer[i];
      occupyMemory(outNode);

      return REQUEST_SUCCESS;
    }
  }

  return REQUEST_FAILURE_NOT_ENOUGH_MEMORY;
}

void MemoryPool::releaseMemory(const MemoryNode& outNode) {
  for (int i = 0; i < outNode.size; ++i) {
    _isMemoryBufferOccupied[i + outNode.bufferStartIndex] = false;
  }
}

void MemoryPool::zeroMemoryValue(const MemoryNode& node) {
  for (int i = 0; i < node.size; ++i) {
    _memoryBuffer[i + node.bufferStartIndex] = 0;
  }
}

void MemoryPool::occupyMemory(const MemoryNode& node) {
  for (int i = 0; i < node.size; ++i) {
    _isMemoryBufferOccupied[i + node.bufferStartIndex] = true;
  }
}

