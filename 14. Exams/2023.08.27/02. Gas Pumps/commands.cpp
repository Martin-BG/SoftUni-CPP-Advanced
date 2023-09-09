#include "commands.h"

void EndCommand::process() {
    outputTicks(std::cout);
    std::cout << ": Final gas quantity: " << GasReservoir::get().getQuantity() << " kg3\n";
}

InitCommand::InitCommand(std::istream &istr) : Command(istr) {
    istr >> initQ;
}

void InitCommand::process() {
    GasReservoir::get().setQuantity(initQ);

    outputTicks(std::cout);
    std::cout << ": Gas quantity: " << GasReservoir::get().getQuantity() << " kg3\n";
}

InitCommand::~InitCommand() = default;

InCommand::InCommand(std::istream &istr) : TwoParametersCommand(istr) {}

void InCommand::process() {
    GasReservoir::get().setQuantity(GasReservoir::get().getQuantity() + getPar1() * getPar2());
    GasReservoir::get().addCycles(getPar2());

    outputTicks(std::cout);
    std::cout << ": Pumping in " << getPar1() << " kg3 for "
              << getPar2() << " hours, remaining " << GasReservoir::get().getQuantity() << " kg3\n";
}

InCommand::~InCommand() = default;

OutCommand::OutCommand(std::istream &istr) : TwoParametersCommand(istr) {

}

void OutCommand::process() {
    GasReservoir::get().addCycles(getPar2());
    outputTicks(std::cout);

    if (GasReservoir::get().getQuantity() == 0) {
        std::cout << ": Gas Storage Empty.\n";
        return;
    }

    int required = getPar1() * getPar2();
    if (GasReservoir::get().getQuantity() >= required) {
        GasReservoir::get().setQuantity(GasReservoir::get().getQuantity() - getPar1() * getPar2());

        std::cout << ": Delivering out " << getPar1() * getPar2() << " kg3, remaining "
                  << GasReservoir::get().getQuantity() << " kg3\n";
    } else {
        int delivered = GasReservoir::get().getQuantity();
        int shortage = required - delivered;
        GasReservoir::get().setQuantity(0);

        std::cout << ": Delivering out " << delivered << " kg3 (shortage " << shortage
                  << " kg3), remaining " << GasReservoir::get().getQuantity() << " kg3\n";
    }
}

OutCommand::~OutCommand() = default;

DemandCommand::DemandCommand(std::istream &istr) : TwoParametersCommand(istr) {

}

void DemandCommand::process() {
    outputTicks(std::cout);
    std::cout << ": CHECK: ";

    int required = getPar1() * getPar2();
    int available = GasReservoir::get().getQuantity();

    if (available <= 0) {
        std::cout << "Gas Storage Empty.\n";
    } else if (available >= required) {
        std::cout << "OK.\n";
    } else {
        int shortage = required - available;
        int maxOutputForTime = available / getPar2();
        std::cout << "Shortage of " << shortage << ": availability " << maxOutputForTime
                  << " for " << getPar2() << " hours\n";
    }
}

DemandCommand::~DemandCommand() = default;
