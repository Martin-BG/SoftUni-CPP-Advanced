#ifndef UNIT_H
#define UNIT_H

#include <string>
#include <istream>
#include <ostream>

typedef char Id;

class Unit {
private:
	Id id;
public:
	Unit();

	Id getId() const;

	friend std::istream& operator>>(std::istream&, Unit&);
	friend std::ostream& operator<<(std::ostream&, const Unit&);
};

#endif // !UNIT_H

