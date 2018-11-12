#ifndef CPP_ADVANCED_CITYUTILS_H
#define CPP_ADVANCED_CITYUTILS_H

#include <vector>
#include <map>

#include "City.h"

const City* initCity(const std::string& name, size_t population) {
  return new City(name, population);
}

std::map<size_t, const City*> groupByPopulation(const std::vector<const City*>& cities, size_t& totalPopulation) {
  totalPopulation = 0;
  std::map<size_t, const City*> sorted;
  for (auto const& city : cities) {
    sorted.emplace(city->getPopulation(), city);
    totalPopulation += city->getPopulation();
  }
  return sorted;
}

#endif //CPP_ADVANCED_CITYUTILS_H
