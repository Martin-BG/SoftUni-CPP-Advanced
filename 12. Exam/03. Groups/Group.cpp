#include "Group.h"
#include <sstream>
#include <set>
#include <iostream>

const int Group::MAX_UNITS = 12;

Group::Group() : units(new UnitPtr[Group::MAX_UNITS]), unitsAdded(0) { };

Group::Group(const Group& other) : Group() {
  for (unsigned int i = 0; i < other.unitsAdded; ++i) {
    this->units[i] = other.units[i];
  }

  this->unitsAdded = other.unitsAdded;
}

void Group::add(UnitPtr unit) {
  for (unsigned int i = 0; i < this->unitsAdded; ++i) {
    if (unit->getId() == this->units[i]->getId()) {
      return;
    }
  }

  int index = this->unitsAdded;

  if (index == Group::MAX_UNITS) {
    index = 0;
  } else {
    this->unitsAdded++;
  }

  this->units[index] = unit;
}

void Group::clear() {
  this->unitsAdded = 0;
}

Group& Group::operator=(const Group& other) {
  if (this != &other) {
    auto unitsCopy = new UnitPtr[MAX_UNITS]{ };

    for (unsigned int i = 0; i < other.unitsAdded; i++) {
      unitsCopy[i] = other.units[i];
    }

    delete[] this->units;
    this->unitsAdded = other.unitsAdded;
    this->units = unitsCopy;
  }

  return *this;
}

Group& Group::operator<<(const Group& other) {
  for (unsigned int i = 0; i < other.unitsAdded; ++i) {
    this->add(other.units[i]);
  }
  return *this;
}

Group::~Group() {
  delete[] this->units;
}

std::ostream& operator<<(std::ostream& out, const Group& group) {
  std::set<Id> ids;

  for (unsigned int i = 0; i < group.unitsAdded; ++i) {
    ids.emplace(group.units[i]->getId());
  }

  for (auto const& id : ids) {
    out << id << ' ';
  }

  return out;
}
