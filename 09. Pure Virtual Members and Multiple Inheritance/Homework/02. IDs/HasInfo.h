#ifndef CPP_ADVANCED_HASINFO_H
#define CPP_ADVANCED_HASINFO_H

#include <string>

class HasInfo {
public:
  virtual ~HasInfo() = default;

  virtual std::string getInfo() const = 0;
};

#endif //CPP_ADVANCED_HASINFO_H
