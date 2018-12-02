#include <iostream>
#include <vector>
#include <string>

#include "SerializationUtils.h"

int main() {
	std::vector<std::string> lines;
	std::string line;
	while (std::getline(std::cin, line) && line != "---") {
		lines.push_back(line);
	}

	int serializedSize;
	char* serialized = serializeStrings(lines, serializedSize);

	for (int i = 0; i < serializedSize; i++) {
		std::cout << (int)serialized[i] << " ";
	}

	delete[] serialized;

	return 0;
}