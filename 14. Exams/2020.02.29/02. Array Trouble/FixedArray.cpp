#include <algorithm>
#include "FixedArray.h"

FixedArray::FixedArray(const int arraySize) : BrokenArray(arraySize) {
}

FixedArray::~FixedArray() = default;

FixedArray::FixedArray(const FixedArray& other) : BrokenArray(other) {
  _array = new int[getSize()];
  std::copy(other._array, other._array + getSize(), _array);
}

FixedArray& FixedArray::operator=(const FixedArray& other) {
  if (&other == this) {
    return *this;
  }

  int* copy = new int[other.getSize()];

  std::copy(other._array, other._array + other.getSize(), copy);

  delete[] _array;
  _array = copy;
  BrokenArray::operator=(other);

  return *this;
}

void FixedArray::addValueToMemory(const int value) {
  BrokenArray::addValueToMemory(value);
}

int FixedArray::getMemorySumValue() const {
  return BrokenArray::getMemorySumValue();
}
