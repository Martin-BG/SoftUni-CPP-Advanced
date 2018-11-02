#ifndef CPP_ADVANCED_COMPANY_H
#define CPP_ADVANCED_COMPANY_H

#include <vector>
#include <sstream>

#include "HasId.h"
#include "HasInfo.h"

class Company : public HasId, public HasInfo {
private:
  int id;
  std::string name;
  std::vector<std::pair<char, char> > employees;
public:
  Company();

  Company(int id, std::string name, std::vector<std::pair<char, char> > employees);

  int getId() const override;

  std::string getName() const;

  std::vector<std::pair<char, char> > getEmployees() const;

  std::string getInfo() const override;

  friend std::ostream& operator<<(std::ostream& stream, const Company& c);

  friend std::istream& operator>>(std::istream& stream, Company& c);
};

#endif //CPP_ADVANCED_COMPANY_H
