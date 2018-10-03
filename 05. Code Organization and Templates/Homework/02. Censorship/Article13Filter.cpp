#include <utility>
#include "Article13Filter.h"

Article13Filter::Article13Filter(std::set<std::string> copyrighted) :
    copyrighted(std::move(copyrighted)) { }

bool Article13Filter::blockIfCopyrighted(std::string s) {
  if (this->isCopyrighted(s)) {
    this->blocked.push_back(s);
    return true;
  }
  return false;
}

bool Article13Filter::isCopyrighted(std::string s) {
  return this->copyrighted.find(s) != this->copyrighted.end();
}

std::vector<std::string> Article13Filter::getBlocked() {
  return this->blocked;
}
