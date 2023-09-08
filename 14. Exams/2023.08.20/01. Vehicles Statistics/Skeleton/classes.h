#ifndef __CLASSES_H_
#define __CLASSES_H_

#include <string>
#include <iostream>

using namespace std;

// Base class
class Vehicle {
protected:
    string numberPlate;
    string color;

    Vehicle(const string &np, const string &c) : numberPlate(np), color(c) {}

public:
    virtual ~Vehicle() {}

    virtual string getSize() const = 0; // Pure virtual function to ensure derived classes implement it

    static Vehicle * factory(const string & numberPlate, const string & size, const string & color);

    void printInfo(ostream & output);

    friend ostream & operator << (ostream & ostr, Vehicle &veh);
};

// Derived classes for each size
class TwoWheeler : public Vehicle {
public:
    TwoWheeler(const string &np, const string &c) : Vehicle(np, c) {}
    string getSize() const override { return "S"; }

    void printInfo(ostream & output);
};

class CarM : public Vehicle {
public:
    CarM(const string &np, const string &c) : Vehicle(np, c) {}
    string getSize() const override { return "M"; }

    void printInfo(ostream & output);
};

class CarL : public Vehicle {
public:
    CarL(const string &np, const string &c) : Vehicle(np, c) {}
    string getSize() const override { return "L"; }

    void printInfo(ostream & output);
};

class TruckXL : public Vehicle {
public:
    TruckXL(const string &np, const string &c) : Vehicle(np, c) {}
    string getSize() const override { return "XL"; }

    void printInfo(ostream & output);
};

class TruckXXL : public Vehicle {
public:
    TruckXXL(const string &np, const string &c) : Vehicle(np, c) {}
    string getSize() const override { return "XXL"; }

    void printInfo(ostream & output);
};




#endif