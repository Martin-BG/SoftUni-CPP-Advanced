#ifndef INPUT_NODE_H
#define INPUT_NODE_H

#include <istream>

#include "NodeBase.h"

class InputNode : public NodeBase {
	std::istream& in;
public:
	InputNode(size_t id, std::istream& in) : NodeBase(id), in(in) {}

	void process(byte data) override {
		this->sendToConnected(data);
	}

	void readAll() {
		byte data;

		while (in >> data && data != '|') {
			this->process(data);
		}
	}
};

#endif // !INPUT_NODE_H

