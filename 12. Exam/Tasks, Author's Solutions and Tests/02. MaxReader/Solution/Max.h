#ifndef MAX_H
#define MAX_H

#include <vector>
#include <ostream>

class VectorMax {
	int max;
	std::vector<int> items;
public:
	friend const std::vector<int>& operator>>(const std::vector<int>& v, VectorMax& max);
	friend std::ostream& operator<<(std::ostream& out, const VectorMax& max);

	bool operator<(const VectorMax& other) const {
		return this->max < other.max;
	}
};

std::ostream& operator<<(std::ostream& out, const VectorMax& max) {
	for (auto item : max.items) {
		out << item << " ";
	}
	return out;
}

const std::vector<int>& operator>>(const std::vector<int>& v, VectorMax& m) {
	m.items = v;
	m.max = v.at(0);
	for (auto item : v) {
		if (item > m.max) {
			m.max = item;
		}
	}

	return v;
}

#endif // !MAX_H

