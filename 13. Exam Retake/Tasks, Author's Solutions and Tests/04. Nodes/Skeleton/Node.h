#ifndef NODE_H
#define NODE_H

#include <cstdlib>

typedef char byte;

class Node {
public:
	virtual size_t getId() const = 0;

	virtual void process(const byte data) = 0;

	virtual void connectTo(Node* other) = 0;

	virtual ~Node() {}
};

#endif // !NODE_H

