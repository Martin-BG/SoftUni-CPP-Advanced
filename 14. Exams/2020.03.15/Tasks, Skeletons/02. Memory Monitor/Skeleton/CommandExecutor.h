#ifndef COMMANDEXECUTOR_H_
#define COMMANDEXECUTOR_H_

#include <string>

#include "MemoryMonitor.h"

class CommandExecutor
{
	public:
		CommandExecutor() = default;
		~CommandExecutor() = default;

		void extractCommand(const std::string & commandStr);

	private:
		void executePushNode(const int nodeSize);

		void executePopNode();

		void executePrintMemoryOccupation(const int numberOfNodes);

		MemoryMonitor _memoryMonitor;
};

#endif /* COMMANDEXECUTOR_H_ */
