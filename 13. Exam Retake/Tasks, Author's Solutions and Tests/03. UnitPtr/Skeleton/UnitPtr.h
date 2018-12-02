#ifndef UNIT_PTR_H
#define UNIT_PTR_H

#include <map>
#include "Unit.h"

typedef Unit T;

class UnitPtr {
	static std::map<T*, int> refCount;
	T* pointer;

	UnitPtr(T* rawPointer);
public:
	UnitPtr();

	static UnitPtr from(T* rawPointer);

	UnitPtr(const UnitPtr& other);

	T& operator*();

	T* operator->() const;

	UnitPtr& operator=(const UnitPtr& other);

	~UnitPtr();
};

#endif // !UNIT_PTR_H

