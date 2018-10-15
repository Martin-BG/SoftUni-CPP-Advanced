#ifndef CPP_ADVANCED_SEQUENCE_H
#define CPP_ADVANCED_SEQUENCE_H

#include <vector>
#include <iostream>

template<typename T>
class Iterator {
private:
  static const int END_ITERATOR_INDEX = -1;

  std::vector<T>& elements;
  int next;

  explicit Iterator(std::vector<T>& elements, int next) : elements(elements), next(next) { }

public:
  static Iterator begin(std::vector<T>& elements) {
    if (elements.size() == 0) {
      return end(elements);
    }
    return Iterator(elements, 0);
  }

  static Iterator end(std::vector<T>& elements) {
    return Iterator(elements, END_ITERATOR_INDEX);
  }

  const bool operator!=(const Iterator& other) const {
    return this->elements != other.elements || this->next != other.next;
  }

  Iterator& operator++() {
    ++this->next;
    if (this->next >= this->elements.size()) {
      this->next = END_ITERATOR_INDEX;
    }
    return *this;
  }

  T& operator*() const {
    return this->elements.at(this->next);
  }
};

template<typename T, typename Generator>
class Sequence {
private:
  Generator generator;
  std::vector<T> elements{ };
public:
  void generateNext(int count) {
    for (int i = 0; i < count; ++i) {
      this->elements.push_back(this->generator());
    }
  }

  Iterator<T> begin() {
    return Iterator<T>::begin(this->elements);
  }

  Iterator<T> end() {
    return Iterator<T>::end(this->elements);
  }
};

#endif //CPP_ADVANCED_SEQUENCE_H
