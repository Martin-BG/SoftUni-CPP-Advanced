#ifndef CPP_ADVANCED_RESOURCE_H
#define CPP_ADVANCED_RESOURCE_H

#include <ostream>
#include <string>
#include <sstream>
#include "ResourceType.h"

namespace SoftUni {
  class Resource {
    int id{ };
    ResourceType type{ };
    std::string link;
  public:
    Resource() = default;

    int getId() const {
      return this->id;
    }

    ResourceType getType() const {
      return this->type;
    }

    const std::string& getLink() const {
      return this->link;
    }

    bool operator<(const Resource& other) const {
      return this->id < other.id;
    }

    bool operator==(const Resource& other) const {
      return this->id == other.id;
    }

    friend std::ostream& operator<<(std::ostream& out, const Resource& resource);

    friend std::istream& operator>>(std::istream& in, Resource& resource);
  };

  std::ostream& operator<<(std::ostream& out, const Resource& resource) {
    return out << resource.id << " " << resource.type << " " << resource.link;
  }

  std::istream& operator>>(std::istream& in, ResourceType& resourceType) {
    std::string type;
    in >> type;
    if (type == "Presentation") {
      resourceType = ResourceType::PRESENTATION;
    } else if (type == "Demo") {
      resourceType = ResourceType::DEMO;
    } else if (type == "Video") {
      resourceType = ResourceType::VIDEO;
    }
    return in;
  }

  std::istream& operator>>(std::istream& in, Resource& resource) {
    return in >> resource.id >> resource.type >> resource.link;
  }
}

#endif //CPP_ADVANCED_RESOURCE_H
