#ifndef ORGANISM_H
#define ORGANISM_H

#include <string>

#include "Position.h"

class Organism {
protected:
  std::string name;
  Position position;

  Organism(std::string name, const Position& position) : name(std::move(name)), position(position) { }

public:

  virtual ~Organism() = default;

  virtual void act() = 0;

  virtual std::string getImage() const = 0;

  Position getPosition() const {
    return this->position;
  }
};

#endif // !ORGANISM_H

