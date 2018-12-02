#include <iostream>

#include <string>

#include "StreamInputIterator.h"

std::string endString;

class Input {
	std::istream& in;
	std::string endString;
public:
	Input(std::istream& in, std::string endString) : in(in), endString(endString) {}

	StreamInputIterator begin() {
		return StreamInputIterator::begin(in);
	}

	StreamInputIterator end() {
		return StreamInputIterator::end(in, endString);
	}
};

int main() {
	std::cin >> endString;

	int sum = 0;
	for (auto i : Input(std::cin, endString)) {
		sum += i;
	}

	std::cout << sum << std::endl;

	return 0;
}