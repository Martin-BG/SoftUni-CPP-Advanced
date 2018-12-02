#ifndef FILTER_NODE_H
#define FILTER_NODE_H

#include <set>
#include <vector>

#include "NodeBase.h"

class FilterNode : public NodeBase {
private:
	std::set<byte> blocked;
protected:
	virtual void block(byte data) {
		this->blocked.insert(data);
	}
public:
	FilterNode(size_t id, const std::vector<byte>& blocked) : NodeBase(id) {
		for (byte b : blocked) {
			this->block(b);
		}
	}

	virtual void process(byte data) override {
		if (this->blocked.find(data) == this->blocked.end()) {
			sendToConnected(data);
		}
	}
};

#endif // !FILTER_NODE_H

