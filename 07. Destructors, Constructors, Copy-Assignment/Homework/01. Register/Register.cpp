#include "Register.h"

Register::Register(size_t numCompanies) : companiesArray(new Company[numCompanies]), numAdded(0) { }

void Register::add(const Company& c) {
  this->companiesArray[numAdded++] = c;
}

Company Register::get(int companyId) const {
  for (int i = 0; i < this->numAdded; ++i) {
    if (this->companiesArray[i].getId() == companyId) {
      return this->companiesArray[i];
    }
  }
}

Register::~Register() {
  delete[] this->companiesArray;
  this->companiesArray = nullptr;
  numAdded = 0;
}
