#ifndef CPP_ADVANCED_SUMAGGREGATOR_H
#define CPP_ADVANCED_SUMAGGREGATOR_H

#include "Aggregator.h"

class SumAggregator : public StreamAggregator {
protected:
  void aggregate(int next) override {
    this->aggregationResult += next;
  }

public:
  explicit SumAggregator(std::istream& input) : StreamAggregator(input) {
    this->aggregationResult = 0;
  }
};

#endif //CPP_ADVANCED_SUMAGGREGATOR_H
