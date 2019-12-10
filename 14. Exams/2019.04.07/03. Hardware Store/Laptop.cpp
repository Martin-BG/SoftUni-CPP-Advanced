#include "Laptop.h"

Laptop::Laptop(const std::string& name,
               const double price,
               const double monitorSize) :
    Hardware(name, price),
    _monitorSize(monitorSize) {
  this->printInfo();
  std::cout << " is being created" << std::endl;
}

Laptop::~Laptop() {
  this->printInfo();
  std::cout << " is being destroyed" << std::endl;
}

Laptop::Laptop(const Laptop& other) :
    Hardware(other.getName(), other.getPrice()),
    _monitorSize(other._monitorSize) {
  std::cout << "Copy construction for ";
  this->printInfo();
  std::cout << std::endl;
}

Laptop& Laptop::operator=(const Laptop& other) {
  if (this != &other) {
    Hardware::operator=(other);
    this->_monitorSize = other._monitorSize;
    std::cout << "Copy assignment for ";
  } else {
    std::cout << "Self-copy prevented for ";
  }
  this->printInfo();
  std::cout << std::endl;

  return *this;
}
