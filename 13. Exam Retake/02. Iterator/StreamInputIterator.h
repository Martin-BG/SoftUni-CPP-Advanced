#ifndef CPP_ADVANCED_STREAMINPUTITERATOR_H
#define CPP_ADVANCED_STREAMINPUTITERATOR_H

#include <sstream>
#include <vector>

class StreamInputIterator {
  std::istream& in;
  std::string next;

public:
  explicit StreamInputIterator(std::istream& in) : in(in) { }

  explicit StreamInputIterator(std::istream& in, const std::string& endString) : StreamInputIterator(in) {
    this->next = endString;
  }

  static StreamInputIterator begin(std::istream& in) {
    return StreamInputIterator(in);
  }

  static StreamInputIterator end(std::istream& in, const std::string& endString) {
    return StreamInputIterator(in, endString);

  }

  const bool operator!=(const StreamInputIterator& other) const {
    return &this->in != &other.in || this->next != other.next;
  }

  StreamInputIterator& operator++() {
    this->in >> this->next;
    return *this;
  }

  int operator*() const {
    std::istringstream out(this->next);
    int n;
    if (out >> n) {
      return n;
    }
    return 0;
  }
};

#endif //CPP_ADVANCED_STREAMINPUTITERATOR_H
