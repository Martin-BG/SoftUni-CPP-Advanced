#include <stack>
#include <iostream>
#include "MemoryContainer.h"
#include "Defines.h"

void pushContainer(const ContainerType                containerType,
                   const size_t		                  containerSize,
                   std::stack<ContainerInterface *> & containers,
                   size_t &                           occupiedMemory)
{
    switch(containerType)
    {
        case ContainerType::SHORT_CONTAINER:
            containers.push(new MemoryContainer<short>(containerSize));
            break;

        case ContainerType::INT_CONTAINER:
            containers.push(new MemoryContainer<int>(containerSize));
            break;

        case ContainerType::LONG_LONG_CONTAINER:
            containers.push(new MemoryContainer<long long>(containerSize));
            break;

        default:
            break;
    }

    occupiedMemory += containers.top()->getOccupiedMemory();

    std::cout << "occupiedMemory: " << occupiedMemory << std::endl;
}

void popContainer(std::stack<ContainerInterface *> & containers,
                  size_t &                           occupiedMemory)
{
    if(!containers.empty())
    {
        occupiedMemory -= containers.top()->getOccupiedMemory();
        delete containers.top();

        containers.pop();
    }

    std::cout << "occupiedMemory: " << occupiedMemory << std::endl;
}



