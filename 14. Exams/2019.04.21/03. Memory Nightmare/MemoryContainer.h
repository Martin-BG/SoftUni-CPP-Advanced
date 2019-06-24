#ifndef MEMORYCONTAINER_H_
#define MEMORYCONTAINER_H_

#include "ContainerInterface.h"

template <typename T>
class MemoryContainer : public ContainerInterface
{
    public:
        MemoryContainer() = delete;

        MemoryContainer(const size_t size)
        {
            _data = new T[size];

            _dataCount = size;
        }

        virtual ~MemoryContainer()
        {
            delete[] _data;
            _data = nullptr;

            _dataCount = 0;
        }

        virtual size_t getOccupiedMemory() const override
        {
            return (sizeof(T) * _dataCount);
        }

    private:
        T *    _data;
        size_t _dataCount;
};

#endif /* MEMORYCONTAINER_H_ */
