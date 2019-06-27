#ifndef CPP_ADVANCED_MAX_H
#define CPP_ADVANCED_MAX_H

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <limits.h>

class VectorMax {
  int max{ INT_MIN };
  std::vector<int> nums{ };
public:
  VectorMax() = default;

  friend void operator>>(const std::vector<int>& arr, VectorMax& vectorMax) {
    vectorMax.nums = arr;
    vectorMax.max = *std::max_element(vectorMax.nums.begin(), vectorMax.nums.end());
  }

  friend std::ostream& operator<<(std::ostream& out, const VectorMax& vectorMax) {
    for (auto const& num : vectorMax.nums) {
      out << num << ' ';
    }
    return out;
  }

  friend const bool operator<(const VectorMax& lhs, const VectorMax& rhs) {
    return lhs.max < rhs.max;
  }
};

/*class VectorMax {
  std::vector<int> nums{ };
public:
  VectorMax() = default;

  friend void operator>>(std::vector<int>& arr, VectorMax& vectorMax) {
    vectorMax.nums.insert(vectorMax.nums.begin(), arr.begin(), arr.end());
  }

  friend std::ostream& operator<<(std::ostream& out, const VectorMax& vectorMax) {
    for (auto const& num : vectorMax.nums) {
      out << num << ' ';
    }
    return out;
  }

  friend const bool operator<(const VectorMax& lhs, const VectorMax& rhs) {
    return *std::max_element(lhs.nums.begin(), lhs.nums.end()) < *std::max_element(rhs.nums.begin(), rhs.nums.end());
  }
};*/

#endif //CPP_ADVANCED_MAX_H
