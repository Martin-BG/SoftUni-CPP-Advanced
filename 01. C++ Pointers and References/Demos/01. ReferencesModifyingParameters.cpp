#include <iostream>
#include <string>
#include <list>

void swap(int& a, int& b) {
	int oldA = a;
	a = b;
	b = oldA;
}

void removeNegative(std::list<int>& numbers) {
	auto i = numbers.begin();
	while (i != numbers.end()) {
		if (*i < 0) {
			i = numbers.erase(i);
		}
		else {
			i++;
		}
	}
}

int main() {
	using namespace std;

	int x = 13, y = 42;
	swap(x, y); // x == 42, y == 13
	cout << x << " " << y << endl;

	list<int> values{ 1, -69, -4, 42, -2, 13, -9 };
	removeNegative(values); // values{ 1, 42, 13 };

	for (int v : values) {
		cout << v << " ";
	}
	cout << endl;

	return 0;
}
