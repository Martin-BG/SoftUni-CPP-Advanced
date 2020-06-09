#ifndef CPP_ADVANCED_CONTAINERINTERFACE_H
#define CPP_ADVANCED_CONTAINERINTERFACE_H

#include <cstddef>

class ContainerInterface {
public:
  virtual ~ContainerInterface() = default;

  virtual size_t getOccupiedMemory() const = 0;
};

#endif //CPP_ADVANCED_CONTAINERINTERFACE_H
