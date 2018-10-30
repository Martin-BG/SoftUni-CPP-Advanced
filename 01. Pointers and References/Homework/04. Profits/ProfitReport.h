#ifndef CPP_ADVANCED_PROFITREPORT_H
#define CPP_ADVANCED_PROFITREPORT_H

#include <map>
#include <sstream>
#include "Company.h"
#include "ProfitCalculator.h"

std::string getProfitReport(const Company* fromInclusive,
                            const Company* toInclusive,
                            const std::map<int, ProfitCalculator>& profitCalculatorsByCompany)
{
  std::ostringstream oss;
  const Company* current = fromInclusive;
  while (true) {
    oss << current->getName()
        << " = "
        << profitCalculatorsByCompany.at(current->getId()).calculateProfit(*current)
        << std::endl;
    if (current == toInclusive) {
      break;
    }
    ++current;
  }
  return oss.str();
}

#endif //CPP_ADVANCED_PROFITREPORT_H
