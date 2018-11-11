#ifndef CPP_ADVANCED_QUOTESEXTRACTOR_H
#define CPP_ADVANCED_QUOTESEXTRACTOR_H

#include "BufferedExtractor.h"

class QuotesExtractor : public BufferedExtractor {
private:
  bool isStarted = false;
protected:
  bool shouldBuffer(char symbol) override {
    if (symbol == '"') {
      isStarted = !isStarted;
      return false;
    }
    return isStarted;
  }

public:
  QuotesExtractor(std::istream& stream) : BufferedExtractor(stream) { }
};

#endif //CPP_ADVANCED_QUOTESEXTRACTOR_H
