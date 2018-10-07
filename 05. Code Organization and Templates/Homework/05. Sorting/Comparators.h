#ifndef CPP_ADVANCED_COMPARATORS_H
#define CPP_ADVANCED_COMPARATORS_H

#include <string>
#include <iostream>
#include "Song.h"

struct comparator {
  bool operator()(const int& lhs, const int& rhs) const {
    return lhs >= rhs;
  }

  bool operator()(const std::string& lhs, const std::string& rhs) const {
    return lhs >= rhs;
  }

  bool operator()(const Song& lhs, const Song& rhs) const {
    return lhs.getLengthSeconds() >= rhs.getLengthSeconds();
  }
};

template<class T>
using LessThan = comparator;
template<typename T, typename = LessThan<T> >
using Reverse = LessThan<T>;

#endif //CPP_ADVANCED_COMPARATORS_H
