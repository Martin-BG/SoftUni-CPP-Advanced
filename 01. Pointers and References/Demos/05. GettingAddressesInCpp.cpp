#include<iostream>
#include<cmath>

void f() {
}

int main() {
	using namespace std;

	int x = 42;
	auto addressX = &x;
	cout << x << " at " << addressX << endl;

	cout << "f()" << " code at " << &f << endl;
	cout << "f()" << " code at " << (void*)&f << endl; // Use (void*) to print function address

	// NOTE: there are different abs functions (int, double...), so we specify we want the one returning double and accepting 1 double parameter
	double(&absAddress)(double) = abs;
	cout << "abs(double)" << " code at " << absAddress << endl;
	cout << "abs(double)" << " code at " << (void*)absAddress << endl; // Use (void*) to print function address

	return 0;
}
