#include <ostream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "Statistics.h"
#include "Structs.h"

void Statistics::printStatistics() {
  std::sort(elders.begin(), elders.end(), std::greater<PersonInfo>());
  std::sort(adults.begin(), adults.end());
  std::sort(minors.begin(), minors.end());

  std::cout << "Elders data:" << std::endl;
  std::copy(elders.cbegin(), elders.cend(),
            std::ostream_iterator<PersonInfo>(std::cout, "\n"));

  std::cout << "Adults data:" << std::endl;
  std::copy(adults.cbegin(), adults.cend(),
            std::ostream_iterator<PersonInfo>(std::cout, "\n"));

  std::cout << "Minors data:" << std::endl;
  std::copy(minors.cbegin(), minors.cend(),
            std::ostream_iterator<PersonInfo>(std::cout, "\n"));
}

Statistics& Statistics::operator<<(PersonInfo& personInfo) {
  if (personInfo.age > 62) {
    elders.emplace_back(std::move(personInfo));
  } else if (personInfo.age > 18) {
    adults.emplace_back(std::move(personInfo));
  } else {
    minors.emplace_back(std::move(personInfo));
  }

  return *this;
}

std::ostream& operator<<(std::ostream& os, const PersonInfo& personInfo) {
  return os << personInfo.firstName << " "
            << personInfo.lastName << " "
            << personInfo.height;
}

bool operator<(const PersonInfo& lhs, const PersonInfo& rhs) {
  return lhs.age < rhs.age;
}

bool operator>(const PersonInfo& lhs, const PersonInfo& rhs) {
  return lhs.age > rhs.age;
}
