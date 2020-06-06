#include <sstream>
#include <vector>
#include <iostream>
#include "Defines.h"

enum class MemoryOperation {
  ALLOCATE = 0,
  DEALLOCATE = 1,

  UNKNOWN = 255
};

MemoryType getMemoryTypeFromString(const std::string& type);

MemoryOperation getMemoryOperationFromString(const std::string& operation);

bool isFreeMemory(size_t index, std::vector<MemoryNode>& memory);

ErrorCode releaseMemory(size_t index, std::vector<MemoryNode>& memory, MemoryType memoryType);

ErrorCode allocateMemory(size_t index, std::vector<MemoryNode>& memory, MemoryType memoryType);

void printResult(const ErrorCode errorCode,
                 const std::string& command) {
  std::cout << command;
  switch (errorCode) {
  case ErrorCode::EXECUTE_SUCCESS:
    std::cout << " - success";
    break;
  case ErrorCode::MEMORY_LEAK:
    std::cout << " - memory leak prevented, will not make allocation";
    break;
  case ErrorCode::DOUBLE_FREE:
    std::cout << " - system crash prevented, will skip this deallocation";
    break;
  case ErrorCode::ALLOCATE_DEALLOCATE_MISMATCH:
    std::cout << " - Warning allocate/deallocate mismatch, will skip this deallocation";
    break;
  }
  std::cout << std::endl;
}

ErrorCode executeCommand(const std::string& command,
                         std::vector<MemoryNode>& memory) {
  std::istringstream iss{ command };
  std::string operation, type;
  size_t index;
  iss >> operation >> type >> index;
  MemoryType memoryType = getMemoryTypeFromString(type);
  MemoryOperation memoryOperation = getMemoryOperationFromString(operation);

  if (memoryOperation == MemoryOperation::ALLOCATE) {
    return allocateMemory(index, memory, memoryType);
  } else if (memoryOperation == MemoryOperation::DEALLOCATE) {
    return releaseMemory(index, memory, memoryType);
  } else {
    throw std::runtime_error("Unknown memory operation: " + operation);
  }
}

ErrorCode allocateMemory(const size_t index, std::vector<MemoryNode>& memory, const MemoryType memoryType) {
  if (!isFreeMemory(index, memory)) {
    return ErrorCode::MEMORY_LEAK;
  }

  switch (memoryType) {
  case MemoryType::SINGLE:
    memory[index].rawMemory = new int;
    break;
  case MemoryType::MULTIPLE:
    memory[index].rawMemory = new int[ALLOCATION_MULTIPLE_SIZE];
    break;
  default:
    throw std::runtime_error("Allocation - unknown memory type: " + std::to_string(memoryType));
  }

  memory[index].memoryType = memoryType;
  return ErrorCode::EXECUTE_SUCCESS;
}

ErrorCode releaseMemory(const size_t index, std::vector<MemoryNode>& memory, const MemoryType memoryType) {
  if (isFreeMemory(index, memory)) {
    return ErrorCode::DOUBLE_FREE;
  }

  if (memory[index].memoryType != memoryType) {
    return ErrorCode::ALLOCATE_DEALLOCATE_MISMATCH;
  }

  switch (memory[index].memoryType) {
  case MemoryType::SINGLE:
    delete memory[index].rawMemory;
    break;
  case MemoryType::MULTIPLE:
    delete[] memory[index].rawMemory;
    break;
  default:
    throw std::runtime_error("Deallocation - unknown memory type: " + std::to_string(memory[index].memoryType));
  }

  memory[index].rawMemory = nullptr;
  memory[index].memoryType = UNKNOWN;
  return ErrorCode::EXECUTE_SUCCESS;
}

bool isFreeMemory(size_t index, std::vector<MemoryNode>& memory) {
  return memory[index].rawMemory == nullptr;
}

MemoryType getMemoryTypeFromString(const std::string& type) {
  if (type == "Single") {
    return MemoryType::SINGLE;
  }
  if (type == "Multiple") {
    return MemoryType::MULTIPLE;
  }
  return MemoryType::UNKNOWN;
}

MemoryOperation getMemoryOperationFromString(const std::string& operation) {
  if (operation == "Allocate") {
    return MemoryOperation::ALLOCATE;
  }
  if (operation == "Deallocate") {
    return MemoryOperation::DEALLOCATE;
  }
  return MemoryOperation::UNKNOWN;
}
