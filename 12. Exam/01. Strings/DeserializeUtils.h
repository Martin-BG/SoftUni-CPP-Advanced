#ifndef CPP_ADVANCED_DESERIALIZEUTILS_H
#define CPP_ADVANCED_DESERIALIZEUTILS_H

#include <vector>
#include <string>

std::vector<std::string> deserializeStrings(char* serialized) {
  std::vector<std::string> words;

  size_t index = 0;
  auto wordsCount = static_cast<size_t>(serialized[index++]);

  while (wordsCount-- > 0) {
    auto wordLength = static_cast<size_t>(serialized[index++]);
    words.emplace_back(serialized + index, wordLength);
    index += wordLength;
  }

  return words;
}

/*#include <sstream>

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
}*/

#endif //CPP_ADVANCED_DESERIALIZEUTILS_H
