#ifndef DIGITS_TO_INT_NODE
#define DIGITS_TO_INT_NODE

#include "BufferedNode.h"

class DigitsToIntNode : public BufferedNode {
public:
	DigitsToIntNode(size_t id) : BufferedNode(id, '.') {}

	virtual void processBuffer() override {
		byte number = 0;
		for (byte digitChar : this->buffer) {
			int digit = digitChar - '0';

			number *= 10;
			number += digit;
		}

		this->sendToConnected(number);
	}
};

#endif // !DIGITS_TO_INT_NODE

