#ifndef CPP_ADVANCED_ARRAYOFPOINTERS_H
#define CPP_ADVANCED_ARRAYOFPOINTERS_H

#include <vector>
#include "Company.h"

class ArrayOfPointers {
private:
  std::vector<Company*> companies;
public:
  ArrayOfPointers() : companies(std::vector<Company*>{ }) { }

  virtual ~ArrayOfPointers() {
    for (Company* c : this->companies) {
      delete c;
    }
  }

  void add(Company* pCompany) {
    this->companies.push_back(pCompany);
  }

  size_t getSize() {
    return this->companies.size();
  }

  Company* get(size_t index) {
    return this->companies.at(index);
  }
};

#endif //CPP_ADVANCED_ARRAYOFPOINTERS_H
