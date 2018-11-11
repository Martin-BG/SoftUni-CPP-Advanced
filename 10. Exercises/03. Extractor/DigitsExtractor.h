#ifndef CPP_ADVANCED_DIGITSEXTRACTOR_H
#define CPP_ADVANCED_DIGITSEXTRACTOR_H

#include "Extractor.h"

class DigitsExtractor : public Extractor {
protected:
  bool process(char symbol, std::string& output) override {
    if (std::isdigit(symbol)) {
      output = symbol;
      return true;
    }
    return false;
  }

public:
  DigitsExtractor(std::istream& stream) : Extractor(stream) { }
};

#endif //CPP_ADVANCED_DIGITSEXTRACTOR_H
