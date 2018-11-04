#ifndef CPP_ADVANCED_ORGANISMFACTORY_H
#define CPP_ADVANCED_ORGANISMFACTORY_H

#include <memory>
#include <vector>
#include "Organism.h"

struct OrganismFactory {
  virtual std::vector<std::shared_ptr<Organism> > buildOrganisms() = 0;

  virtual ~OrganismFactory() = default;
};

#endif //CPP_ADVANCED_ORGANISMFACTORY_H
