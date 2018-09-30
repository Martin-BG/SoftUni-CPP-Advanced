#include <sstream>
#include "Fraction.h"

int main() {
  using namespace MyFraction;
  using std::cin;
  using std::cout;
  using std::endl;
  using std::boolalpha;

  Fraction a(1, 3), b(4, 5), c(a);
//  Fraction a, b, c;
//  cin >> a >> b >> c;
  cout << a << ", " << b << ", " << c << endl;

  cout << a << " == " << b << " : " << boolalpha << (a == b) << endl;
  cout << b << " == " << a << " : " << boolalpha << (b == a) << endl;
  cout << a << " == " << c << " : " << boolalpha << (a == c) << endl;

  cout << a << " != " << b << " : " << boolalpha << (a != b) << endl;
  cout << b << " != " << a << " : " << boolalpha << (b != a) << endl;
  cout << a << " != " << c << " : " << boolalpha << (a != c) << endl;

  cout << a << " < " << b << " : " << boolalpha << (a < b) << endl;
  cout << b << " < " << a << " : " << boolalpha << (b < a) << endl;
  cout << a << " < " << c << " : " << boolalpha << (a < c) << endl;

  cout << a << " <= " << b << " : " << boolalpha << (a <= b) << endl;
  cout << b << " <= " << a << " : " << boolalpha << (b <= a) << endl;
  cout << a << " <= " << c << " : " << boolalpha << (a <= c) << endl;

  cout << a << " > " << b << " : " << boolalpha << (a > b) << endl;
  cout << b << " > " << a << " : " << boolalpha << (b > a) << endl;
  cout << a << " > " << c << " : " << boolalpha << (a > c) << endl;

  cout << a << " >= " << b << " : " << boolalpha << (a >= b) << endl;
  cout << b << " >= " << a << " : " << boolalpha << (b >= a) << endl;
  cout << a << " >= " << c << " : " << boolalpha << (a >= c) << endl;

  cout << a << " + " << b << " = " << a + b << endl;
  cout << a << " + " << c << " = " << a + c << endl;
  cout << a << " - " << b << " = " << a - b << endl;
  cout << a << " - " << c << " = " << a - c << endl;
  cout << a << " * " << b << " = " << a * b << endl;
  cout << a << " * " << c << " = " << a * c << endl;
  cout << a << " / " << b << " = " << a / b << endl;
  cout << a << " / " << c << " = " << a / c << endl;

  cout << a << "++ " << " -> " << a++ << " (" << a << ")" << endl;
  cout << "++" << a << " -> " << ++a << " (" << a << ")" << endl;
  cout << a << "-- " << " -> " << a-- << " (" << a << ")" << endl;
  cout << "--" << a << " -> " << --a << " (" << a << ")" << endl;
  cout << "--" << c << " -> " << --c << " (" << c << ")" << endl;

  cout << a << " += " << b << " -> " << (a += b) << endl;
  cout << a << " -= " << b << " -> " << (a -= b) << endl;
  cout << a << " *= " << b << " -> " << (a *= b) << endl;
  cout << a << " /= " << b << " -> " << (a /= b) << endl;

  return 0;
}
