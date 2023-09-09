#ifndef __COMMANDS_H__
#define __COMMANDS_H__

#include <iostream>

#include "command.h"

class EndCommand : public Command {

    public:

        EndCommand(std::istream & istr) : Command(istr) {} ;

        virtual void process(void) override; 

        virtual ~EndCommand() override {};
};

class InitCommand : public Command {

    int initQ;

    public:

        InitCommand(std::istream & istr);

        virtual void process(void) override;

        virtual ~InitCommand() override;
};

class TwoParametersCommand : public Command {
    private:
        int par1, par2;
    public:
        TwoParametersCommand(std::istream & istr) : Command(istr) {
            istr >> par1 >> par2;
        }

        int getPar1(void) const { return par1; }
        int getPar2(void) const { return par2; }
};

class InCommand : public TwoParametersCommand {

    public:

        InCommand(std::istream & istr);

        virtual void process(void) override;

        virtual ~InCommand() override;
};

class OutCommand : public TwoParametersCommand {

    public:

        OutCommand(std::istream & istr);

        virtual void process(void) override;

        virtual ~OutCommand() override;
};

class DemandCommand : public TwoParametersCommand {

    public:

        DemandCommand(std::istream & istr);

        virtual void process(void) override;

        virtual ~DemandCommand() override;
};

#endif