#ifndef MEMORYMONITOR_H_
#define MEMORYMONITOR_H_

#include <vector>

#include "Structs.h"

class MemoryMonitor
{
	public:
		MemoryMonitor();
		~MemoryMonitor();

		void pushNode(const int nodeSize);

		void popNode();

		void printMemoryOccupation(const int numberOfNodes);

		MemoryNode getLastNode() const;

	private:
		std::vector<MemoryNode> _nodes;
};

#endif /* MEMORYMONITOR_H_ */
