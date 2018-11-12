#ifndef CPP_ADVANCED_INITIALIZATION_H
#define CPP_ADVANCED_INITIALIZATION_H

#include "AdvancedCommandInterface.h"

std::shared_ptr<CommandInterface> buildCommandInterface(std::string& text) {
  return std::make_shared<AdvancedCommandInterface>(text);
}

#endif //CPP_ADVANCED_INITIALIZATION_H
