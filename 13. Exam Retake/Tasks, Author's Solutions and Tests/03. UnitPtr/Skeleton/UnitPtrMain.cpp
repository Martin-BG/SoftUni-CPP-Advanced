#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <istream>
#include <map>

#include "Unit.h"
#include "Group.h"

#include "UnitPtr.h"

std::string readInput() {
	std::ostringstream input;

	std::string line;
	while (std::getline(std::cin, line) && line != "end") {
		input << line << std::endl;
	}

	return input.str();
}

void runTest(std::istream& in, std::ostream& out) {
	const int numGroups = ('9' - '0') + 1;
	Group groups[numGroups]{};
	std::map<Id, UnitPtr> units;

	std::string command;
	Group selection;
	while (in >> command) {
		if (command == "unit") {
			UnitPtr unit = UnitPtr::from(new Unit());
			in >> *unit;
			units[unit->getId()] = unit;
		}
		else if (command == "select") {
			Id unitId;
			in >> unitId;
			selection.clear();
			selection.add(units[unitId]);
		}
		else if (command == "shift-select") {
			Id unitId;
			while (in >> unitId && unitId != '.') {
				selection.add(units[unitId]);
			}
		}
		else if (command == "ctrl") {
			int groupId;
			in >> groupId;
			groups[groupId] = selection;
		}
		else if (command == "shift") {
			int groupId;
			in >> groupId;
			groups[groupId] << selection;
		}
	}

	for (int i = 0; i < numGroups; i++) {
		out << i << ": " << groups[i] << std::endl;
	}
}

int main() {
	std::cin.sync_with_stdio(false);
	std::cout.sync_with_stdio(false);

	std::vector<Unit*> units;

	int numTests;
	std::cin >> numTests;
	std::cin.ignore();

	std::string input = readInput();

	std::string firstRunResult;
	std::string lastRunResult;
	for (int i = 0; i < numTests; i++) {
		std::istringstream in(input);

		std::ostringstream out;
		runTest(in, out);

		if (i == 0) {
			firstRunResult = out.str();
		}
		if (i == numTests - 1) {
			lastRunResult = out.str();
		}
	}

	if (firstRunResult != lastRunResult) {
		std::cout << "first and last run different: " << std::endl;
		std::cout << firstRunResult; 
		std::cout << std::endl << "---" << std::endl;
		std::cout << lastRunResult;
	}
	else {
		std::cout << firstRunResult;
	}

	return 0;
}