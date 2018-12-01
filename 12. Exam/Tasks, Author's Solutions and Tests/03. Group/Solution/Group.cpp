#include "Group.h"

#include <algorithm>

const int Group::MAX_UNITS = 12;

Group::Group() : units(new UnitPtr[MAX_UNITS]{}), unitsAdded(0) {}

Group::Group(const Group& other) : units(new UnitPtr[MAX_UNITS]{}), unitsAdded(0) {
	for (int i = 0; i < MAX_UNITS && i < other.unitsAdded; i++) {
		this->add(other.units[i]);
	}
}

void Group::add(UnitPtr unit) {
	for (int i = 0; i < MAX_UNITS && i < this->unitsAdded; i++) {
		if (this->units[i]->getId() == unit->getId()) {
			return;
		}
	}

	this->units[this->unitsAdded % MAX_UNITS] = unit;
	this->unitsAdded++;
}

void Group::clear() {
	this->unitsAdded = 0;
}

Group& Group::operator=(const Group& other) {
	if (this != &other) {
		UnitPtr* unitsCopy = new UnitPtr[MAX_UNITS]{};

		for (int i = 0; i < MAX_UNITS; i++) {
			unitsCopy[i] = other.units[i];
		}

		delete[] this->units;
		this->unitsAdded = other.unitsAdded;
		this->units = unitsCopy;
	}

	return *this;
}

Group& Group::operator<<(const Group& other) {
	for (int i = 0; i < MAX_UNITS && i < other.unitsAdded; i++) {
		this->add(other.units[i]);
	}

	return *this;
}

Group::~Group() {
	delete[] this->units;
	this->units = nullptr;
}

std::ostream& operator<<(std::ostream& out, const Group& group) {
	std::vector<UnitPtr> sorted;
	for (int i = 0; i < Group::MAX_UNITS && i < group.unitsAdded; i++) {
		sorted.push_back(group.units[i]);
	}

	std::sort(sorted.begin(), sorted.end(), [](const UnitPtr& a, const UnitPtr& b) {
		return a->getId() < b->getId();
	});

	for (auto u : sorted) {
		out << *u << " ";
	}

	return out;
}