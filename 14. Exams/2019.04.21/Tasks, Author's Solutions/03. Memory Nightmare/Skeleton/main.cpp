#include <iostream>
#include <sstream>
#include <stack>
#include "Defines.h"
#include "MemoryContainer.h"

void pushContainer(const ContainerType                containerType,
                   const size_t		                  containerSize,
                   std::stack<ContainerInterface *> & containers,
                   size_t &                           occupiedMemory);

void popContainer(std::stack<ContainerInterface *> & containers,
                  size_t &                           occupiedMemory);

void freeMemory(std::stack<ContainerInterface *> & containers);


int main()
{
    std::stack<ContainerInterface *> containers;
    size_t occupiedMemory = 0;

    std::string input;
    int commandsCount = 0;
    std::cin >> commandsCount;
    std::cin.ignore();

    for(int i = 0; i < commandsCount; ++i)
    {
        std::getline(std::cin, input);

        std::istringstream sstr(input);
        std::string command;

        sstr >> command;

        if("push" == command)
        {
            int containerType = 0;
            size_t containerSize = 0;

            sstr >> containerType >> containerSize;

            pushContainer(static_cast<ContainerType>(containerType),
                          containerSize,
                          containers,
                          occupiedMemory);
        }
        else //"pop" == command
        {
            popContainer(containers, occupiedMemory);
        }
    }

    //this function implementation will remain hidden from you
    freeMemory(containers);

    return 0;
}


