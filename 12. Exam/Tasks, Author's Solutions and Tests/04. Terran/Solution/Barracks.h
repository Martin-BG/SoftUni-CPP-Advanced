#ifndef BARRACKS_H
#define BARRACKS_H

#include <vector>
#include <queue>

#include "TimedBuilder.h"
#include "Marine.h"

class Barracks : public TimedBuilder {
protected:
	void handleConstructionCompleted() override {
		TimedBuilder::handleConstructionCompleted();

		if (!this->buildQueue.empty()) {
			this->startMarine(buildQueue.front());
			this->buildQueue.pop();
		}
	}

	bool startMarine(Id id) {
		return this->startBuilding(new Marine(id), Marine::BUILD_TIME);
	}

	std::queue<Id> buildQueue;
public:
	static const int BUILD_TIME = 50;

	Barracks(Id id) : TimedBuilder(id, "barracks") {}

	void handleCommand(const std::vector<std::string>& commandParts) override {
		if (commandParts[0] == "train" && commandParts[1] == "marine") {
			Id marineId = parseId(commandParts[2]);
			if (!this->isConstructing()) {
				this->startMarine(marineId);
			} else if (this->buildQueue.size() < 5) {
				this->buildQueue.push(marineId);
			}
		}
	}
};

#endif // !BARACKS_H

