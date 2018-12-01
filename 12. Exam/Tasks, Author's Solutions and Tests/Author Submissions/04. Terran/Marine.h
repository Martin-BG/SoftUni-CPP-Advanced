#ifndef MARINE_H
#define MARINE_H

#include "ControllableUnit.h"

#include <iostream>

class Marine : public ControllableUnit {
public:
	Marine(Id id) : ControllableUnit(id, "marine") {}

	void handleCommand(const std::vector<std::string>& commandParts) override {
		if (commandParts[0] == "report") {
			std::cout << "marine " << this->getId() << " reporting" << std::endl;
		}
	}
};

#endif // !MARINE_H

