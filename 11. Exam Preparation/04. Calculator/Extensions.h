#ifndef CPP_ADVANCED_EXTENSIONS_H
#define CPP_ADVANCED_EXTENSIONS_H

#include <stack>

#include "InputInterpreter.h"

using Memory = std::stack<int>;

class BaseOperation : public Operation {
protected:
  int result = 0;
  bool completed = false;
public:
  bool isCompleted() override {
    return this->completed;
  }

  int getResult() override {
    return this->result;
  }
};

class DivisionOperation : public BaseOperation {
  int firstOperand = 0;
  bool hasFirstOperand = false;
public:
  void addOperand(int operand) override {
    if (hasFirstOperand) {
      this->result = firstOperand / operand;
      this->completed = true;
    } else {
      this->firstOperand = operand;
      this->hasFirstOperand = true;
    }
  }
};

class SaveOperation : public BaseOperation {
  Memory& memory;
public:
  SaveOperation(Memory& memory) : memory(memory) { }

  void addOperand(int operand) override {
    this->result = operand;
    this->completed = true;
    this->memory.emplace(operand);
  }
};

class RecallOperation : public BaseOperation {
public:
  RecallOperation(Memory& memory) {
    this->result = memory.top();
    memory.pop();
    this->completed = true;
  }

  void addOperand(int operand) override { }
};

class ExtendedInputInterpreter : public InputInterpreter {
private:
  Memory memory{ };
public:
  ExtendedInputInterpreter(CalculationEngine& engine) : InputInterpreter(engine) { }

  std::shared_ptr<Operation> getOperation(std::string operation) override {
    if (operation == "/") {
      return std::make_shared<DivisionOperation>();
    } else if (operation == "ms") {
      return std::make_shared<SaveOperation>(this->memory);
    } else if (operation == "mr") {
      return std::make_shared<RecallOperation>(this->memory);
    }

    return InputInterpreter::getOperation(operation);
  }

};

std::shared_ptr<InputInterpreter> buildInterpreter(CalculationEngine& engine) {
  return std::make_shared<ExtendedInputInterpreter>(engine);
}

#endif //CPP_ADVANCED_EXTENSIONS_H
