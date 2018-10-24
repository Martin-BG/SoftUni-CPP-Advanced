#ifndef CPP_ADVANCED_AVERAGEAGGREGATOR_H
#define CPP_ADVANCED_AVERAGEAGGREGATOR_H

#include "Aggregator.h"

class AverageAggregator : public StreamAggregator {
private:
  int sum;

protected:
  void aggregate(int next) override {
    StreamAggregator::aggregate(next);
    this->sum += next;
    this->aggregationResult = this->sum / StreamAggregator::getNumAggregated();
  }

public:
  explicit AverageAggregator(std::istream& input) : StreamAggregator(input), sum(0) {
    this->aggregationResult = 0;
  }
};

#endif //CPP_ADVANCED_AVERAGEAGGREGATOR_H
