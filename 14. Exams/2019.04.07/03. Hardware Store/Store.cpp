#include "Store.h"

void Store::remove(const int index) {
  _laptops.erase(_laptops.begin() + index);
}

void Store::copy(const int fromIndex, const int toIndex) {
  _laptops.at(toIndex) = _laptops.at(fromIndex);
}

