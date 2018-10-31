#ifndef CPP_ADVANCED_EXTENSIONS_H
#define CPP_ADVANCED_EXTENSIONS_H

#include <stack>
#include "InputInterpreter.h"

class DivisionOperation : public Operation {
private:
  std::vector<int> operands;
  int result;
public:
  void addOperand(int operand) override {
    this->operands.push_back(operand);

    if (this->isCompleted()) {
      this->result = this->operands[0] / this->operands[1];
    }
  }

  bool isCompleted() override {
    return this->operands.size() == 2;
  }

  int getResult() override {
    return this->result;
  }
};

class MemoryPushOperation : public Operation {
private:
  std::stack<int> memory;
public:
  void addOperand(int operand) override {
    this->memory.push(operand);
  }

  bool isCompleted() override {
    return false;
  }

  int getResult() override {
    int result = this->memory.top();
    this->memory.pop();
    return result;
  }
};

class MemoryPopOperation : public Operation {
private:
  std::shared_ptr<MemoryPushOperation> memoryPtr;
public:
  MemoryPopOperation(std::shared_ptr<MemoryPushOperation> memoryPtr) : memoryPtr(std::move(memoryPtr)) { }

  void addOperand(int operand) override { }

  bool isCompleted() override {
    return true;
  }

  int getResult() override {
    return this->memoryPtr->getResult();
  }
};

class AdvancedInputInterpreter : public InputInterpreter {
private:
  std::shared_ptr<MemoryPushOperation> memoryPtr;
public:
  AdvancedInputInterpreter(CalculationEngine& engine)
      : InputInterpreter(engine), memoryPtr(std::make_shared<MemoryPushOperation>()) { }

  std::shared_ptr<Operation> getOperation(std::string operation) override {
    if (operation == "*") {
      return std::make_shared<MultiplicationOperation>();
    } else if (operation == "/") {
      return std::make_shared<DivisionOperation>();
    } else if (operation == "ms") {
      return this->memoryPtr;
    } else if (operation == "mr") {
      return std::make_shared<MemoryPopOperation>(this->memoryPtr);
    }

    return std::shared_ptr<Operation>(nullptr);
  }
};

std::shared_ptr<InputInterpreter> buildInterpreter(CalculationEngine& engine) {
  return std::make_shared<AdvancedInputInterpreter>(engine);
}

#endif //CPP_ADVANCED_EXTENSIONS_H
