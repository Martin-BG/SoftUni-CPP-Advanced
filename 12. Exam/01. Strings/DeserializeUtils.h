#ifndef CPP_ADVANCED_DESERIALIZEUTILS_H
#define CPP_ADVANCED_DESERIALIZEUTILS_H

#include <string>
#include <sstream>

std::vector<std::string> deserializeStrings(char* serialized) {
  std::vector<std::string> words;
  int wordsRemaining = (int) serialized[0];
  std::stringstream ss;
  int index = 0;
  while (wordsRemaining > 0) {
    wordsRemaining--;
    int length = (int) serialized[++index];
    for (int i = 0; i < length; ++i) {
      ss << serialized[++index];
    }
    words.push_back(ss.str());
    ss.clear();
    ss.str("");
  }
  return words;
}

#endif //CPP_ADVANCED_DESERIALIZEUTILS_H
