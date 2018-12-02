#ifndef CPP_ADVANCED_SERIALIZATIONUTILS_H
#define CPP_ADVANCED_SERIALIZATIONUTILS_H

#include <vector>
#include <string>

char* serializeStrings(const std::vector<std::string>& words, int& serializedSize) {
  std::vector<char> data{ };
  serializedSize = 0;
  for (const auto& word: words) {
    serializedSize += 1 + word.length();
    data.emplace_back(word.length());
    for (auto ch: word) {
      data.emplace_back(ch);
    }
  }

  char* serialized = new char[serializedSize];

  size_t index = 0;
  for (const auto& ch: data) {
    serialized[index++] = ch;
  }

  return serialized;
}

#endif //CPP_ADVANCED_SERIALIZATIONUTILS_H
