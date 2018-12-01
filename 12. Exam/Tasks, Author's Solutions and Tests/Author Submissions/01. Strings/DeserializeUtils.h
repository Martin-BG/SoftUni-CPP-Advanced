#ifndef DESERIALIZE_UTILS_H
#define DESERIALIZE_UTILS_H

#include <vector>
#include <string>

std::vector<std::string> deserializeStrings(char* serialized) {
	std::vector<std::string> strings;
	
	int numStrings = serialized[0];
	int position = 1;
	for (int i = 0; i < numStrings; i++) {
		int size = serialized[position++];

		std::string s(serialized + position, serialized + position + size);
		strings.push_back(s);

		position += size;
	}

	return strings;
}

#endif // !DESERIALIZE_UTILS_H
