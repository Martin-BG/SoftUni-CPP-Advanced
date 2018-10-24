#include "Register.h"

Register::Register(size_t numCompanies) : numAdded(0), companiesArray(new Company[numCompanies]) { }

void Register::add(const Company& c) {
  this->companiesArray[this->numAdded++] = c;
}

Company Register::get(int companyId) const {
  for (size_t i = 0; i < this->numAdded; ++i) {
    if (this->companiesArray[i].getId() == companyId) {
      return this->companiesArray[i];
    }
  }

  return Company();
}

Register::~Register() {
  delete[] this->companiesArray;
}

Register& Register::operator=(const Register& other) {
  if (this != &other) {
    Company* temp = new Company[other.numAdded];
    for (size_t i = 0; i < other.numAdded; ++i) {
      temp[i] = other.companiesArray[i];
    }

    delete[] this->companiesArray;

    this->companiesArray = temp;
    this->numAdded = other.numAdded;
  }
  return *this;
}

Register::Register(const Register& other) {
  Company* temp = new Company[other.numAdded];
  for (size_t i = 0; i < other.numAdded; ++i) {
    temp[i] = other.companiesArray[i];
  }

  delete[] this->companiesArray;

  this->companiesArray = temp;
  this->numAdded = other.numAdded;
}
