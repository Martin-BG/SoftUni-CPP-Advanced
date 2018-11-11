#include "IndexedSet.h"

IndexedSet::IndexedSet() : valuesSet(std::set<Value>{ }), valuesArray(nullptr) { }

IndexedSet::IndexedSet(const IndexedSet& other) : IndexedSet() {
  this->valuesSet.insert(other.valuesSet.begin(), other.valuesSet.end());
}

void IndexedSet::add(const Value& v) {
  this->clearIndex();
  this->valuesSet.insert(v);
}

size_t IndexedSet::size() const {
  return this->valuesSet.size();
}

const Value& IndexedSet::operator[](size_t index) {
  this->buildIndex();
  return this->valuesArray[index];
}

IndexedSet& IndexedSet::operator=(const IndexedSet& other) {
  if (this != &other) {
    this->clearIndex();
    this->valuesSet.clear();
    this->valuesSet.insert(other.valuesSet.begin(), other.valuesSet.end());
  }
  return *this;
}

IndexedSet::~IndexedSet() {
  this->clearIndex();
}

void IndexedSet::buildIndex() {
  if (this->valuesArray == nullptr) {
    this->clearIndex();
    this->valuesArray = new Value[this->size()];
    size_t index = 0;
    for (const auto& v : this->valuesSet) {
      this->valuesArray[index++] = v;
    }
  }
}

void IndexedSet::clearIndex() {
  if (this->valuesArray != nullptr) {
    delete[] this->valuesArray;
    this->valuesArray = nullptr;
  }
}
