#ifndef CPP_ADVANCED_INCLUDES_H
#define CPP_ADVANCED_INCLUDES_H

#include <vector>
#include <iostream>

#include "City.h"
#include "CityDiff.h"

std::istream& operator>>(std::istream& in, City& city) {
  unsigned int censusYear;
  std::string name;
  size_t population;

  in >> name >> population >> censusYear;

  city = City(censusYear, name, population);

  return in;
}

CityDiff operator-(const City& a, const City& b) {
  return CityDiff(a, b);
}

#endif //CPP_ADVANCED_INCLUDES_H
