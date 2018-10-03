#ifndef CPP_ADVANCED_PRINTUTILS_H
#define CPP_ADVANCED_PRINTUTILS_H

#include <iostream>
#include <sstream>
#include <vector>

template<typename T>
void printVector(std::vector<T> container) {
  for (auto& i : container) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

#endif //CPP_ADVANCED_PRINTUTILS_H
