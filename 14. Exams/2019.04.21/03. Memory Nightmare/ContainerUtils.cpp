#include <stack>
#include <iostream>
#include "MemoryContainer.h"
#include "Defines.h"

void printOccupiedMemory(const size_t occupiedMemory) {
  std::cout << "occupiedMemory: " << occupiedMemory << std::endl;
}

void pushContainer(const ContainerType containerType,
                   const size_t containerSize,
                   std::stack<ContainerInterface*>& containers,
                   size_t& occupiedMemory) {

  ContainerInterface* container;

  switch (containerType) {
  case SHORT_CONTAINER:
    container = new MemoryContainer<short>(containerSize);
    break;
  case INT_CONTAINER:
    container = new MemoryContainer<int>(containerSize);
    break;
  case LONG_LONG_CONTAINER:
    container = new MemoryContainer<long long>(containerSize);
    break;
  }

  occupiedMemory += container->getOccupiedMemory();
  containers.push(container);

  printOccupiedMemory(occupiedMemory);
}

void popContainer(std::stack<ContainerInterface*>& containers,
                  size_t& occupiedMemory) {
  if (!containers.empty()) {
    auto container = containers.top();
    containers.pop();
    occupiedMemory -= container->getOccupiedMemory();
    delete container;
  }
  printOccupiedMemory(occupiedMemory);
}

// NOTE: Remove this method before submitting solution to Judge system
void freeMemory(std::stack<ContainerInterface*>& containers) {
  while (!containers.empty()) {
    auto container = containers.top();
    containers.pop();
    delete container;
  }
}
