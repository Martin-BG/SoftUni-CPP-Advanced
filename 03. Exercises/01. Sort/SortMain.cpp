#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include "Company.h"

std::vector<Company> readCompanies();

bool (* getSortingFunction())(const Company&, const Company&);

bool compId(const Company& a, const Company& b);

bool compName(const Company& a, const Company& b);

int main() {
  auto companies = readCompanies();
  auto comp = getSortingFunction();

  std::sort(companies.begin(), companies.end(), comp);

  for (auto company: companies) {
    std::cout << company.toString() << std::endl;
  }

  return 0;
}

bool compId(const Company& a, const Company& b) {
  return a.getId() < b.getId();
}

bool compName(const Company& a, const Company& b) {
  return a.getName() < b.getName();
}

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

bool (* getSortingFunction())(const Company&, const Company&) {
  bool (* comp)(const Company&, const Company&);

  std::string sortBy;
  getline(std::cin, sortBy);

  if (sortBy == "id") {
    comp = compId;
  } else if (sortBy == "name") {
    comp = compName;
  } else {
    comp = nullptr;
  }

  return comp;
}
