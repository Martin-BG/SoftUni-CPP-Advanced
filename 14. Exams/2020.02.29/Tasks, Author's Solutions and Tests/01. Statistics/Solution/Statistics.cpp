#include "Statistics.h"

Statistics& Statistics::operator<<(const PersonInfo& data) {
  if (data.age <= MINORS_AGE_TOP) //minors
  {
    _minorsMap[data.age].emplace_back(data.firstName,
                                      data.lastName,
                                      data.height);
  } else if (data.age >= ELDERS_AGE_BOTTOM) //elders
  {
    _eldersMap[data.age].emplace_back(data.firstName,
                                      data.lastName,
                                      data.height);
  } else //adults
  {
    _adultsMap[data.age].emplace_back(data.firstName,
                                      data.lastName,
                                      data.height);
  }

  return *this;
}

void Statistics::printStatistics() const {
  std::cout << "Elders data: \n";
  for (const std::pair<int, const std::vector<PersonInfoInternal>&>
        eldersForAge : _eldersMap) {
    for (const PersonInfoInternal& elder : eldersForAge.second) {
      elder.printDetails();
    }
  }

  std::cout << "Adults data: \n";
  for (const std::pair<int, const std::vector<PersonInfoInternal>&>
        adultsForAge : _adultsMap) {
    for (const PersonInfoInternal& adult : adultsForAge.second) {
      adult.printDetails();
    }
  }

  std::cout << "Minors data: \n";
  for (const std::pair<int, const std::vector<PersonInfoInternal>&>
        minorsForAge : _minorsMap) {
    for (const PersonInfoInternal& minor : minorsForAge.second) {
      minor.printDetails();
    }
  }
}


