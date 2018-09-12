#ifndef CPP_ADVANCED_MAKECOMPANY_H
#define CPP_ADVANCED_MAKECOMPANY_H

#include <memory>
#include "Company.h"

std::shared_ptr<Company> makeCompany(const std::vector<std::string>& properties) {
  const auto id = std::stoi(properties.at(0));
  const auto name = properties.at(1);
  std::vector<std::pair<char, char> > employees;
  for (uint64_t i = 2; i < properties.size(); ++i) {
    employees.emplace_back(properties.at(i)[0], properties.at(i)[1]);
  }
  return std::make_shared<Company>(id, name, employees);
}

#endif //CPP_ADVANCED_MAKECOMPANY_H
