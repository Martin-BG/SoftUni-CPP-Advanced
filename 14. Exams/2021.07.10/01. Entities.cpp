#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>

using data = std::unordered_map<std::string, std::unordered_map<std::string, int>>;
using result = std::pair<std::string, int>;

data readInputData(std::istream& in);

result findMostCommonValue(const std::string& column, const data& db);

int main() {
  std::istream& in = std::cin;
  std::ostream& out = std::cout;

  data db = readInputData(in);

  std::string column;
  in >> column;

  result res = findMostCommonValue(column, db);

  out << res.first << " " << res.second << std::endl;

  return 0;
}

data readInputData(std::istream& in) {
  std::vector<std::string> columnNames{ };

  std::string header;
  std::getline(in >> std::ws, header);
  std::istringstream iss(header);
  std::string columnName;
  while (iss >> columnName) {
    columnNames.emplace_back(columnName);
  }

  data db{ };
  std::string dataRow;
  while (std::getline(in >> std::ws, dataRow) && dataRow != "end") {
    std::istringstream issData(dataRow);
    for (auto const& column : columnNames) {
      std::string data;
      issData >> data;
      ++db[column][data];
    }
  }

  return db;
}

result findMostCommonValue(const std::string& column, const data& db) {
  std::string mostCommonValue;
  int mostCommonValueCount = 0;

  for (const auto& pair : db.at(column)) {
    const std::string& value = pair.first;
    const int count = pair.second;

    if (count > mostCommonValueCount) {
      mostCommonValueCount = count;
      mostCommonValue = value;
    }
  }

  return std::make_pair(mostCommonValue, mostCommonValueCount);
}
