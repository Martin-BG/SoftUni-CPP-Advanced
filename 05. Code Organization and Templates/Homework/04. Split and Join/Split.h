#ifndef CPP_ADVANCED_SPLIT_H
#define CPP_ADVANCED_SPLIT_H

#include <vector>
#include <string>
#include <sstream>

template<typename T>
std::vector<T> split(const std::string& input, const char separator) {
  std::vector<T> result;
  std::string parsed;
  std::stringstream ss(input);
  while (std::getline(ss, parsed, separator)) {
    T element;
    std::istringstream is(parsed);
    is >> element;
    result.push_back(element);
  }
  return result;
};

#endif //CPP_ADVANCED_SPLIT_H
