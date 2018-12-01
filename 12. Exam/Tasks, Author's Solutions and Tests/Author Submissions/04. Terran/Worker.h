#ifndef WORKER_H
#define WORKER_H

#include "ControllableUnit.h"
#include "TimedBuilder.h"

#include "Depot.h"
#include "Barracks.h"

#include <iostream>

class Worker : public TimedBuilder {
public:
	Worker(Id id) : TimedBuilder(id, "worker") {}

	void handleCommand(const std::vector<std::string>& commandParts) override {
		if (commandParts[0] == "report") {
			this->report();
		}
		else if (commandParts[0] == "build") {
			if (this->isConstructing()) {
				this->report();
			}
			else {
				if (commandParts[1] == "depot") {
					this->startBuilding(new Depot(), 25);
				}
				else if (commandParts[1] == "barracks") {
					this->startBuilding(new Barracks(parseId(commandParts[2])), 50);
				}
			}
		}
	}

	void report() const {
		std::cout << "worker " << this->getId() << " " << (this->isConstructing() ? "busy" : "free") << std::endl;
	}
};

#endif // !WORKER_H

