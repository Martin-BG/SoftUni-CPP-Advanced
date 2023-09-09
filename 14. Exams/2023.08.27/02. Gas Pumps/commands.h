#ifndef __COMMANDS_H__
#define __COMMANDS_H__

#include <iostream>

#include "command.h"

class EndCommand : public Command {

    public:

        explicit EndCommand(std::istream & istr) : Command(istr) {}

        void process() override;

        ~EndCommand() override = default;
};

class InitCommand : public Command {

    int initQ{};

    public:

        explicit InitCommand(std::istream & istr);

        void process() override;

        ~InitCommand() override;
};

class TwoParametersCommand : public Command {
    private:
        int par1{};
        int par2{};
    public:
        explicit TwoParametersCommand(std::istream & istr) : Command(istr) {
            istr >> par1 >> par2;
        }

        [[nodiscard]] int getPar1() const { return par1; }
        [[nodiscard]] int getPar2() const { return par2; }
};

class InCommand : public TwoParametersCommand {

    public:

        explicit InCommand(std::istream & istr);

        void process() override;

        ~InCommand() override;
};

class OutCommand : public TwoParametersCommand {

    public:

        explicit OutCommand(std::istream & istr);

        void process() override;

        ~OutCommand() override;
};

class DemandCommand : public TwoParametersCommand {

    public:

        explicit DemandCommand(std::istream & istr);

        void process() override;

        ~DemandCommand() override;
};

#endif