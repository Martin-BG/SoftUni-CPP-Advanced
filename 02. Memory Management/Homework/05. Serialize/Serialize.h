#ifndef CPP_ADVANCED_SERIALIZE_H
#define CPP_ADVANCED_SERIALIZE_H

#include <string>
#include <sstream>
#include <iostream>
#include "Company.h"

namespace local {
  std::vector<Company> parseCompanies(const std::string& input) {
    std::vector<Company> companies{ };

    std::istringstream companiesIn(input);

    Company company;
    while (companiesIn >> company) {
      companies.push_back(company);
    }

    return companies;
  }

  std::vector<byte> serialize(const std::vector<Company>& companies) {
    std::vector<byte> serialized{ };

    serialized.push_back(static_cast<unsigned char&&>(companies.size()));

    for (const Company& company : companies) {
      serialized.push_back(static_cast<unsigned char&&>(company.getId()));

      auto companyName = company.getName();
      std::vector<byte> name(companyName.begin(), companyName.end());
      serialized.insert(serialized.end(), name.begin(), name.end());
      serialized.push_back('\0');

      serialized.push_back(static_cast<unsigned char&&>(company.getEmployees().size()));
      for (const std::pair<char, char>& employee : company.getEmployees()) {
        serialized.push_back(static_cast<unsigned char&&>(employee.first));
        serialized.push_back(static_cast<unsigned char&&>(employee.second));
      }
    }

    return serialized;
  }
}

byte* serializeToMemory(const std::string& input,
                        size_t& bytesWritten) {
  bytesWritten = 0;

  std::vector<Company> companies = local::parseCompanies(input);

  std::vector<byte> serialized = local::serialize(companies);

  bytesWritten = serialized.size();
  auto result = new byte[bytesWritten];
  std::copy(serialized.begin(), serialized.end(), result);

  return result;
}

#endif //CPP_ADVANCED_SERIALIZE_H
