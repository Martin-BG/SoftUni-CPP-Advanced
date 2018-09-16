#include <iostream>
#include <vector>
#include <ostream>

template<typename T>
std::ostream& operator<<(std::ostream& stream, const std::vector<T>& v) {
	for (T item : v) {
		stream << item << " ";
	}

	return stream;
}

std::vector<int> filter(std::vector<int> numbers, bool(*shouldFilter)(int)) {
	std::vector<int> filtered;


	for (int n : numbers) {
		if (shouldFilter(n)) {
			filtered.push_back(n);
		}
	}

	return filtered;
}

bool isEven(int number) {
	return number % 2 == 0;
}

int main() {
	using namespace std;

	cout << filter({ 1, 2, 3, 4, 5, 6, 7 }, [](int n) {
		return n > 3;
	}) << endl;

	cout << filter({ 1, 2, 3, 4, 5, 6, 7 }, isEven) << endl;

	cout << filter({ 1, -2, 3, 4, -5, 6, -7 }, [](int n) {
		return n < 0;
	}) << endl;

	return 0;
}
