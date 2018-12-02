#ifndef SERIALIZATION_UTILS_H
#define SERIALIZATION_UTILS_H

#include <vector>
#include <string>

char* serializeStrings(const std::vector<std::string>& strings, int& resultSize) {
	resultSize = 0;

	std::vector<char> bytes;
	for (auto s : strings) {
		bytes.push_back(s.size());
		for (auto c : s) {
			bytes.push_back(c);
		}
	}

	resultSize = bytes.size();

	char* data = new char[resultSize];
	for (int i = 0; i < resultSize; i++) {
		data[i] = bytes[i];
	}

	return data;
}

#endif // !SERIALIZATION_UTILS_H

