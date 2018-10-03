#ifndef CPP_ADVANCED_PARSER_H
#define CPP_ADVANCED_PARSER_H

#include <utility>
#include <string>
#include <sstream>

template<class T>
class Parser {
  std::istream& in;
  std::string stopLine;
public:
  Parser(std::istream& in, std::string& stopLine) : in(in), stopLine(std::move(stopLine)) { }

  bool readNext(T& element) {
    std::string line;
    if (std::getline(this->in, line) && line != this->stopLine) {
      std::istringstream is(line);
      is >> element;
      return true;
    }
    return false;
  }
};

#endif //CPP_ADVANCED_PARSER_H
