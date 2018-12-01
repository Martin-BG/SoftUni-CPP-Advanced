#ifndef TIMED_BUILDER_H
#define TIMED_BUILDER_H

#include "Producer.h"
#include "ControllableUnit.h"

class TimedBuilder : public ControllableUnit, public ProducerBase {
private:
	void construct() {
		this->buildTimeRemaining--;
		if (this->buildTimeRemaining <= 0) {
			this->produced.push_back(this->currentConstruction);

			this->handleConstructionCompleted();
		}
	}
protected:
	int buildTimeRemaining;
	UnitPtr currentConstruction;

	TimedBuilder(Id id, std::string type) : ControllableUnit(id, type), buildTimeRemaining(0), currentConstruction(nullptr) {}

	virtual void handleConstructionCompleted() {
		this->buildTimeRemaining = 0;
		this->currentConstruction = nullptr;
	}

	void update() override {
		ControllableUnit::update();
		if (this->isConstructing()) {
			this->construct();
		}
	}

	bool isConstructing() const {
		return this->buildTimeRemaining > 0;
	}

	bool startBuilding(UnitPtr p, int buildTime) {
		if (this->isConstructing()) {
			return false;
		}

		this->buildTimeRemaining = buildTime;
		this->currentConstruction = p;

		return true;
	}
};

#endif // !TIMED_BUILDER_H

