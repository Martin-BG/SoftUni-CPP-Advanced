#ifndef CPP_ADVANCED_FIND_H
#define CPP_ADVANCED_FIND_H

#include "Company.h"
#include <vector>

Company* find(const std::vector<Company*>& companies, const int& searchId)
{
  for (auto company : companies) {
    if (company->getId() == searchId) {
      return company;
    }
  }
  return nullptr;
}

#endif //CPP_ADVANCED_FIND_H
