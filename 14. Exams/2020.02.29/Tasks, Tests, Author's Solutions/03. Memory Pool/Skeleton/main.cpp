#include <iostream>
#include <string>

#include "CommandExecutor.h"

int main()
{
	int commands = 0;
	int memoryPoolSize = 0;
	std::string input;

	std::cin >> commands >> memoryPoolSize;
	std::cin.ignore();

	CommandExecutor commandExecutor(memoryPoolSize);

	for(int i = 0; i < commands; ++i)
	{
		getline(std::cin, input);

		commandExecutor.extractCommand(input);
	}

	return 0;
}
