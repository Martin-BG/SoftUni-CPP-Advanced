#include <iostream>
#include <string>

#include "StringConcatenator.h"


int main()
{
	int strategyId = 0;
	std::string left;
	std::string right;

	std::cin >> strategyId;
	std::cin.ignore();

	getline(std::cin, left);
	getline(std::cin, right);

	StringConcatenator concatenator;

	const std::string result = concatenator.concatenate(
							      static_cast<ConcatenateStrategy>(strategyId),
								  left.data(),
								  left.size(),
								  right.data(),
								  right.size());

	std::cout << result << std::endl;

	return 0;
}
