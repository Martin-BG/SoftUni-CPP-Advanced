#ifndef CPP_ADVANCED_INITIALIZATION_H
#define CPP_ADVANCED_INITIALIZATION_H

#include <utility>
#include "CommandInterface.h"

class ExpandedCommandInterface : public CommandInterface {
private:
  class CutText : public TextTransform {
  private:
    std::string clipboard{ };
  public:
    void invokeOn(std::string& text, int startIndex, int endIndex) override {
      auto length = static_cast<size_t>(endIndex - startIndex);
      this->clipboard = text.substr(static_cast<size_t>(startIndex), length);
      text.erase(static_cast<size_t>(startIndex), length);
    }

    std::string getClipboard() const {
      return this->clipboard;
    }
  };

  class PasteText : public TextTransform {
  private:
    std::shared_ptr<CutText> cutPtr;
  public:
    PasteText(std::shared_ptr<CutText> cutPtr) : cutPtr(std::move(cutPtr)) { };

    void invokeOn(std::string& text, int startIndex, int endIndex) override {
      auto length = static_cast<size_t>(endIndex - startIndex);
      text.replace(static_cast<size_t>(startIndex), length, this->cutPtr->getClipboard());
    }
  };

protected:
  std::vector<Command> initCommands() override {
    std::vector<Command> commands = CommandInterface::initCommands();
    const std::shared_ptr<CutText>& cutPtr = std::make_shared<CutText>();
    commands.emplace_back("cut", cutPtr);
    commands.emplace_back("paste", std::make_shared<PasteText>(cutPtr));
    return commands;
  }

public:
  ExpandedCommandInterface(std::string& text) : CommandInterface(text) { this->init(); };
};

std::shared_ptr<CommandInterface> buildCommandInterface(std::string& text) {
  return std::make_shared<ExpandedCommandInterface>(text);
}

#endif //CPP_ADVANCED_INITIALIZATION_H
