#ifndef CPP_ADVANCED_TOMANDJERRYFACTORY_H
#define CPP_ADVANCED_TOMANDJERRYFACTORY_H

#include "OrganismFactory.h"
#include "Cat.h"
#include "Mouse.h"

struct TomAndJerryFactory : public OrganismFactory {
  std::vector<std::shared_ptr<Organism> > buildOrganisms() override {
    std::vector<std::shared_ptr<Organism> > result;

    result.push_back(std::make_shared<Cat>(Position(0, 0)));
    result.push_back(std::make_shared<Mouse>(Position(0, 0)));

    return result;
  }
};

#endif //CPP_ADVANCED_TOMANDJERRYFACTORY_H
