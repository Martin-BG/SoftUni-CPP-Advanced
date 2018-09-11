#ifndef NODE_H

class Node {
public:
  int value;
  Node* next;

  Node(int value, Node* next) : value(value), next(next) { }
};

#define NODE_H
#endif // !NODE_H
