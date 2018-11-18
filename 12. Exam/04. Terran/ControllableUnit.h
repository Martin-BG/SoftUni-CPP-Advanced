#ifndef CONTROLLABLE_UNIT_H
#define CONTROLLABLE_UNIT_H

#include <string>

#include "Unit.h"
#include "Controllable.h"

class ControllableUnit : public Unit, public Controllable {
  Id id;
public:
  ControllableUnit(Id id, std::string type) : Unit(type), id(id) { }

  Id getId() const override {
    return this->id;
  }

  void update() override { }

  std::string getInfo() override {
    std::ostringstream info;
    info << Unit::getInfo() << " " << id;
    return info.str();
  }
};

#endif // !CONTROLLABLE_UNIT_H

