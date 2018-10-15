#ifndef CPP_ADVANCED_SEQUENCE_H
#define CPP_ADVANCED_SEQUENCE_H

#include <vector>
#include <iostream>

template<typename T, typename Generator>
class Sequence {
private:
  Generator generator;
  std::vector<T> elements{ };
public:
  class Iterator {
    static const int END_ITERATOR_INDEX = -1;
    std::vector<T>& elements;
    int next;
  public:
    explicit Iterator(std::vector<T>& elements, bool endIterator = false) : elements(elements), next(0) {
      if (endIterator || this->elements.size() == 0) {
        this->next = END_ITERATOR_INDEX;
      }
    }

    const bool operator!=(const Iterator& rhs) const {
      return this->next != rhs.next;
    }

    typename Sequence<T, Generator>::Iterator operator++() {
      ++this->next;
      if (this->next >= this->elements.size()) {
        this->next = END_ITERATOR_INDEX;
      }
      return *this;
    }

    T operator*() const {
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
    return Iterator(this->elements, true);
  }
};

#endif //CPP_ADVANCED_SEQUENCE_H
