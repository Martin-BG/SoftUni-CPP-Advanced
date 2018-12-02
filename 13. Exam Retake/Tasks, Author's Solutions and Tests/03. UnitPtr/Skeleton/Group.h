#ifndef GROUP_H
#define GROUP_H

#include <vector>
#include <ostream>

#include "Unit.h"
#include "UnitPtr.h"

class Group {
	int groupId;
	UnitPtr* units;
	unsigned int unitsAdded;

public:
	static const int MAX_UNITS;
public:
	Group();

	Group(const Group& other);

	void add(UnitPtr unit);

	void clear();

	Group& operator=(const Group& other);

	Group& operator<<(const Group& other);

	~Group();

	friend std::ostream& operator<<(std::ostream& out, const Group& group);
};

#endif // !GROUP_H