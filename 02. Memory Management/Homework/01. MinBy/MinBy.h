#ifndef CPP_ADVANCED_MINBY_H
#define CPP_ADVANCED_MINBY_H

#include <string>
#include <vector>
#include <algorithm>

typedef bool(* comparator)(const std::string&, const std::string&);

std::string minBy(std::vector<std::string>& input, const comparator comp) {
  std::sort(input.begin(), input.end(), comp);
  return input.at(0);
}

#endif //CPP_ADVANCED_MINBY_H
