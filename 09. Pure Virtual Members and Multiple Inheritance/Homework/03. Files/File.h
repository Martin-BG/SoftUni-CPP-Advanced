#ifndef CPP_ADVANCED_FILE_H
#define CPP_ADVANCED_FILE_H

#include "ByteContainer.h"
#include "FileSystemObject.h"

class File : public FileSystemObject, public ByteContainer {
public:
  File(std::string filename, std::string bytes)
      : FileSystemObject(std::move(filename)), ByteContainer(std::move(bytes)) { }

  size_t getSize() const override {
    return ByteContainer::getSize();
  }
};

#endif //CPP_ADVANCED_FILE_H
