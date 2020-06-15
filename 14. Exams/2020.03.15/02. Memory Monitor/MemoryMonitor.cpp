#include <iostream>
#include "MemoryMonitor.h"

MemoryMonitor::MemoryMonitor() { }

MemoryMonitor::~MemoryMonitor() {
  for (auto& node : _nodes) {
    delete node.data;
  }
}

void MemoryMonitor::pushNode(const int nodeSize) {
  MemoryNode memoryNode;
  memoryNode.size = nodeSize;
  memoryNode.data = new int[nodeSize];

  _nodes.push_back(memoryNode);

  std::cout << "Pushed node with memory occupation: "
            << nodeSize * sizeof(int) << std::endl;
}

void MemoryMonitor::popNode() {
  if (_nodes.empty()) {
    std::cout << "No nodes to pop" << std::endl;
    return;
  }

  size_t releasedMemorySize = _nodes.back().size * sizeof(int);

  delete _nodes.back().data;
  _nodes.pop_back();

  std::cout << "Popped node with memory occupation: "
            << releasedMemorySize << std::endl;
}

void MemoryMonitor::printMemoryOccupation(const int numberOfNodes) {
  size_t usedMemory = 0;
  const size_t N = std::min(_nodes.size(), (size_t) numberOfNodes);

  for (size_t i = 0; i < N; ++i) {
    usedMemory += _nodes[i].size * sizeof(int);
  }

  std::cout << "Memory occupation for first " << numberOfNodes
            << " memory nodes is: " << usedMemory << std::endl;
}

MemoryNode MemoryMonitor::getLastNode() const {
  return _nodes.back();
}
