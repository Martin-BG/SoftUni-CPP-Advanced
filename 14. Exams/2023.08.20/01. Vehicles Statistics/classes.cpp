#include "classes.h"


void Vehicle::printInfo(ostream &output) {
    output << numberPlate << ", " << color << ' ';

    if (auto twoWheeler = dynamic_cast<TwoWheeler *>(this); twoWheeler != nullptr) {
        twoWheeler->printInfo(output);
    } else if (auto carM = dynamic_cast<CarM *>(this); carM != nullptr) {
        carM->printInfo(output);
    } else if (auto carL = dynamic_cast<CarL *>(this); carL != nullptr) {
        carL->printInfo(output);
    } else if (auto truckXL = dynamic_cast<TruckXL *>(this); truckXL != nullptr) {
        truckXL->printInfo(output);
    } else if (auto truckXXL = dynamic_cast<TruckXXL *>(this); truckXXL != nullptr) {
        truckXXL->printInfo(output);
    }

    output << '.';
}

void TwoWheeler::printInfo(ostream &output) {
    output << "with 2 wheels";
}

void CarM::printInfo(ostream &output) {
    output << "medium car";
}

void CarL::printInfo(ostream &output) {
    output << "bigger car";
}

void TruckXL::printInfo(ostream &output) {
    output << "truck";
}

void TruckXXL::printInfo(ostream &output) {
    output << "big truck";
}