#ifndef CPP_ADVANCED_LECTURE_H
#define CPP_ADVANCED_LECTURE_H

#include <set>
#include <vector>
#include "Resource.h"

namespace SoftUni {
  static const int RESOURCE_TYPES = 3;

  class Lecture {
    std::set<Resource> resources;
    int resourcesByType[RESOURCE_TYPES]{ };
  public:
    Lecture() = default;

    Lecture& operator<<(const Resource& resource) {
      if (this->resources.erase(resource) == 0) {
        ++this->resourcesByType[resource.getType()];
      }
      this->resources.insert(resource);
      return *this;
    }

    int operator[](const ResourceType& type) const {
      return this->resourcesByType[type];
    }

    std::set<Resource>::iterator begin() const {
      return this->resources.begin();
    };

    std::set<Resource>::iterator end() const {
      return this->resources.end();
    };

    friend std::vector<ResourceType>& operator<<(std::vector<ResourceType>& usedResources, const Lecture& lecture);
  };

  std::vector<ResourceType>& operator<<(std::vector<ResourceType>& usedResources, const Lecture& lecture) {
    for (int i = 0; i < RESOURCE_TYPES; ++i) {
      if (lecture.resourcesByType[i]) {
        usedResources.push_back((ResourceType) i);
      }
    }
    return usedResources;
  }
}

#endif //CPP_ADVANCED_LECTURE_H
