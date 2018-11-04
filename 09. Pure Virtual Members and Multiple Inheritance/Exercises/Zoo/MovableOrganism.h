#ifndef CPP_ADVANCED_MOVABLEORGANISM_H
#define CPP_ADVANCED_MOVABLEORGANISM_H

class MovableOrganism {
protected:
  virtual void move() = 0;

  virtual void changeMovement() { };
public:

  virtual ~MovableOrganism() = default;
};

#endif //CPP_ADVANCED_MOVABLEORGANISM_H
