#ifndef CPP_ADVANCED_FILTERNODE_H
#define CPP_ADVANCED_FILTERNODE_H

#include "NodeBase.h"
#include <vector>
#include <set>

class FilterNode : public NodeBase {
  std::set<byte> filtered;
public:
  explicit FilterNode(size_t id, std::vector<byte> filtered) : NodeBase(id),
                                                               filtered(filtered.begin(), filtered.end()) { }

  // A filter node ignores any data matching certain predefined values,
  // and its result is each data item that is not one of those predefined values
  void process(byte data) override {
    if (this->filtered.find(data) == this->filtered.end()) {
      this->sendToConnected(data);
    }
  }
};

#endif //CPP_ADVANCED_FILTERNODE_H
