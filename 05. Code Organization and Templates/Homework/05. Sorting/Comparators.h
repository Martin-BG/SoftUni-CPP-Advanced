#ifndef CPP_ADVANCED_COMPARATORS_H
#define CPP_ADVANCED_COMPARATORS_H

#include <string>
#include <iostream>
#include "Song.h"

template<typename T>
class LessThan {
public:
  static bool evaluate(const T& lhs, const T& rhs) {
    return lhs < rhs;
  };
};

template<typename T, typename D>
class Reverse {
public:
  bool operator()(const T& lhs, const T& rhs) const {
    return !D::evaluate(lhs, rhs);
  }
};

/*
// Solution #1 - the hackish one
template<typename T>
struct comparator {
  bool operator()(const T& lhs, const T& rhs) const {
    return !(lhs < rhs);
  }
};

template<class T>
using LessThan = comparator<T>;
template<typename T, typename = LessThan<T> >
using Reverse = LessThan<T>;
*/
#endif //CPP_ADVANCED_COMPARATORS_H
