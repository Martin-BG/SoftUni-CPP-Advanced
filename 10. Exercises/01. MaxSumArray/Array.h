#ifndef CPP_ADVANCED_ARRAY_H
#define CPP_ADVANCED_ARRAY_H

#include <algorithm>
#include <cstdlib>

template<typename T>
class Array {
  T* data;
  size_t size;
public:
  explicit Array(size_t size) : data(new T[size]), size(size) { }

  Array(const Array<T>& other) : Array(other.size) {
    memcpy(this->data, other.data, sizeof(T) * other.size);
  }

  virtual ~Array() {
    delete[] this->data;
  }

  size_t getSize() const {
    return this->size;
  }

  T* begin() const {
    return this->data;
  }

  T* end() const {
    return this->data + this->size;
  }

  T& operator[](size_t index) const {
    return this->data[index];
  }

  Array<T>& operator=(Array<T> other) {
    swap(*this, other);
    return *this;
  };

  friend void swap(Array& first, Array& second) {
    using std::swap;
    swap(first.size, second.size);
    swap(first.data, second.data);
  }
};

#endif //CPP_ADVANCED_ARRAY_H
