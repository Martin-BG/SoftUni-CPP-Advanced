#include <sstream>
#include <algorithm>
#include "StringConcatenator.h"

StringConcatenator::StringConcatenator() { };

StringConcatenator::~StringConcatenator() { }

std::string StringConcatenator::concatenate(ConcatenateStrategy strategy,
                                            const char* left, size_t leftSize,
                                            const char* right, size_t rightSize) const {
  int leftStep = (strategy == ConcatenateStrategy::LEFT_2_RIGHT_1) ? 2 : 1;
  int rightStep = (strategy == ConcatenateStrategy::LEFT_1_RIGHT_2) ? 2 : 1;
  size_t leftIndex = 0;
  size_t rightIndex = 0;

  std::ostringstream oss{ };

  while (leftIndex + leftStep <= leftSize && rightIndex + rightStep <= rightSize) {
    std::copy_n(&left[leftIndex], leftStep, std::ostreambuf_iterator<char>(oss));
    std::copy_n(&right[rightIndex], rightStep, std::ostreambuf_iterator<char>(oss));
    leftIndex += leftStep;
    rightIndex += rightStep;
  }

  if (leftIndex < leftSize) {
    std::copy_n(&left[leftIndex], leftSize - leftIndex, std::ostreambuf_iterator<char>(oss));
  }

  if (rightIndex < rightSize) {
    std::copy_n(&right[rightIndex], rightSize - rightIndex, std::ostreambuf_iterator<char>(oss));
  }

  return oss.str();
}
