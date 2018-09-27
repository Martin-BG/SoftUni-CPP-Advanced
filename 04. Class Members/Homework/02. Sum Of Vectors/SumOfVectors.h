#ifndef CPP_ADVANCED_SUMOFVECTORS_H
#define CPP_ADVANCED_SUMOFVECTORS_H

#include <vector>
#include <string>

typedef std::vector<std::string> vectorOfStrings;

vectorOfStrings operator+(const vectorOfStrings& v1, const vectorOfStrings& v2) {
  vectorOfStrings result;
  for (size_t i = 0; i < v1.size() && i < v2.size(); ++i) {
    result.push_back(v1.at(i) + " " + v2.at(i));
  }
  return result;
}

#endif //CPP_ADVANCED_SUMOFVECTORS_H
