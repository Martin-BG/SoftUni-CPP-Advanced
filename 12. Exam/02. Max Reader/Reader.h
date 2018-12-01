#ifndef CPP_ADVANCED_READER_H
#define CPP_ADVANCED_READER_H

#include <sstream>
#include <vector>

class Reader {
  std::istream& in;
public:
  explicit Reader(std::istream& in) : in(in) { }

  std::vector<int>& operator>>(std::vector<int>& arr) {
    std::string line;
    std::getline(this->in >> std::ws, line);
    std::istringstream is(line);
    int next;
    while (is >> next) {
      arr.emplace_back(next);
    }
    return arr;
  }
};

#endif //CPP_ADVANCED_READER_H
