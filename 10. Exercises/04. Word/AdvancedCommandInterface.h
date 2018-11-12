#ifndef CPP_ADVANCED_ADVANCEDCOMMANDINTERFACE_H
#define CPP_ADVANCED_ADVANCEDCOMMANDINTERFACE_H

#include "CommandInterface.h"

class AdvancedCommandInterface : public CommandInterface {
private:
  std::string memory;

  class CutTransform : public TextTransform {
  private:
    std::string& memory;
  public:
    CutTransform(std::string& memory) : memory(memory) { };

    void invokeOn(std::string& text, int startIndex, int endIndex) override {
      auto length = static_cast<size_t>(endIndex - startIndex);
      this->memory = text.substr(static_cast<size_t>(startIndex), length);
      text.erase(static_cast<size_t>(startIndex), length);
    }
  };

  class PasteTransform : public TextTransform {
  private:
    std::string& memory;
  public:
    PasteTransform(std::string& memory) : memory(memory) { };

    void invokeOn(std::string& text, int startIndex, int endIndex) override {
      auto length = static_cast<size_t>(endIndex - startIndex);
      text.replace(static_cast<size_t>(startIndex), length, this->memory);
    }
  };

public:
  std::vector<Command> initCommands() override {
    std::vector<Command> commands = CommandInterface::initCommands();

    commands.emplace_back("cut", std::make_shared<CutTransform>(this->memory));
    commands.emplace_back("paste", std::make_shared<PasteTransform>(this->memory));

    return commands;
  }

public:
  AdvancedCommandInterface(std::string& text) : CommandInterface(text) {
    this->init();
  }
};

#endif //CPP_ADVANCED_ADVANCEDCOMMANDINTERFACE_H
