#ifndef DESERIALIZE_UTILS_H
#define DESERIALIZE_UTILS_H

#include <vector>
#include <string>

std::string deserialzeString(char* stringData, int& bytesRead) {
	int numChars = stringData[0];

	bytesRead = 1 + numChars;
	return std::string(stringData + 1, numChars);
}

std::vector<std::string> deserializeStrings(char* stringsData) {
	int numStrings = stringsData[0];
	std::vector<std::string> strings;
	char* currentStringStart = stringsData + 1;
	for (int i = 0; i < numStrings; i++) {
		int bytesRead = 0;
		strings.push_back(deserialzeString(currentStringStart, bytesRead));
		currentStringStart += bytesRead;
	}

	return strings;
}

#endif // !DESERIALIZE_UTILS_H