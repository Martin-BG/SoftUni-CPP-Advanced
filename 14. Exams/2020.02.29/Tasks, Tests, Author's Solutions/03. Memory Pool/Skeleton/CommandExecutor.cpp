#include "CommandExecutor.h"

#include <sstream>
#include <iostream>

CommandExecutor::CommandExecutor(const int memoryPoolSize) :
 	 	 	 	 	 	 	 	 	 	 	 _memoryPool(memoryPoolSize)
{
	_usedNodes.reserve(memoryPoolSize);
}

void CommandExecutor::extractCommand(const std::string & commandStr)
{
	std::istringstream istr(commandStr);
	int currCommand = 0;
	istr >> currCommand;

	switch(currCommand)
	{
		case InputCommands::REQUEST_MEMORY:
		{
			int nodeSize = 0;
			istr >> nodeSize;

			executeRequestMemory(nodeSize);
		}
			break;

		case InputCommands::RELEASE_MEMORY:
		{
		    int memoryNodeIdx = 0;
	        istr >> memoryNodeIdx;
	        executeReleaseMemory(memoryNodeIdx);
		}
			break;

		case InputCommands::ZERO_MEMORY:
        {
            int memoryNodeIdx = 0;
            istr >> memoryNodeIdx;
            executeZeroMemory(memoryNodeIdx);
        }
			break;

		case InputCommands::SUM_NODE_DATA:
        {
            int memoryNodeIdx = 0;
            istr >> memoryNodeIdx;
		    executeSumNodeData(memoryNodeIdx);
        }
			break;

		case InputCommands::INCR_NODE_DATA_VALUE:
		{
            int memoryNodeIdx = 0;
		    int incrValue = 0;
            istr >> memoryNodeIdx >> incrValue;

		    executeIncrNodeDataValue(incrValue, memoryNodeIdx);
		}
		    break;

		default:
		    std::cerr << "Warning, received unknown InputCommand: "
		              << currCommand << std::endl;
		    break;
	}
}

void CommandExecutor::executeRequestMemory(const int nodeSize)
{
	MemoryNode memoryNode;
	memoryNode.size = nodeSize;

	const ErrorCode ERROR_CODE = _memoryPool.requestMemory(memoryNode);

    std::cout << "REQUEST_MEMORY for size: " << nodeSize << ", ErrorCode: ";

	if(REQUEST_SUCCESS == ERROR_CODE)
	{
		_usedNodes.push_back(memoryNode);

		std::cout << "REQUEST_SUCCESS";
	}
	else if(REQUEST_FAILURE_BIGGER_THAN_BUFFER == ERROR_CODE)
	{
        std::cout << "REQUEST_FAILURE_BIGGER_THAN_BUFFER";
	}
	else //REQUEST_FAILURE_NOT_ENOUGH_MEMORY == ERROR_CODE
	{
        std::cout << "REQUEST_FAILURE_NOT_ENOUGH_MEMORY";
	}

	std::cout << std::endl;
}

void CommandExecutor::executeReleaseMemory(const int nodeIdx)
{
	_memoryPool.releaseMemory(_usedNodes[nodeIdx]);

	_usedNodes.erase(_usedNodes.begin() + nodeIdx);

    std::cout << "RELEASE_MEMORY for idx: " << nodeIdx << std::endl;
}

void CommandExecutor::executeZeroMemory(const int nodeIdx)
{
	_memoryPool.zeroMemoryValue(_usedNodes[nodeIdx]);

    std::cout << "ZERO_MEMORY for idx: " << nodeIdx << std::endl;
}

void CommandExecutor::executeSumNodeData(const int nodeIdx)
{
	int sum = 0;

	for(int i = 0; i < _usedNodes[nodeIdx].size; ++i)
	{
		sum += _usedNodes[nodeIdx].memory[i];
	}

	std::cout << "SUM_NODE_DATA for idx: " << nodeIdx
	          << ", sum: " << sum << std::endl;
}

void CommandExecutor::executeIncrNodeDataValue(const int incrValue,
                                               const int nodeIdx)
{
    for(int i = 0; i < _usedNodes[nodeIdx].size; ++i)
    {
        _usedNodes[nodeIdx].memory[i] += incrValue;
    }

    std::cout << "INCR_NODE_DATA_VALUE for idx: " << nodeIdx
              << ", incrValue: " << incrValue << std::endl;
}


