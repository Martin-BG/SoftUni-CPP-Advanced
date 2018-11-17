#ifndef CPP_ADVANCED_ARRAYWITHPAGE_H
#define CPP_ADVANCED_ARRAYWITHPAGE_H

#include <algorithm>
#include <cstdlib>

template<typename T>
class Page {
  T* data;
  size_t size;
public:
  explicit Page(size_t size) : data(new T[size]), size(size) { }

  virtual ~Page() {
    delete[] this->data;
  }

  Page(const Page<T>& other) : Page(other.size) {
    memcpy(this->data, other.data, sizeof(T) * other.size);
  }

  Page<T>& operator=(Page<T> other) {
    swap(*this, other);
    return *this;
  };

  operator T*() const {
    return this->data;
  }

  size_t getSize() const {
    return this->size;
  }

  friend void swap(Page& first, Page& second) {
    using std::swap;
    swap(first.size, second.size);
    swap(first.data, second.data);
  }
};

template<typename T>
class Array {
  Page<T> data;
public:
  explicit Array(size_t size) : data(size) { }

  size_t getSize() const {
    return this->data.getSize();
  }

  T* begin() const {
    return this->data;
  }

  T* end() const {
    return this->data + this->data.getSize();
  }

  T& operator[](size_t index) const {
    return this->data[index];
  }
};

#endif //CPP_ADVANCED_ARRAYWITHPAGE_H
