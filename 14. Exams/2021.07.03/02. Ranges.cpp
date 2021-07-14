#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <memory>

class Range {
  int start;
  int end;
public:
  Range() = default;

  int getStart() const {
    return start;
  }

  int getEnd() const {
    return end;
  }

  friend std::istream& operator>>(std::istream& is, Range& range) {
    is >> range.start >> range.end;
    return is;
  }
};

class RangesContainer {
  std::map<int, std::shared_ptr<Range>> starts{ };
  std::map<int, std::shared_ptr<Range>> ends{ };
public:

  void addRange(const Range& range) {
    auto rangePtr = std::make_shared<Range>(range);
    starts[range.getStart()] = rangePtr;
    ends[range.getEnd()] = rangePtr;
  }

  bool isInRange(const int value) const {
    auto start = starts.upper_bound(value);
    auto end = ends.lower_bound(value);
    return start != starts.begin() && ((--start)->second == end->second);
  }
};

int main() {
  const std::string& inputSeparator = ".";
  std::istream& in = std::cin;
  std::ostream& out = std::cout;

  std::ostream::sync_with_stdio(false);
  std::istream::sync_with_stdio(false);
  in.tie(nullptr);

  RangesContainer ranges{ };

  std::string line;
  while (getline(in, line) && line != inputSeparator) {
    std::istringstream lineIn(line);
    Range range{ };
    lineIn >> range;
    ranges.addRange(range);
  }

  std::ostringstream result;
  while (getline(in, line) && line != inputSeparator) {
    std::istringstream lineIn(line);
    int num;
    lineIn >> num;
    result << (ranges.isInRange(num) ? "in" : "out") << std::endl;
  }

  out << result.str();
}
