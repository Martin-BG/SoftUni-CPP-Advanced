#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using valuesCount = std::unordered_map<int, int>;

valuesCount readInputData(std::istream& in);

int main() {
  std::istream& in = std::cin;
  std::ostream& out = std::cout;

  valuesCount data = readInputData(in);

  int searchValue;
  while (in >> searchValue && searchValue != 0) {
    out << data[searchValue] << std::endl;
  }

  return 0;
}

valuesCount readInputData(std::istream& in) {
  std::unordered_set<int> separators{ };

  std::string separatorsLine;

  std::getline(in, separatorsLine);
  std::istringstream issSeparators(separatorsLine);
  int separator;
  while (issSeparators >> separator) {
    separators.emplace(separator);
  }

  valuesCount data{ };

  std::string message;
  std::getline(in, message);
  std::istringstream issValues(message);

  std::unordered_set<int> currentPartValues{ };
  int value;
  while (issValues >> value) {
    if (separators.find(value) != separators.end()) {
      currentPartValues.clear();
      continue;
    }

    if (currentPartValues.find(value) == currentPartValues.end()) {
      currentPartValues.emplace(value);
      ++data[value];
    }
  }

  return data;
}
