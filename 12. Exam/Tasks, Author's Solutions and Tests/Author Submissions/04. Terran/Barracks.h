#ifndef BARRACKS_H
#define BARRACKS_H

#include <queue>

#include "TimedBuilder.h"

#include "Marine.h"

class Barracks : public TimedBuilder {
	std::queue<UnitPtr> buildQ;
public:
	Barracks(Id id) : TimedBuilder(id, "barracks") {}

	void handleCommand(const std::vector<std::string>& commandParts) override {
		if (commandParts[0] == "train" && commandParts[1] == "marine") {
			if (this->isConstructing()) {
				if (this->buildQ.size() < 5) {
					this->buildQ.push(new Marine(parseId(commandParts[2])));
				}
			}
			else {
				this->startBuilding(new Marine(parseId(commandParts[2])), 15);
			}
		}
	}

	void handleConstructionCompleted() override {
		TimedBuilder::handleConstructionCompleted();
		if (!this->buildQ.empty()) {
			this->startBuilding(this->buildQ.front(), 15);
			this->buildQ.pop();
		}
	}
};

#endif // !BARRACKS_H