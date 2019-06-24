#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "Defines.h"

enum Action {
  IDLE = 0,
  ALLOCATE,
  DEALLOCATE
};

Action parseCommand(const std::string& command,
                    size_t& index);

std::string getErrorMessage(ErrorCode errorCode);

ErrorCode allocate(std::vector<int*>& memory,
                   size_t index);

ErrorCode deallocate(std::vector<int*>& memory,
                     size_t index);

ErrorCode executeCommand(const std::string& command,
                         std::vector<int*>& memory) {
  size_t index;
  Action action = parseCommand(command, index);

  if (action == IDLE) {
    return EXECUTE_IDLE;
  }

  if (index >= memory.size()) {
    return INDEX_OUT_OF_BOUND;
  }

  ErrorCode errorCode;
  if (action == ALLOCATE) {
    errorCode = allocate(memory, index);
  } else if (action == DEALLOCATE) {
    errorCode = deallocate(memory, index);
  } else {
    throw std::invalid_argument("Unknown action type");
  }

  return errorCode;
}

void printResult(const ErrorCode errorCode,
                 const std::string& command) {
  std::cout << command << " - " << getErrorMessage(errorCode) << std::endl;
}

std::string getErrorMessage(const ErrorCode errorCode) {
  switch (errorCode) {
  case EXECUTE_SUCCESS:
    return "success";
  case EXECUTE_IDLE:
    return "this exam is a piece of cake! Where is the OOP already?!?";
  case MEMORY_LEAK:
    return "memory leak prevented, will not make allocation";
  case DOUBLE_FREE:
    return "system crash prevented, will skip this deallocation";
  case INDEX_OUT_OF_BOUND:
    return "out of bound";
  default:
    throw std::invalid_argument("Unknown error code");
  }
}

ErrorCode allocate(std::vector<int*>& memory,
                   const size_t index) {
  if (memory.at(index)) {
    return MEMORY_LEAK;
  }

  memory[index] = new int(0);
  return EXECUTE_SUCCESS;
}

ErrorCode deallocate(std::vector<int*>& memory,
                     const size_t index) {
  int* data = memory.at(index);
  if (data) {
    delete data;
    memory[index] = nullptr;
    return EXECUTE_SUCCESS;
  }

  return DOUBLE_FREE;
}

Action parseCommand(const std::string& command,
                    size_t& index) {
  if (command == "Idle") {
    return IDLE;
  }

  std::istringstream lineIn(command);
  std::string action;
  lineIn >> action >> index;

  if (action == "Allocate") {
    return ALLOCATE;
  } else if (action == "Deallocate") {
    return DEALLOCATE;
  } else {
    throw std::invalid_argument("Unknown command");
  }
}
