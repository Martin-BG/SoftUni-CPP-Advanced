#ifndef CPP_ADVANCED_CONTAINERINTERFACE_H
#define CPP_ADVANCED_CONTAINERINTERFACE_H

class ContainerInterface {
public:
  virtual ~ContainerInterface() = default;

  virtual size_t getOccupiedMemory() const {
    return 0;
  }
};

#endif //CPP_ADVANCED_CONTAINERINTERFACE_H
