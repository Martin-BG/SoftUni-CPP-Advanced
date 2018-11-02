#ifndef CPP_ADVANCED_FILTERFACTORY_H
#define CPP_ADVANCED_FILTERFACTORY_H

#include <string>
#include "Filter.h"

class CapitalLetterFilter : public Filter {
protected:
  bool shouldFilterOut(char symbol) const override {
    return std::isupper(symbol);
  }
};

class SmallLetterFilter : public Filter {
protected:
  bool shouldFilterOut(char symbol) const override {
    return std::islower(symbol);
  }
};

class DigitFilter : public Filter {
protected:
  bool shouldFilterOut(char symbol) const override {
    return std::isdigit(symbol);
  }
};

class FilterFactory {
public:
  Filter* buildFilter(const std::string& filterDefinition) const {
    if (filterDefinition == "A-Z") {
      return new CapitalLetterFilter();
    } else if (filterDefinition == "a-z") {
      return new SmallLetterFilter();
    } else if (filterDefinition == "0-9") {
      return new DigitFilter();
    }

    return nullptr;
  }
};

#endif //CPP_ADVANCED_FILTERFACTORY_H
