#ifndef CPP_ADVANCED_EXPLORER_H
#define CPP_ADVANCED_EXPLORER_H

#include <vector>

#include "File.h"
#include "Directory.h"
#include "Shortcuts.h"

using ObjectPtr = std::shared_ptr<FileSystemObject>;
using ParentPtr = std::weak_ptr<Directory>;
using Objects = std::vector<ObjectPtr>;

class Explorer {
private:
  Objects& rootObjects;
  const ParentPtr rootFolder{ };
  ParentPtr current{ };
  Objects clipboard{ };
  std::shared_ptr<Shortcuts> shortcuts = nullptr;

  void addToRoot(const ObjectPtr& obj) {
    this->rootObjects.push_back(obj);
    obj->setParent(this->rootFolder);
  }

  void initFileSystemObject(const ObjectPtr& obj) {
    if (auto currentFolderPtr = this->current.lock()) {
      obj->setParent(currentFolderPtr);
      currentFolderPtr->add(obj);
    } else {
      this->addToRoot(obj);
    }
  }

  const ObjectPtr getItemByNameInRoot(const std::string& objectName) const {
    auto it = find_if(this->rootObjects.cbegin(), this->rootObjects.cend(),
                      [&objectName](const ObjectPtr& obj) { return obj->getName() == objectName; });
    return (it != this->rootObjects.cend()) ? *it : nullptr;
  }

  const ObjectPtr getItemByNameInCurrentDirectory(const std::string& objectName) const {
    if (auto currentFolderPtr = this->current.lock()) {
      return currentFolderPtr->getItemByName(objectName);
    }

    return this->getItemByNameInRoot(objectName);
  }

public:
  explicit Explorer(Objects& rootObjects) : rootObjects(rootObjects) { }

  void createFile(const std::string& filename, const std::string& data) {
    this->initFileSystemObject(std::make_shared<File>(filename, data));
  }

  void createDirectory(const std::string& directoryName) {
    this->initFileSystemObject(std::make_shared<Directory>(directoryName));
  }

  void createShortcut(const std::string& objectName) {
    if (auto item = this->getItemByNameInCurrentDirectory(objectName)) {
      if (!this->shortcuts) {
        this->shortcuts = std::make_shared<Shortcuts>();
        this->addToRoot(this->shortcuts);
      }
      this->shortcuts->add(item);
    }
  }

  void cut(const std::string& objectName) {
    if (auto obj = this->getItemByNameInCurrentDirectory(objectName)) {
      this->clipboard.push_back(obj);
    }
  }

  void paste() {
    for (const auto& item : this->clipboard) {
      if (item->getParent().expired()) {
        this->rootObjects.erase(std::find(this->rootObjects.begin(), this->rootObjects.end(), item));
      } else {
        std::static_pointer_cast<Directory>(item->getParent().lock())->remove(item);
      }
      this->initFileSystemObject(item);
    }
    this->clipboard.clear();
  }

  void navigate(const std::string& path) {
    if (path == "..") {
      if (!this->current.expired()) {
        this->current = std::static_pointer_cast<Directory>(this->current.lock()->getParent().lock());
      }
      return;
    }

    if (auto newObject = this->getItemByNameInCurrentDirectory(path)) {
      if (auto newDirectory = std::dynamic_pointer_cast<Directory>(newObject)) {
        this->current = newDirectory;
      }
    }
  }
};

#endif //CPP_ADVANCED_EXPLORER_H
