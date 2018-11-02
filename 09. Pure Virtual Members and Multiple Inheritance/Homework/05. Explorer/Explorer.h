#ifndef CPP_ADVANCED_EXPLORER_H
#define CPP_ADVANCED_EXPLORER_H

#include <vector>

#include "File.h"
#include "Directory.h"
#include "Shortcuts.h"

using ObjectPtr = std::shared_ptr<FileSystemObject>;
using DirectoryPtr = std::shared_ptr<Directory>;
using Objects = std::vector<ObjectPtr>;

class Explorer {
private:
  Objects& rootObjects;
  DirectoryPtr root = std::make_shared<Directory>("\\");
  DirectoryPtr current = this->root;
  Objects clipboard{ };
  std::shared_ptr<Shortcuts> shortcuts = nullptr;

  void addToRoot(const ObjectPtr& obj) {
    this->rootObjects.push_back(obj);
    this->root->add(obj);
    obj->setParent(this->root);
  }

  void initFileSystemObject(const ObjectPtr& obj) {
    if (this->current == this->root) {
      this->addToRoot(obj);
    } else {
      obj->setParent(this->current);
      this->current->add(obj);
    }
  }

public:
  explicit Explorer(Objects& rootObjects) : rootObjects(rootObjects) { }

  void createFile(const std::string& filename, const std::string& data) {
    initFileSystemObject(std::make_shared<File>(filename, data));
  }

  void createDirectory(const std::string& directoryName) {
    initFileSystemObject(std::make_shared<Directory>(directoryName));
  }

  void createShortcut(const std::string& objectName) {
    auto item = this->current->getItemByName(objectName);
    if (!item) {
      return;
    }
    if (!this->shortcuts) {
      this->shortcuts = std::make_shared<Shortcuts>();
      this->addToRoot(this->shortcuts);
    }
    this->shortcuts->add(item);
  }

  void cut(const std::string& objectName) {
    ObjectPtr obj = current->getItemByName(objectName);
    if (obj) {
      this->clipboard.push_back(obj);
    }
  }

  void paste() {
    for (const auto& item : this->clipboard) {
      const std::shared_ptr<Directory>& parent = std::dynamic_pointer_cast<Directory>(item->getParent().lock());
      parent->remove(item);
      if (parent == this->root) {
        this->rootObjects.erase(std::find(this->rootObjects.begin(), this->rootObjects.end(), item));
      }
      this->initFileSystemObject(item);
    }
    this->clipboard.clear();
  }

  void navigate(const std::string& path) {
    if (path == ".." && this->current != this->root) {
      this->current = std::dynamic_pointer_cast<Directory>(this->current->getParent().lock());
      return;
    }
    auto newDirectory = this->current->getItemByName(path);
    if (newDirectory && std::dynamic_pointer_cast<Directory>(newDirectory)) {
      this->current = std::dynamic_pointer_cast<Directory>(newDirectory);
    }
  }
};

#endif //CPP_ADVANCED_EXPLORER_H
