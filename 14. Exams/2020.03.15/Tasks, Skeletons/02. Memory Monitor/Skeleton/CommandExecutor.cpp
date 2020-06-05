#include "CommandExecutor.h"
#include "Defines.h"

#include <sstream>
#include <iostream>
#include <cstdlib>

void CommandExecutor::extractCommand(const std::string & commandStr)
{
	std::istringstream istr(commandStr);
	int currCommand = 0;
	istr >> currCommand;

	switch(currCommand)
	{
		case InputCommands::PUSH_NODE:
		{
			int nodeSize = 0;
			istr >> nodeSize;

			executePushNode(nodeSize);
		}
			break;

		case InputCommands::POP_NODE:
	        executePopNode();
			break;

		case InputCommands::PRINT_MEMORY_OCCUPATION:
        {
            int numberOfNodes = 0;
            istr >> numberOfNodes;
            executePrintMemoryOccupation(numberOfNodes);
        }
			break;

		default:
		    std::cerr << "Warning, received unknown InputCommand: "
		              << currCommand << std::endl;
		    break;
	}
}

void CommandExecutor::executePushNode(const int nodeSize)
{
	_memoryMonitor.pushNode(nodeSize);

	const MemoryNode node = _memoryMonitor.getLastNode();

	//checking whether your application will crash
	for(int i = 0; i < node.size; ++i)
	{
		node.data[i] = (rand() % nodeSize);
	}
}

void CommandExecutor::executePopNode()
{
	_memoryMonitor.popNode();
}

void CommandExecutor::executePrintMemoryOccupation(const int numberOfNodes)
{
	_memoryMonitor.printMemoryOccupation(numberOfNodes);
}



