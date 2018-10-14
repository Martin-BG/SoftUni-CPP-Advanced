#ifndef CPP_ADVANCED_SEQUENCE_H
#define CPP_ADVANCED_SEQUENCE_H

#include <vector>
#include <iostream>

template<typename T, typename Generator>
class Sequence {
private:
  static const int END_ITERATOR_INDEX = -1;
  Generator generator;
  std::vector<T> elements{ };
public:
  class Iterator {
    std::vector<T>& elements;
    int next = END_ITERATOR_INDEX;
  public:
    explicit Iterator(std::vector<T>& elements) : elements(elements) {
      if (this->elements.size() > 0) {
        this->next = 0;
      }
    }

    explicit Iterator(std::vector<T>& elements, int index) : elements(elements), next(index) {
      if (this->elements.size() <= this->next || (this->next < 0 && this->next != END_ITERATOR_INDEX)) {
        this->next = END_ITERATOR_INDEX;
      }
    }

    bool operator!=(const Iterator& rhs) const {
      return this->next != rhs.next;
    }

    typename Sequence<T, Generator>::Iterator operator++() {
      ++this->next;
      if (this->next >= this->elements.size()) {
        this->next = END_ITERATOR_INDEX;
      }
      return *this;
    }

    T operator*() {
      return this->elements.at(this->next);
    }
  };

  void generateNext(int count) {
    for (int i = 0; i < count; ++i) {
      this->elements.push_back(this->generator());
    }
  }

  Iterator begin() {
    return Iterator(this->elements);
  }

  Iterator end() {
    return Iterator(this->elements, END_ITERATOR_INDEX);
  }
};

#endif //CPP_ADVANCED_SEQUENCE_H
