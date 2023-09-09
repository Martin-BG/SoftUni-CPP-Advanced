#include <iostream>
#include <string>
#include <memory.h>


#include "command.h"
#include "commands.h"

#include "defines.h"

using namespace std;

unique_ptr<Command> Command::CommandFactory(istream & istr) {

    string str;
    istr >> str;

    switch(str2command(str)) {
        case Commands::INIT:
            return make_unique<InitCommand>(istr); 
        case Commands::IN:
            return make_unique<InCommand>(istr); 
        case Commands::OUT:
            return make_unique<OutCommand>(istr); 
        case Commands::DEMAND:
            return make_unique<DemandCommand>(istr); 
        case Commands::END:
            break;
    };

    return make_unique<EndCommand>(istr);
}
