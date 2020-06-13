#ifndef CPP_ADVANCED_COMPARATORS_H
#define CPP_ADVANCED_COMPARATORS_H

#include <string>
#include <iostream>
#include "Song.h"

template<typename T>
struct LessThan {
  bool operator()(const T& lhs, const T& rhs) const {
    return lhs < rhs;
  };
};

template<typename T, typename Comparator>
struct Reverse {
  bool operator()(const T& lhs, const T& rhs) const {
    Comparator comparator;
    return !comparator(lhs, rhs);
  }
};

/*// Solution with Comparator instance reuse
template<typename T, typename Comparator>
class Reverse {
  Comparator comparator;
public:
  const bool operator()(const T& lhs, const T& rhs) const {
    return !this->comparator(lhs, rhs);
  }
};*/

/*// Solution #2 - suboptimal
template<typename T>
struct LessThan {
  static const bool evaluate(const T& lhs, const T& rhs) {
    return lhs < rhs;
  };
};

template<typename T, typename D>
struct Reverse {
  bool operator()(const T& lhs, const T& rhs) const {
    return !D::evaluate(lhs, rhs);
  }
};*/

/*// Solution #1 - the hackish one
template<typename T>
struct comparator {
  bool const operator()(const T& lhs, const T& rhs) const {
    return !(lhs < rhs);
  }
};

template<class T>
using LessThan = comparator<T>;
template<typename T, typename D >
using Reverse = D;*/
#endif //CPP_ADVANCED_COMPARATORS_H
