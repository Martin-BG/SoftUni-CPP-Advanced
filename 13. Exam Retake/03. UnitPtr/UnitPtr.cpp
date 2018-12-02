#include "UnitPtr.h"
#include <iostream>

std::map<T*, int> UnitPtr::refCount = { };

UnitPtr::UnitPtr(T* rawPointer) : pointer(rawPointer) {
  UnitPtr::refCount[rawPointer] = 1;
}

UnitPtr::UnitPtr() : pointer(nullptr) { }

UnitPtr UnitPtr::from(T* rawPointer) {
  return UnitPtr(rawPointer);
}

UnitPtr::UnitPtr(const UnitPtr& other) {
  this->pointer = other.pointer;
  UnitPtr::refCount[other.pointer]++;
}

T& UnitPtr::operator*() {
  return *this->pointer;
}

T* UnitPtr::operator->() const {
  return this->pointer;
}

UnitPtr& UnitPtr::operator=(const UnitPtr& other) {
  if (this != &other) {
    UnitPtr::refCount[this->pointer]--;
    if (refCount[this->pointer] <= 0) {
      UnitPtr::refCount.erase(this->pointer);
      delete this->pointer;
    }
    this->pointer = other.pointer;
    UnitPtr::refCount[other.pointer]++;
  }
  return *this;
}

UnitPtr::~UnitPtr() {
  UnitPtr::refCount[this->pointer]--;
  if (refCount[this->pointer] <= 0) {
    UnitPtr::refCount.erase(this->pointer);
    delete this->pointer;
  }
}
