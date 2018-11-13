#include "Range.h"

Range::Range() :
    rangeFirst(0),
    rangeLength(0),
    valueCounts(new size_t[0]{ }) { }

void Range::add(T value) {
  if (this->empty()) {
    this->resize(value, value);
  } else if (this->rangeFirst > value) {
    this->resize(value, this->rangeFirst + this->rangeLength);
  } else if (this->rangeFirst + this->rangeLength <= value) {
    this->resize(this->rangeFirst, value);
  }
  this->valueCounts[this->getIndex(value)]++;
}

size_t Range::getCount(T value) const {
  if (value < this->rangeFirst || value >= this->rangeFirst + this->rangeLength) {
    return 0;
  }
  return this->valueCounts[this->getIndex(value)];
}

void Range::clear() {
  this->rangeFirst = 0;
  this->rangeLength = 0;
  delete[] this->valueCounts;
  this->valueCounts = new size_t[0]{ };
}

void Range::resize(T first, T last) {
  int newLength = last - first + 1;
  auto* newValues = new size_t[newLength]{ };
  for (int i = 0; i < newLength; i++) {
    newValues[i] = this->getCount(first + i);
  }
  this->clear();
  this->valueCounts = newValues;
  this->rangeFirst = first;
  this->rangeLength = newLength;
}

bool Range::empty() const {
  return this->rangeLength == 0;
}

Range::Range(const Range& other) :
    rangeFirst(other.rangeFirst),
    rangeLength(other.rangeLength),
    valueCounts(Range::copyValues(other)) { }

Range& Range::operator=(const Range& other) {
  if (this != &other) {
    this->clear();
    this->valueCounts = Range::copyValues(other);
    this->rangeFirst = other.rangeFirst;
    this->rangeLength = other.rangeLength;
  }
  return *this;
}

Range::~Range() {
  this->clear();
}

size_t Range::getIndex(T value) const {
  return static_cast<size_t>(value - this->rangeFirst);
}
