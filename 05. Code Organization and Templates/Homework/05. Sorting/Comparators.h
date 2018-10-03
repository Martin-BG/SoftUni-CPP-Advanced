#ifndef CPP_ADVANCED_COMPARATORS_H
#define CPP_ADVANCED_COMPARATORS_H

#include <string>
#include <iostream>
#include "Song.h"

struct lex_compare {
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
using LessThan = lex_compare;
template<typename T, typename = LessThan<T> >
using Reverse = LessThan<T>;

#endif //CPP_ADVANCED_COMPARATORS_H
