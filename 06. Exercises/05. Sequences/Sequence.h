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
  private:
    static const int END_ITERATOR_INDEX = -1;
    std::vector<T>& elements;
    int next;

    explicit Iterator(std::vector<T>& elements, int next) : elements(elements), next(next) {
      if (next >= this->elements.size() || this->elements.size() == 0) {
        this->next = END_ITERATOR_INDEX;
      }
    }

  public:
    static Iterator end(std::vector<T>& elements) {
      return Iterator(elements, END_ITERATOR_INDEX);
    }

    static Iterator begin(std::vector<T>& elements) {
      return Iterator(elements, 0);
    }

    const bool operator!=(const Iterator& other) const {
      return this->elements != other.elements || this->next != other.next;
    }

    Iterator operator++() {
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

  void generateNext(int count) {
    for (int i = 0; i < count; ++i) {
      this->elements.push_back(this->generator());
    }
  }

  Iterator begin() {
    return Iterator::begin(this->elements);
  }

  Iterator end() {
    return Iterator::end(this->elements);
  }
};

#endif //CPP_ADVANCED_SEQUENCE_H
