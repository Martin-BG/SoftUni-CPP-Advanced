#ifndef CPP_ADVANCED_HASID_H
#define CPP_ADVANCED_HASID_H

class HasId {
public:
  virtual ~HasId() = default;

  virtual int getId() const = 0;
};

#endif //CPP_ADVANCED_HASID_H
