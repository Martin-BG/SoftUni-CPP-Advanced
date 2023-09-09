#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

#include "defines.h"
#include "command.h"
#include "commands.h"

using namespace std;

Commands str2command(const string & str) {

    if (str == "INIT")
        return Commands::INIT;
    else if (str == "GASIN")
        return Commands::IN;
    else if (str == "GASOUT")
        return Commands::OUT;
    else if (str == "DEMAND")
        return Commands::DEMAND;
    else 
        return Commands::END;
}

std::unique_ptr< GasReservoir > GasReservoir::theReservoir(nullptr);

GasReservoir & GasReservoir::get(void) { 
    if (theReservoir.get() == nullptr) {
        theReservoir = unique_ptr<GasReservoir>(new GasReservoir());
    }

    return *theReservoir.get();
}

int main() {

    vector< unique_ptr<Command> > cmd_list;

	string line;
	while (getline(cin, line)) {

        std::transform(line.begin(), line.end(), line.begin(), ::toupper);

		istringstream lineIn(line);
        cmd_list.push_back(Command::CommandFactory(lineIn));

        if (line == "END")
            break;
	}

    for(auto c = cmd_list.begin(); c!=cmd_list.end(); c++)
        (*c)->process();

    return 0;
}
