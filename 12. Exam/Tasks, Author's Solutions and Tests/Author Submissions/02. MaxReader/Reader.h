#ifndef READER_H
#define READER_H

#include <istream>
#include <vector>
#include <string>
#include <sstream>

class Reader {
	std::istream& in;
public:
	Reader(std::istream& in) : in(in) {}

	Reader& operator>>(std::vector<int>& v) {
		std::string line;
		std::getline(in, line);

		std::istringstream lineIn(line);

		v.clear();

		int element;
		while (lineIn >> element) {
			v.push_back(element);
		}

		return *this;
	}
};

#endif // !READER_H

