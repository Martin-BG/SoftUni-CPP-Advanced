#ifndef CPP_ADVANCED_TRYPARSE_H
#define CPP_ADVANCED_TRYPARSE_H

#include <string>
#include <sstream>

bool tryParse(const std::string& str, int& num)
{
  return !(std::istringstream(str) >> num).fail();
}

#endif //CPP_ADVANCED_TRYPARSE_H
