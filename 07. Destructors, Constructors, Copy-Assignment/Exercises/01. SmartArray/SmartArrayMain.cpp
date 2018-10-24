#include <iostream>
#include "SmartArray.h"

int main() {
  SmartArray<int> a(3);
  a[0] = 34;
  a[1] = 42;
  a[2] = 56;

  std::cout << a << std::endl;

  a.resize(20);
  std::cout << a << std::endl;

  a.resize(10);
  std::cout << a << std::endl;

  SmartArray<int> b;
  b = a;

  SmartArray<int> c(a);

  a[7] = 66;
  std::cout << a << std::endl;

  b[9] = 44;
  std::cout << b << std::endl;

  c[8] = 77;
  std::cout << c << std::endl;

  SmartArray<int> d{ 4, 5, 1, 34, 55, 67, 98, -123 };
  std::cout << d.getSize() << " : " << d << std::endl;

  SmartArray<std::string> s{ "hi", "there", "!" };
  std::cout << s.getSize() << " : " << s << std::endl;

  s[0] = "bye";
  s.resize(4);
  s[3] = "<<<>>>";
  std::cout << s.getSize() << " : " << s << std::endl;

  return 0;
}
