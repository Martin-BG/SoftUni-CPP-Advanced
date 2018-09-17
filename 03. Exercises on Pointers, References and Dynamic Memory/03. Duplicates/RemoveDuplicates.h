#ifndef CPP_ADVANCED_REMOVEDUPLICATES_H
#define CPP_ADVANCED_REMOVEDUPLICATES_H

#include <list>
#include <set>
#include "Company.h"

void removeDuplicates(std::list<Company*>& companies) {
  std::set<Company*> uniquePtr;
  std::set<std::string> uniqueNames;

  auto it = companies.begin();
  while (it != companies.end()) {
    Company* company = *it;
    if (!uniquePtr.insert(company).second) {
      it = companies.erase(it);
    } else if (!uniqueNames.insert(company->getName()).second) {
      delete company;
      it = companies.erase(it);
    } else {
      ++it;
    }
  }
}

#endif //CPP_ADVANCED_REMOVEDUPLICATES_H
