#include "Unit.h"

Unit::Unit() {}

char Unit::getId() const {
	return this->id;
}

std::istream& operator>>(std::istream& in, Unit& u) {
	return in >> u.id;
}

std::ostream& operator<<(std::ostream& out, const Unit& u) {
	return out << u.id;
}