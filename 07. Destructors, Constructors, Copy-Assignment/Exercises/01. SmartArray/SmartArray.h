#ifndef CPP_ADVANCED_SMARTARRAY_H
#define CPP_ADVANCED_SMARTARRAY_H

#include <utility>
#include <cstddef>
#include <iostream>
#include <memory>

template<typename T>
class SmartArray {
private:
  T* data;
  size_t size;
public:
  SmartArray() : data(nullptr), size(0) { };

  explicit SmartArray(size_t size) : data(new T[size]{ }), size(size) { };

  SmartArray(std::initializer_list<T> elements) : data(new T[elements.size()]), size(elements.size()) {
    std::copy(elements.begin(), elements.end(), data);
  }

  SmartArray(const SmartArray<T>& other) : data(nullptr), size(other.size) {
    if (other.data != nullptr) {
      T* newData = new T[other.size];
      for (size_t i = 0; i < other.size; ++i) {
        newData[i] = other.data[i];
      }
      this->data = newData;
    }
  }

  ~SmartArray() {
    delete[] this->data;
    this->data = nullptr;
    this->size = 0;
  }

  size_t getSize() const {
    return this->size;
  }

  void resize(const size_t& newSize) {
    if (newSize > 0) {
      T* newData = new T[newSize]{ };
      if (this->data != nullptr) {
        for (size_t i = 0; i < this->size && i < newSize; ++i) {
          newData[i] = this->data[i];
        }
        delete[] this->data;
      }
      this->size = newSize;
      this->data = newData;
    } else {
      delete[] this->data;
      this->data = nullptr;
      this->size = 0;
    }
  }

  T* begin() const {
    return this->data;
  }

  T* end() const {
    return this->data + this->size;
  }

  T& operator[](const size_t& index) const {
    return this->data[index];
  }

  // Classic solution
/*  SmartArray<T>& operator=(const SmartArray<T>& other) {
    if (this != &other) {
      T* newData = nullptr;
      if (other.data != nullptr) {
        newData = new T[other.size];
        for (int i = 0; i < other.size; ++i) {
          newData[i] = other.data[i];
        }
      }
      if (this->data != nullptr) {
        delete[] this->data;
        this->size = other.size;
      }
      this->data = newData;
    }
    return *this;
  };*/

  // Solution with copy-and-swap idiom:
  // https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom
  SmartArray<T>& operator=(SmartArray<T> other) {
    if (this != &other) {
      swap(*this, other);
    }
    return *this;
  };

  // https://stackoverflow.com/questions/5695548/public-friend-swap-member-function
  // https://en.cppreference.com/w/cpp/language/adl
  friend void swap(SmartArray& first, SmartArray& second) {
    using std::swap;
    swap(first.size, second.size);
    swap(first.data, second.data);
  }

  friend std::ostream& operator<<(std::ostream& out, const SmartArray& a) {
    for (auto element: a) {
      std::cout << element << " ";
    }
    return out;
  }
};

#endif //CPP_ADVANCED_SMARTARRAY_H
