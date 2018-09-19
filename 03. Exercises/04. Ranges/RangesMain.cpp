#include <iostream>
#include <sstream>
#include <string>
#include <map>

int main() {
  std::ostream::sync_with_stdio(false);
  std::istream::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::map<int, int> starts;
  std::map<int, int> ends;

  int rangeId = 0;
  std::string line;
  while (getline(std::cin, line) && line != ".") {
    std::istringstream lineIn(line);
    int from, to;
    lineIn >> from >> to;
    starts[from] = rangeId;
    ends[to] = rangeId;
    ++rangeId;
  }

  std::ostringstream result;
  while (getline(std::cin, line) && line != ".") {
    std::istringstream lineIn(line);
    int num;
    lineIn >> num;
    auto start = starts.upper_bound(num);
    auto end = ends.lower_bound(num);
    if (start != starts.begin() && ((--start)->second == end->second)) {
      result << "in" << std::endl;
    } else {
      result << "out" << std::endl;
    }
  }

  std::cout << result.str();
  * /
}
