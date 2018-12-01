#ifndef CPP_ADVANCED_BARRACKS_H
#define CPP_ADVANCED_BARRACKS_H

#include <queue>

#include "Marine.h"
#include "TimedBuilder.h"

class Barracks : public TimedBuilder {
  static const int MAX_QUEUE_SIZE = 5;
  std::queue<Id> buildQueue{ };
public:
  static const int BUILD_TIME = 50;

  explicit Barracks(Id id) : TimedBuilder(id, "barracks") { }

  void handleCommand(const std::vector<std::string>& commandParts) override {
    if (this->buildQueue.size() <= MAX_QUEUE_SIZE && commandParts[0] == "train" && commandParts[1] == "marine") {
      const Id id{ commandParts[2][0] };
      this->buildQueue.emplace(id);
      if (!TimedBuilder::isConstructing()) {
        startBuilding(new Marine(id), Marine::BUILD_TIME);
      }
    }
  }

  void handleConstructionCompleted() override {
    this->buildQueue.pop();
    this->buildTimeRemaining = 0;
    this->currentConstruction = nullptr;
    if (!this->buildQueue.empty()) {
      startBuilding(new Marine(this->buildQueue.front()), Marine::BUILD_TIME);
    }
  }
};

#endif //CPP_ADVANCED_BARRACKS_H
