#ifndef CPP_ADVANCED_OPERATORS_H
#define CPP_ADVANCED_OPERATORS_H

#include <ostream>
#include <vector>
#include <string>
#include <sstream>

typedef std::vector<std::string> vectorOfStrings;

vectorOfStrings& operator<<(vectorOfStrings& vector, const std::string& str) {
  vector.push_back(str);
  return vector;
}

std::ostream& operator<<(std::ostream& out, const vectorOfStrings& vector) {
  for (const auto& line : vector) {
    out << line << std::endl;
  }
  return out;
}

std::string operator+(const std::string& str, const int& num) {
  std::ostringstream os;
  os << str << num;
  return os.str();
}

#endif //CPP_ADVANCED_OPERATORS_H
