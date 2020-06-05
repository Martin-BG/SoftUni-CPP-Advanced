#ifndef COMMANDEXECUTOR_H_
#define COMMANDEXECUTOR_H_

#include <string>
#include <vector>

#include "MemoryPool.h"

class CommandExecutor
{
	public:
		CommandExecutor(const int memoryPoolSize);
		virtual ~CommandExecutor() = default;

		void extractCommand(const std::string & commandStr);

	private:
		void executeRequestMemory(const int nodeSize);

		void executeReleaseMemory(const int nodeIdx);

		void executeZeroMemory(const int nodeIdx);

		void executeSumNodeData(const int nodeIdx);

        void executeIncrNodeDataValue(const int incrValue,
                                      const int nodeIdx);

		MemoryPool 				_memoryPool;

		std::vector<MemoryNode> _usedNodes;
};

#endif /* COMMANDEXECUTOR_H_ */
