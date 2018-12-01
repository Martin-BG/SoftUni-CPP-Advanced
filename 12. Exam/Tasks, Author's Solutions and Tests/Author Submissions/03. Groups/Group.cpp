#include "Group.h"
#include <map>

#define SIZE(g) ((g).unitsAdded > Group::MAX_UNITS ? Group::MAX_UNITS : (g).unitsAdded)

const int Group::MAX_UNITS = 12;

Group::Group() : units(new UnitPtr[MAX_UNITS]{}), unitsAdded(0) {}

Group::Group(const Group& other) : units(new UnitPtr[MAX_UNITS]{}), unitsAdded(other.unitsAdded) {
	for (int i = 0; i < SIZE(other); i++) {
		this->units[i] = other.units[i];
	}
}

void Group::add(UnitPtr unit) {
	for (int i = 0; i < SIZE(*this); i++) {
		if (this->units[i]->getId() == unit->getId()) {
			return;
		}
	}

	this->units[(this->unitsAdded++) % MAX_UNITS] = unit;
}

void Group::clear() {
	delete[] this->units;

	this->units = new UnitPtr[MAX_UNITS]{};
	this->unitsAdded = 0;
}

Group& Group::operator=(const Group& other) {
	if (this != &other) {
		Group copy(other);

		std::swap(this->units, copy.units);
		std::swap(this->unitsAdded, copy.unitsAdded);
	}

	return *this;
}

Group& Group::operator<<(const Group& other) {
	for (int i = other.unitsAdded <= MAX_UNITS ? 0 : (other.unitsAdded + 1); i < other.unitsAdded; i++) {
		this->add(other.units[i % MAX_UNITS]);
	}

	return *this;
}

Group::~Group() {
	delete[] this->units;
}

std::ostream& operator<<(std::ostream& out, const Group& group) {
	std::map<Id, UnitPtr> byId;

	for (int i = 0; i < SIZE(group); i++) {
		byId[group.units[i]->getId()] = group.units[i];
	}

	for (auto idAndUnit : byId) {
		out << *idAndUnit.second << " ";
	}

	return out;
}
