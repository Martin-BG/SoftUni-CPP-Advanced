#ifndef REVERSE_NODE_H
#define REVERSE_NODE_H

#include "BufferedNode.h"

class ReverseNode : public BufferedNode {
public:
	ReverseNode(size_t id) : BufferedNode(id, '.') {}

	void processBuffer() override {
		for (int i = this->buffer.size() - 1; i >= 0; i--) {
			this->sendToConnected(this->buffer[i]);
		}
	}
};

#endif // !REVERSE_NODE_H

