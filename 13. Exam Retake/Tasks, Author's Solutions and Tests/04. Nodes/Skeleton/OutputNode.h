#ifndef OUTPUT_NODE_H
#define OUTPUT_NODE_H

#include <ostream>

#include "NodeBase.h"

class OutputNode : public NodeBase {
	std::ostream& out;
	bool numberOutput;
public:
	OutputNode(size_t id, std::ostream& out, bool numberOutput) : NodeBase(id), out(out), numberOutput(numberOutput) {}

	void process(byte data) override {
		if (this->numberOutput) {
			out << (int)data << " ";
		}
		else {
			out << data << " ";
		}
	}
};

#endif // !OUTPUT_NODE_H

