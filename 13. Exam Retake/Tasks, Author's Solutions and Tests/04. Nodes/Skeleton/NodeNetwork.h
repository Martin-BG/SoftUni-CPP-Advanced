#ifndef NODE_NETWORK_H
#define NODE_NETWORK_H

#include "Node.h"
#include "DigitsToIntNode.h"
#include "ReverseNode.h"
#include "SumNode.h"
#include "FilterNode.h"
#include "InputNode.h"
#include "OutputNode.h"

#include <map>

class NodeNetwork {
	std::map<size_t, Node*> nodes;
	InputNode* inputNode;
public:
	NodeNetwork() = default;

	void compute() {
		this->inputNode->readAll();
	}

	void addNode(Node* node) {
		InputNode* asInput = dynamic_cast<InputNode*>(node);
		if (asInput != nullptr) {
			this->inputNode = asInput;
		}

		this->nodes[node->getId()] = node;
	}

	void connect(size_t fromId, size_t toId) {
		this->nodes[fromId]->connectTo(this->nodes[toId]);
	}

	NodeNetwork(const NodeNetwork& other) = delete;
	NodeNetwork& operator=(const NodeNetwork& other) = delete;

	~NodeNetwork() {
		for (auto idAndNode : this->nodes) {
			delete idAndNode.second;
		}
	}
};

#endif // !NODE_NETWORK_H

