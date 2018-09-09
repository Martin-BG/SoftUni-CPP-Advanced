#ifndef CPP_ADVANCED_ORDEREDINSERTER_H
#define CPP_ADVANCED_ORDEREDINSERTER_H

#include <vector>
#include "Company.h"

class OrderedInserter {
  std::vector<const Company*>& companies;
public:
  explicit OrderedInserter(std::vector<const Company*>& companies) :
      companies(companies)
  { }

  void insert(const Company* company)
  {
    auto it = this->companies.begin();
    while (it != this->companies.end()) {
      if ((*it)->getId() > company->getId()) {
        this->companies.insert(it, company);
        return;
      }
      ++it;
    }
    this->companies.push_back(company);
  }
};

#endif //CPP_ADVANCED_ORDEREDINSERTER_H
