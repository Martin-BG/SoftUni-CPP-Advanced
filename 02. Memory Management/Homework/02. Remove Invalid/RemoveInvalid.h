#ifndef CPP_ADVANCED_REMOVEINVALID_H
#define CPP_ADVANCED_REMOVEINVALID_H

#include <list>
#include <algorithm>
#include "Company.h"

namespace local {
  bool removed(Company* company) {
    if (company->getId() < 0) {
      delete company;
      return true;
    }
    return false;
  }
}

void removeInvalid(std::list<Company*>& companies) {
  companies.remove_if(local::removed);
}

/* //Solution using lambda
void removeInvalid(std::list<Company*>& companies) {
  companies.remove_if([](Company* company) {
    if (company->getId() < 0) {
      delete company;
      return true;
    }
    return false;
  });
}
*/

#endif //CPP_ADVANCED_REMOVEINVALID_H
