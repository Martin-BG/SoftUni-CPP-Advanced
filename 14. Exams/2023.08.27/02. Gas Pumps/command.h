#ifndef __COMMAND_H__
#define __COMMAND_H__

#include <memory>
#include <iostream>
#include <iomanip>

#include "defines.h"

class Command {

    protected:
        explicit Command(std::istream &) {}

        std::ostream & outputTicks(std::ostream & ostr) {
            ostr << "Hour " << std::setfill('0') << std::setw(4)
            << GasReservoir::get().getCycles();
            return ostr;
        }

    public:
        Command() = delete;

        static std::unique_ptr<Command> CommandFactory(std::istream & istr);

        virtual void process() = 0;

        virtual ~Command() = default;
};

#endif