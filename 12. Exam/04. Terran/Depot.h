#ifndef DEPOT_H
#define DEPOT_H

#include "Unit.h"

class Depot : public Unit {
public:
  static const int BUILD_TIME = 25;

  Depot() : Unit("depot") { }

  void update() override {
  }
};

#endif // !DEPOT_H

