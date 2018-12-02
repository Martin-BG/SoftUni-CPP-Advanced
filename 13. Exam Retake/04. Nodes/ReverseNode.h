#ifndef CPP_ADVANCED_REVERSENODE_H
#define CPP_ADVANCED_REVERSENODE_H

#include "NodeBase.h"
#include <vector>
#include <algorithm>

class ReverseNode : public NodeBase {
  std::vector<byte> data;
public:
  explicit ReverseNode(size_t id) : NodeBase(id) { }

  // A reverse node stores data it receives and reverses its order when a '.' (dot)
  // is encountered (the dot is not included in the result), and treats that as its result
  void process(byte data) override {
    if (data == '.') {
      std::reverse(this->data.begin(), this->data.end());
      for (auto b: this->data) {
        this->sendToConnected(b);
      }
      this->data.clear();
    } else {
      this->data.push_back(data);
    }
  }
};

#endif //CPP_ADVANCED_REVERSENODE_H
