#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>

int main() {
  std::istream& in = std::cin;
  std::ostream& out = std::cout;

  std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> indexedData{ };

  std::string indexName;
  in >> indexName;

  std::string entityData;
  while (std::getline(in >> std::ws, entityData) && entityData != "[queries]") {
    std::istringstream iss(entityData);
    std::unordered_map<std::string, std::string> entityDataPairs{ };
    std::string indexFieldValue;
    std::string fieldName;
    while (iss >> fieldName) {
      if (fieldName == indexName) {
        iss >> indexFieldValue;
        continue;
      }

      iss >> entityDataPairs[fieldName];
    }

    for (const auto& pair : entityDataPairs) {
      indexedData[indexFieldValue][pair.first].emplace_back(pair.second);
    }
  }

  std::string query;
  while (std::getline(in >> std::ws, query) && query != "end") {
    std::istringstream iss(query);
    std::string indexedValue;
    std::string secondaryColumnName;
    iss >> indexedValue >> secondaryColumnName;

    if (indexedData.find(indexedValue) == indexedData.end()) {
      out << "[not found]" << std::endl;
      continue;
    }

    for (const auto& data : indexedData[indexedValue][secondaryColumnName]) {
      out << data << " ";
    }
    out << std::endl;
  }

  return 0;
}
