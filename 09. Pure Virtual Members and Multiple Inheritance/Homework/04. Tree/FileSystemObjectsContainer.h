#ifndef FILE_SYSTEM_OBJECTS_CONTAINER_H
#define FILE_SYSTEM_OBJECTS_CONTAINER_H

#include <list>
#include <memory>

#include "FileSystemObject.h"

class FileSystemObjectsContainer {
public:
	virtual void add(const std::shared_ptr<FileSystemObject>& obj) = 0;

	virtual std::list<std::shared_ptr<FileSystemObject> >::const_iterator begin() const = 0;
	virtual std::list<std::shared_ptr<FileSystemObject> >::const_iterator end() const = 0;

	virtual ~FileSystemObjectsContainer() {}
};

#endif // !FILE_SYSTEM_OBJECTS_CONTAINER_H

