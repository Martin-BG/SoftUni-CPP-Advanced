#include <utility>

#ifndef CPP_ADVANCED_CITYDIFF_H
#define CPP_ADVANCED_CITYDIFF_H

#include <utility>

#include "City.h"

class CityDiff {
  City a;
  City b;
public:
  CityDiff(City a, City b) : a(std::move(a)), b(std::move(b)) { }

  friend std::ostream& operator<<(std::ostream& out, const CityDiff& a);
};

std::ostream& operator<<(std::ostream& out, const CityDiff& diff) {
  if (diff.a.getName() == diff.b.getName()) {
    out << diff.a.getName() << " (" << diff.a.getCensusYear() << " vs. " << diff.b.getCensusYear() << ")";
  } else {
    out << diff.a.getName() << " (" << diff.a.getCensusYear() << ") vs. "
        << diff.b.getName() << " (" << diff.b.getCensusYear() << ")";
  }

  out << std::endl << "population: ";
  if (diff.a.getPopulation() >= diff.b.getPopulation()) {
    out << "+" << diff.a.getPopulation() - diff.b.getPopulation() << std::endl;
  } else {
    out << "-" << diff.b.getPopulation() - diff.a.getPopulation() << std::endl;
  }

  return out;
}

#endif //CPP_ADVANCED_CITYDIFF_H
