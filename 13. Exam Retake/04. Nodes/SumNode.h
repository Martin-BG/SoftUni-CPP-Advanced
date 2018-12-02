#ifndef CPP_ADVANCED_SUMNODE_H
#define CPP_ADVANCED_SUMNODE_H

#include "NodeBase.h"

class SumNode : public NodeBase {
  int sum;
public:
  explicit SumNode(size_t id) : NodeBase(id), sum(0) { }

  // A sum node stores its data as integer numbers and sums them.
  // It produces the sum as its result when it receives a value of 0
  void process(byte data) override {
    int value = (int) data;
    this->sum += value;
    if (value == 0) {
      this->sendToConnected(static_cast<byte>(this->sum));
      this->sum = 0;
    }
  }
};

#endif //CPP_ADVANCED_SUMNODE_H
