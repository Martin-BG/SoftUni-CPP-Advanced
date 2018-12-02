#ifndef SUM_NODE_H
#define SUM_NODE_H

#include "BufferedNode.h"

class SumNode : public BufferedNode {
public:
	SumNode(size_t id) : BufferedNode(id, 0) {}

	void processBuffer() override {
		byte sum = 0;
		for (byte value : this->buffer) {
			sum += value;
		}

		this->sendToConnected(sum);
	}
};

#endif // !SUM_NODE_H

