#ifndef CPP_ADVANCED_PARSECOMPANIES_H
#define CPP_ADVANCED_PARSECOMPANIES_H

#include <sstream>
#include <iterator>
#include <unordered_set>
#include <vector>
#include "Company.h"

Company* parseUniqueCompanies(const std::string& input,
                              int& numCompanies,
                              std::string(* identifier)(const Company&)) {
  numCompanies = 0;

  std::istringstream iss(input);
  std::vector<std::string> tokens(std::istream_iterator<std::string>{ iss },
                                  std::istream_iterator<std::string>());

  std::unordered_set<std::string> identifiers;
  std::vector<Company> uniqueCompanies;

  for (size_t i = 0; i < tokens.size(); i += 2) {
    Company company = Company(std::stoi(tokens.at(i)), tokens.at(i + 1));
    if (identifiers.insert(identifier(company)).second) {
      uniqueCompanies.push_back(company);
    }
  }

  numCompanies = (int) uniqueCompanies.size();
  auto companies = new Company[numCompanies];
  std::copy(uniqueCompanies.begin(), uniqueCompanies.end(), companies);

  return companies;
}

#endif //CPP_ADVANCED_PARSECOMPANIES_H
