#include <iostream>
#include <string>
#include <sstream>

#include "Structs.h"
#include "Statistics.h"

int main()
{
	int commands = 0;
	std::string input;
	std::istringstream istr;

	PersonInfo maleData;
	PersonInfo femaleData;

	Statistics statistics;

	std::cin >> commands;
	std::cin.ignore();

	for(int i = 0; i < commands; ++i)
	{
		getline(std::cin, input);

		istr.clear();
		istr.str(input);

		istr >> maleData.firstName >> maleData.lastName
		     >> maleData.age       >> maleData.height;

        istr >> femaleData.firstName >> femaleData.lastName
             >> femaleData.age       >> femaleData.height;

        statistics << maleData << femaleData;
	}

	statistics.printStatistics();

	return 0;
}

