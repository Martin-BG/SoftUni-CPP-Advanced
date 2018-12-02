#include "UnitPtr.h"

std::map<T*, int> UnitPtr::refCount;

UnitPtr::UnitPtr() : pointer(nullptr) {
	refCount[nullptr]++;
}

UnitPtr::UnitPtr(T* rawPointer) : pointer(rawPointer) {
	refCount[rawPointer]++;
}

UnitPtr UnitPtr::from(T* rawPointer) {
	return UnitPtr(rawPointer);
}

UnitPtr::UnitPtr(const UnitPtr& other) : pointer(other.pointer) {
	refCount[other.pointer]++;
}

T& UnitPtr::operator*() {
	return *(this->pointer);
}

T* UnitPtr::operator->() const {
	return this->pointer;
}

UnitPtr& UnitPtr::operator=(const UnitPtr& other) {
	if (this != &other) {
		refCount[this->pointer]--;
		if (refCount[this->pointer] == 0 && this->pointer != nullptr) {
			delete this->pointer;
		}

		this->pointer = other.pointer;
		this->refCount[this->pointer]++;
	}

	return *this;
}

UnitPtr::~UnitPtr() {
	refCount[this->pointer]--;

	if (refCount[this->pointer] == 0 && this->pointer != nullptr) {
		delete this->pointer;
	}
}