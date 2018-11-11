#ifndef CPP_ADVANCED_EXTRACTORINITIALIZATION_H
#define CPP_ADVANCED_EXTRACTORINITIALIZATION_H

#include <memory>

#include "DigitsExtractor.h"
#include "NumbersExtractor.h"
#include "QuotesExtractor.h"

std::shared_ptr<Extractor> getExtractor(const std::string& extractType, std::istream& stream) {
  if (extractType == "digits") {
    return std::make_shared<DigitsExtractor>(stream);
  } else if (extractType == "numbers") {
    return std::make_shared<NumbersExtractor>(stream);
  } else if (extractType == "quotes") {
    return std::make_shared<QuotesExtractor>(stream);
  }

  return nullptr;
}

#endif //CPP_ADVANCED_EXTRACTORINITIALIZATION_H
