#include <iostream>
#include <string>

class IntArray {
	int* data;
	int size;
public:
	IntArray(int size) : data(new int[size]), size(size) {}

	~IntArray() {
		delete[] this->data;
	}

	IntArray(const IntArray& other) {
		this->resetData(other.data, other.size);
	}

	IntArray& operator=(const IntArray& other) {
		this->resetData(other.data, other.size);
		return *this;
	}

	int getSize() const {
		return this->size;
	}

	int& operator[](const int index) const {
		return this->data[index];
	}

private:
	void resetData(int* otherData, int otherSize) {
		int* copyData = new int[otherSize];

		if (this->data != nullptr) {
			delete[] this->data;
		}

		for (int i = 0; i < otherSize; i++) {
			copyData[i] = otherData[i];
		}

		this->data = copyData;
		this->size = otherSize;
	}
};

int main() {
	IntArray arr(10);
	arr[0] = 42;
	arr = arr;
	std::cout << arr[0] << std::endl;

	return 0;
}
