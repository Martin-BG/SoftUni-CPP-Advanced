#ifndef CONTAINERINTERFACE_H_
#define CONTAINERINTERFACE_H_

#include <cstddef>

class ContainerInterface
{
    public:
        ContainerInterface() = default;
        virtual ~ContainerInterface() = default;

        virtual size_t getOccupiedMemory() const = 0;
};

#endif /* CONTAINERINTERFACE_H_ */
