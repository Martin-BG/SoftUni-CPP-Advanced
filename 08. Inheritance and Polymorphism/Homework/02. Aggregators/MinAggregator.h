#ifndef CPP_ADVANCED_MINAGGREGATOR_H
#define CPP_ADVANCED_MINAGGREGATOR_H

#include "Aggregator.h"

class MinAggregator : public StreamAggregator {
protected:
  void aggregate(int next) override {
    if (this->aggregationResult > next) {
      this->aggregationResult = next;
    }
  }

public:
  explicit MinAggregator(std::istream& input) : StreamAggregator(input) {
    this->aggregationResult = INT32_MAX;
  }
};

#endif //CPP_ADVANCED_MINAGGREGATOR_H
