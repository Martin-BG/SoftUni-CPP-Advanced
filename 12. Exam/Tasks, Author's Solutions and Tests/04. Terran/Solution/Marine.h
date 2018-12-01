#ifndef MARINE_H
#define MARINE_H

#include "ControllableUnit.h"

class Marine : public ControllableUnit {
public:
	static const int BUILD_TIME = 15;

	Marine(Id id) : ControllableUnit(id, "marine") {}

	void handleCommand(const std::vector<std::string>& commandParts) override {
		if (commandParts[0] == "report") {
			std::cout << "marine " << this->getId() << " reporting" << std::endl;
		}
	}
};

#endif // !MARINE_H

