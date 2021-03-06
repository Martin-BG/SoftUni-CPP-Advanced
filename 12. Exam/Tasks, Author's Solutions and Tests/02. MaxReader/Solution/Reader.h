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
		std::getline(this->in, line);

		std::istringstream lineIn(line);

		int value;
		while (lineIn >> value) {
			v.push_back(value);
		}

		return *this;
	}
};

#endif // !READER_H

