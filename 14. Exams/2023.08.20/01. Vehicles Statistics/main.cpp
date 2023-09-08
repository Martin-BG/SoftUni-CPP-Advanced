#include "classes.h"

#include <vector>
#include <map>

// friend
ostream & operator << (ostream & ostr, Vehicle & veh)
{
    veh.printInfo(ostr);
    return ostr;
}

//static
Vehicle * Vehicle::factory(const string & numberPlate, const string & size, const string & color) {

    Vehicle* vehicle = nullptr;

    if (size == "S") vehicle = new TwoWheeler(numberPlate, color);
    else if (size == "M") vehicle = new CarM(numberPlate, color);
    else if (size == "L") vehicle = new CarL(numberPlate, color);
    else if (size == "XL") vehicle = new TruckXL(numberPlate, color);
    else if (size == "XXL") vehicle = new TruckXXL(numberPlate, color);

    return vehicle;
}

int main() {

    vector<Vehicle*> vehicles;
    map<string, vector<Vehicle*>> vehiclesBySize;
    map<string, vector<Vehicle*>> vehiclesByColor;

    string numberPlate, color, size;

    // Reading input
    while (true) {
        cin >> numberPlate;

        if (numberPlate == "end")
            break;
        
        cin >> color >> size;

        Vehicle* vehicle = Vehicle::factory(numberPlate, size, color);

        if (vehicle) {
            vehicles.push_back(vehicle);
            vehiclesBySize[size].push_back(vehicle);
            vehiclesByColor[color].push_back(vehicle);
        }
    }

    // Printing statistics
    cout << "Vehicles by size:" << endl;
    for (const auto &entry : vehiclesBySize) {
        cout << entry.first << ":" << endl;
        for (Vehicle* vehicle : entry.second) {
            cout << "- " << *vehicle << endl;
        }
    }

    cout << "\nVehicles by color:" << endl;
    for (const auto &entry : vehiclesByColor) {
        cout << entry.first << ":" << endl;
        for (Vehicle* vehicle : entry.second) {
            cout << "- " << *vehicle << endl;
        }
    }

    // Cleaning up
    for (Vehicle* vehicle : vehicles)
        delete vehicle;

    return 0;
}
