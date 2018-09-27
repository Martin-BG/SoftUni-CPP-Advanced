#ifndef CPP_ADVANCED_CAR_H
#define CPP_ADVANCED_CAR_H

#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Car {

  const string brand;
  const string model;
  const int year;

public:
  Car(string brand, string model, int year) :
      brand(std::move(brand)),
      model(std::move(model)),
      year(year) { }

  const string& GetBrand() const {
    return this->brand;
  }

  const string& GetModel() const {
    return this->model;
  }

  int GetYear() const {
    return this->year;
  }
};

#endif //CPP_ADVANCED_CAR_H
