#include <iostream>
#include <vector>
#include <sstream>

#include "DeserializeUtils.h"

int main() {
	std::vector<char> values;
	std::string valuesLine;
	std::getline(std::cin, valuesLine);
	std::istringstream valuesLineIn(valuesLine);
	int value;
	while (valuesLineIn >> value) {
		values.push_back(value);
	}

	char* serialized = new char[values.size()];
	for (auto i = 0; i < values.size(); i++) {
		*(serialized + i) = values[i];
	}

	auto strings = deserializeStrings(serialized);

	for (auto s : strings) {
		std::cout << s << std::endl;
	}

	delete[] serialized;

	return 0;
}