#ifndef CPP_ADVANCED_STATISTICS_H
#define CPP_ADVANCED_STATISTICS_H

#include <vector>
#include "Structs.h"

class Statistics {
  std::vector<PersonInfo> elders{ };
  std::vector<PersonInfo> adults{ };
  std::vector<PersonInfo> minors{ };
public:
  void printStatistics();

  Statistics& operator<<(PersonInfo& personInfo);
};

#endif //CPP_ADVANCED_STATISTICS_H
