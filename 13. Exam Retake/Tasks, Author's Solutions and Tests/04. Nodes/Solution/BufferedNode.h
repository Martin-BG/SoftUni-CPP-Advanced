#ifndef BUFFERED_NODE_H
#define BUFFERED_NODE_H

#include "NodeBase.h"

class BufferedNode : public NodeBase {
private:
	byte flushByte;
protected:
	std::vector<byte> buffer;
public:
	BufferedNode(size_t id, byte flushByte) : NodeBase(id), flushByte(flushByte) {}

	virtual void process(byte data) override {
		if (data != this->flushByte) {
			this->buffer.push_back(data);
		}
		else {
			this->processBuffer();
			this->buffer.clear();
		}
	}

	virtual void processBuffer() = 0;
};

#endif // !BUFFERED_NODE_H

