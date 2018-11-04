#ifndef MOUSE_H
#define MOUSE_H

#include "Organism.h"
#include "MovableOrganism.h"

class Mouse : public Organism, public MovableOrganism {
  int diagonal = 0;
  bool stopped = false;
  int actsInCurrentState = 0;

protected:
  void move() override {
    switch (this->diagonal) {
    case 0:
      this->position = Position(this->position.getRow() - 1, this->position.getCol() + 1);
      break;
    case 1:
      this->position = Position(this->position.getRow() - 1, this->position.getCol() - 1);
      break;
    case 2:
      this->position = Position(this->position.getRow() + 1, this->position.getCol() - 1);
      break;
    case 3:
      this->position = Position(this->position.getRow() + 1, this->position.getCol() + 1);
      break;
    default:
      break;
    }
  }

public:
  explicit Mouse(const Position& p) : Organism("mouse", p) { }

  void act() override {
    actsInCurrentState++;
    if (rand() % 100 < actsInCurrentState) {
      this->stopped = rand() % 2;

      this->diagonal = rand() % 4;
      this->actsInCurrentState = 0;
    }

    if (!this->stopped) {
      this->move();
    }
  }

  std::string getImage() const override {
    if (this->diagonal == 0 || this->diagonal == 3) {
      if (this->stopped) {
        return "~~(__^->";
      } else {
        return "~~(__^o>";
      }
    } else {
      if (this->stopped) {
        return "<-^__)~~";
      } else {
        return "<o^__)~~";
      }
    }
  }
};

#endif // !MOUSE_H

