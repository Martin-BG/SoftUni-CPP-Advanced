#ifndef CPP_ADVANCED_TREEVIEW_H
#define CPP_ADVANCED_TREEVIEW_H

#include <vector>
#include <sstream>
#include <set>

#include "FileSystemObjectsContainer.h"

namespace TreeViewUtils {
  using ObjectPtr = std::shared_ptr<FileSystemObject>;
  using Objects = std::vector<ObjectPtr>;

  static const char* const PREFIX = "--->";

  struct ObjectComparator {
    bool operator()(const ObjectPtr& lhs, const ObjectPtr& rhs) const {
      return lhs->getName() < rhs->getName();
    }
  };

  void walk(const ObjectPtr& obj, std::ostringstream& oss, const std::string& prefix) {
    oss << prefix << obj->getName() << std::endl;
    auto dirPtr = std::dynamic_pointer_cast<FileSystemObjectsContainer>(obj);
    if (dirPtr) {
      const std::set<ObjectPtr, ObjectComparator> items(dirPtr->begin(), dirPtr->end());
      for (const auto& item: items) {
        walk(item, oss, prefix + PREFIX);
      }
    }
  }
}

std::string getTreeView(TreeViewUtils::Objects rootObjects) {
  std::ostringstream oss;
  for (const auto& obj: rootObjects) {
    TreeViewUtils::walk(obj, oss, "");
  }
  return oss.str();
}

#endif //CPP_ADVANCED_TREEVIEW_H
