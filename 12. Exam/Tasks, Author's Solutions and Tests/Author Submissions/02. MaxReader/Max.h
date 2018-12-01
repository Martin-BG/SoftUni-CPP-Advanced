#ifndef MAX_H
#define MAX_H

#include <vector>

class VectorMax {
	std::vector<int> elements;
	int max;
public:
	bool operator<(const VectorMax& other) const {
		return this->max < other.max;
	}

	friend const std::vector<int>& operator>>(const std::vector<int>& v, VectorMax& m);
	friend std::ostream& operator<<(std::ostream& out, const VectorMax& m);
};

std::ostream& operator<<(std::ostream& out, const VectorMax& m) {
	for (auto e : m.elements) {
		out << e << " ";
	}

	return out;
}

const std::vector<int>& operator>>(const std::vector<int>& v, VectorMax& m) {
	m.max = v[0];
	m.elements = v;

	for (int i = 1; i < v.size(); i++) {
		if (v[i] > m.max) {
			m.max = v[i];
		}
	}

	return v;
}

#endif // !MAX_H