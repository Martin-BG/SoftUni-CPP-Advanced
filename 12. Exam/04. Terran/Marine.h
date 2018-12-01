#ifndef CPP_ADVANCED_MARINE_H
#define CPP_ADVANCED_MARINE_H

#include "ControllableUnit.h"
#include "Unit.h"
#include <iostream>

class Marine : public ControllableUnit {
public:
  static const int BUILD_TIME = 15;

  explicit Marine(Id id) : ControllableUnit(id, "marine") { }

  void handleCommand(const std::vector<std::string>& commandParts) override {
    if (commandParts[0] == "report") {
      std::cout << "marine " << this->getId() << " reporting" << std::endl;
    }
  }
};

#endif //CPP_ADVANCED_MARINE_H
