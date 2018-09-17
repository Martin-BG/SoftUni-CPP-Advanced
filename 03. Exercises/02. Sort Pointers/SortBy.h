#ifndef CPP_ADVANCED_SORTBY_H
#define CPP_ADVANCED_SORTBY_H

#include <algorithm>
#include "Company.h"

void sortBy(Company** first, Company** end, bool (* comp)(const Company&, const Company&)) {
  std::sort(first, end, [&](const Company* const a, const Company* const b) {
    return comp(*a, *b);
  });
}

#endif //CPP_ADVANCED_SORTBY_H
