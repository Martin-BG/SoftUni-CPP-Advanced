#include <sstream>
#include "Fraction.h"

int main() {
  using namespace MyFraction;
  using std::cin;
  using std::cout;
  using std::endl;

  Fraction a(1, 3), b(4, 5);
//  Fraction a, b;
//  cin >> a >> b;
  cout << a << endl << b << endl;

  cout << a << " == " << b << " : " << std::boolalpha << (a == b) << endl;
  cout << a << " < " << b << " : " << std::boolalpha << (a < b) << endl;
  cout << a << " <= " << b << " : " << std::boolalpha << (a <= b) << endl;
  cout << a << " > " << b << " : " << std::boolalpha << (a > b) << endl;
  cout << a << " >= " << b << " : " << std::boolalpha << (a >= b) << endl;

  cout << a << " + " << b << " = " << a + b << endl;
  cout << a << " - " << b << " = " << a - b << endl;
  cout << a << " * " << b << " = " << a * b << endl;
  cout << a << " / " << b << " = " << a / b << endl;

  cout << a << "++ " << " -> " << a++ << endl;
  cout << "++" << a << " -> " << ++a << endl;
  cout << a << "-- " << " -> " << a-- << endl;
  cout << "--" << a << " -> " << --a << endl;

  cout << a << " += " << b << " -> " << (a += b) << endl;
  cout << a << " -= " << b << " -> " << (a -= b) << endl;
  cout << a << " *= " << b << " -> " << (a *= b) << endl;
  cout << a << " /= " << b << " -> " << (a /= b) << endl;

  return 0;
}
