#ifndef CPP_ADVANCED_NUMBERSEXTRACTOR_H
#define CPP_ADVANCED_NUMBERSEXTRACTOR_H

#include "BufferedExtractor.h"

class NumbersExtractor : public BufferedExtractor {
protected:
  bool shouldBuffer(char symbol) override {
    return std::isdigit(symbol);
  }

public:
  NumbersExtractor(std::istream& stream) : BufferedExtractor(stream) { }
};

#endif //CPP_ADVANCED_NUMBERSEXTRACTOR_H
