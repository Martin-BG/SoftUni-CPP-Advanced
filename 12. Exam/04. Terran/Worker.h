#ifndef CPP_ADVANCED_WORKER_H
#define CPP_ADVANCED_WORKER_H

#include <iostream>

#include "TimedBuilder.h"
#include "Depot.h"
#include "Barracks.h"

class Worker : public TimedBuilder {
public:

  explicit Worker(Id id) : TimedBuilder(id, "worker") { }

  void handleCommand(const std::vector<std::string>& commandParts) override {
    if (isConstructing() || commandParts[0] == "report") {
      std::cout << "worker " << this->getId() << (isConstructing() ? " busy" : " free") << std::endl;
    } else if (commandParts[1] == "depot") {
      startBuilding(new Depot(), Depot::BUILD_TIME);
    } else if (commandParts[1] == "barracks") {
      Id id = parseId(commandParts[2]);
      startBuilding(new Barracks(id), Barracks::BUILD_TIME);
    }
  }
};

#endif //CPP_ADVANCED_WORKER_H
