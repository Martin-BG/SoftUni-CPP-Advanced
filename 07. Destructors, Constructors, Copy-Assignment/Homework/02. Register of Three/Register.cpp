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
