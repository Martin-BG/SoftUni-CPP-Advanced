#include <iostream>

int main() {
  size_t size;
  std::cin >> size;
  int sum{0};

  for (size_t row = 0; row < size; ++row) {
    for (size_t col = 0; col < size; ++col) {
      int currentNum;
      std::cin >> currentNum;
      if (row != col && size - row - 1 != col && currentNum % 2 != 0) {
        sum += currentNum;
      }
    }
  }

  std::cout << "The sum is: " << sum << std::endl;

  return 0;
}
