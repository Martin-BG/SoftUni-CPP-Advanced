#include "MemoryMonitor.h"

#include <iostream>

MemoryMonitor::MemoryMonitor()
{

}

MemoryMonitor::~MemoryMonitor()
{
	for(MemoryNode & node : _nodes)
	{
		delete node.data;
	}
}

void MemoryMonitor::pushNode(const int nodeSize)
{
	MemoryNode node;
	node.size = nodeSize;
	node.data = new int[nodeSize];

	std::cout << "Pushed node with memory occupation: "
			  << (nodeSize * sizeof(int)) << '\n';

	_nodes.push_back(node);
}

void MemoryMonitor::popNode()
{
	if(!_nodes.empty())
	{
		delete _nodes.back().data;

		std::cout << "Popped node with memory occupation: "
				  << (_nodes.back().size * sizeof(int)) << '\n';

		_nodes.pop_back();
	}
	else
	{
		std::cout << "No nodes to pop\n";
	}
}

void MemoryMonitor::printMemoryOccupation(const int numberOfNodes)
{
	size_t currSize = 0;
	const int SIZE = static_cast<int>(_nodes.size());

	for(int i = 0; i < SIZE && i < numberOfNodes; ++i)
	{
		currSize += (_nodes[i].size * sizeof(int));
	}

	std::cout << "Memory occupation for first " << numberOfNodes
			  << " memory nodes is: " << currSize << '\n';
}

MemoryNode MemoryMonitor::getLastNode() const
{
	return _nodes.back();
}

