#ifndef CPP_ADVANCED_BYTECONTAINER_H
#define CPP_ADVANCED_BYTECONTAINER_H

#include <string>

class ByteContainer {
private:
  const std::string bytes;

protected:
  explicit ByteContainer(std::string bytes) : bytes(std::move(bytes)) { }

  size_t getSize() const {
    return this->bytes.length();
  }

public:
  virtual ~ByteContainer() = default;

  std::string getBytes() const {
    return this->bytes;
  }
};

#endif //CPP_ADVANCED_BYTECONTAINER_H
