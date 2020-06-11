#ifndef STATISTICS_H_
#define STATISTICS_H_

#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "Structs.h"

struct PersonInfoInternal {
  PersonInfoInternal(const std::string& inputFirstName,
                     const std::string& inputLastName,
                     const int inputHeight) :
      firstName(inputFirstName),
      lastName(inputLastName),
      height(inputHeight) { }

  void printDetails() const {
    std::cout << firstName << " " << lastName << " " << height << '\n';
  }

  const std::string firstName;
  const std::string lastName;
  const int height;
};

class Statistics {
public:
  Statistics() = default;

  virtual ~Statistics() = default;

  Statistics& operator<<(const PersonInfo& data);

  void printStatistics() const;

private:
  enum AgeMargins {
    MINORS_AGE_TOP = 18,
    ELDERS_AGE_BOTTOM = 63
  };

  std::map<int, std::vector<PersonInfoInternal>> _minorsMap;
  std::map<int, std::vector<PersonInfoInternal>> _adultsMap;
  std::map<int, std::vector<PersonInfoInternal>, std::greater<int>>
      _eldersMap;
};

#endif /* STATISTICS_H_ */
