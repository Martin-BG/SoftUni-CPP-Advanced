#include "Group.h"
#include <sstream>
#include <set>
#include <iostream>

const int Group::MAX_UNITS = 12;

Group::Group() : units(new UnitPtr[Group::MAX_UNITS]), unitsAdded(0) { };

Group::Group(const Group& other) : Group() {
  for (unsigned int i = 0; i < other.unitsAdded; ++i) {
    this->units[i] = new Unit();
    std::ostringstream os;
    os << other.units[i];
    std::istringstream is(os.str());
    is >> *this->units[i];
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
    delete this->units[0];
    index = 0;
  } else {
    this->unitsAdded++;
  }

  this->units[index] = new Unit();
  std::ostringstream os;
  os << unit->getId();
  std::istringstream is(os.str());
  is >> *this->units[index];
//  this->units[index] = unit;
}

void Group::clear() {
  for (unsigned int i = 0; i < this->unitsAdded; ++i) {
    delete this->units[i];
  }
  this->unitsAdded = 0;
}

Group& Group::operator=(const Group& other) {
  if (this != &other) {
    this->clear();
    this->unitsAdded = other.unitsAdded;

    for (unsigned int i = 0; i < other.unitsAdded; ++i) {
      this->units[i] = new Unit();
      std::ostringstream os;
      os << other.units[i]->getId();
      std::istringstream is(os.str());
      is >> *this->units[i];
    }
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
  this->clear();
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

