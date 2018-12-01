#ifndef WORKER_H
#define WORKER_H

#include <iostream>
#include <string>

#include "Unit.h"
#include "ControllableUnit.h"
#include "TimedBuilder.h"

#include "Barracks.h"
#include "Depot.h"

class Worker : public TimedBuilder {
public:
	Worker(Id id) : TimedBuilder(id, "worker") {}

	void handleCommand(const std::vector<std::string>& commandParts) override {
		if (commandParts[0] == "build") {
			if (!this->isConstructing()) {
				if (commandParts[1] == "barracks") {
					this->startBuilding(new Barracks(parseId(commandParts[2])), Barracks::BUILD_TIME);
				}
				else if (commandParts[1] == "depot") {
					this->startBuilding(new Depot(), Depot::BUILD_TIME);
				}
			}
			else {
				this->reportState();
			}
		}
		else if (commandParts[0] == "report") {
			this->reportState();
		}
	}

	void reportState() {
		std::cout << "worker " << this->getId() << " " << (this->isConstructing() ? "busy" : "free") << std::endl;
	}
};

#endif // !WORKER_H