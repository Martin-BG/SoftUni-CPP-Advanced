#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include "Company.h"

std::vector<Company> readCompanies() {
  std::vector<Company> companies;
  std::string line;

  getline(std::cin, line);
  while (line != "end") {
    std::istringstream lineIn(line);
    std::string name;
    int id;
    lineIn >> name >> id;
    companies.emplace_back(id, name);
    getline(std::cin, line);
  }

  return companies;
}

bool compId(const Company& a, const Company& b) {
  return a.getId() < b.getId();
}

bool compName(const Company& a, const Company& b) {
  return a.getName() < b.getName();
}

int main() {

  auto companies = readCompanies();

  bool (* comp)(const Company&, const Company&) = nullptr;

  std::string sortBy;
  getline(std::cin, sortBy);

  if (sortBy == "id") {
    comp = compId;
  } else if (sortBy == "name") {
    comp = compName;
  } else {
    comp = nullptr;
  }

  std::sort(companies.begin(), companies.end(), comp);

  for (auto company: companies) {
    std::cout << company.toString() << std::endl;
  }

  return 0;
}
