#ifndef CPP_ADVANCED_DIGITSTOINTNODE_H
#define CPP_ADVANCED_DIGITSTOINTNODE_H

#include "NodeBase.h"
#include <vector>

class DigitsToIntNode : public NodeBase {
  std::vector<byte> elements{ };

public:
  explicit DigitsToIntNode(size_t id) : NodeBase(id) { }

  // An int node stores the data it gets as characters, which are digits in a number ('0'-'9')
  // and converts it into a non-negative integer number result.
  // The node expects the sequence to end in a '.' (dot)
  void process(byte data) override {
    if (data == '.') {
      std::string result(this->elements.begin(), this->elements.end());
      this->sendToConnected(static_cast<byte>(stoi(result)));
      this->elements.clear();
    } else if (data >= '0' && data <= '9') {
      this->elements.push_back(data);
    }
  }
};

#endif //CPP_ADVANCED_DIGITSTOINTNODE_H
