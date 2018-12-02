#ifndef NODE_BASE_H
#define NODE_BASE_H

#include <vector>
#include "Node.h"

class NodeBase : public Node {
	size_t id;

	std::vector<Node*> connected;
public:
	NodeBase(size_t id) : id(id) {}

	size_t getId() const {
		return this->id;
	}

	virtual void process(byte data) = 0;

	void sendToConnected(byte data, size_t connectedIndex) {
		if (this->connected.size() > connectedIndex && this->connected[connectedIndex] != nullptr) {
			this->connected[connectedIndex]->process(data);
		}
	}

	void sendToConnected(byte data) {
		for (auto n : this->connected) {
			n->process(data);
		}
	}

	void connectTo(Node* node) override {
		this->connected.push_back(node);
	}
};

#endif // !NODE_BASE_H

