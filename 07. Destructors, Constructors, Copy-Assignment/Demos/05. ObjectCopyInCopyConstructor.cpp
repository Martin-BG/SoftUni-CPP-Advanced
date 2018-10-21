#include <string>
#include <iostream>

struct Lecturer {
	double rating;
	std::string name;

	Lecturer(std::string name, double rating)
		: name(name), rating(rating) {}

	Lecturer(const Lecturer& other) {
		*this = other;
	}

	Lecturer& operator=(Lecturer other) {
		this->name = other.name;
		this->rating = other.rating;
		return *this;
	}

/*	// Fixed code to avoid self-calling recursion
	Lecturer& operator=(const Lecturer& other) {
		if (this != &other) {
			this->name = other.name;
			this->rating = other.rating;
		}
		return *this;
	}*/
};

int main() {
	Lecturer a("Bill", 4.2);
	Lecturer other(a);

	std::cout << other.name << std::endl;

	return 0;
}