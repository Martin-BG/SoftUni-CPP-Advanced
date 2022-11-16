#include <iostream>

bool isPrime(int number) {
  if (number < 1) {
    return false;
  }

  for (int i = 2; i <= number / 2; i++) {
    if (number % i == 0) {
      return false;
    }
  }

  return true;
}

int main() {
  size_t size;
  std::cin >> size;
  int sum{0};

  for (size_t row = 0; row < size; ++row) {
    for (size_t col = 0; col < size; ++col) {
      int currentNum;
      std::cin >> currentNum;
      if (size - row <= col && row > col && isPrime(currentNum)) {
        sum += currentNum;
      }
    }
  }

  std::cout << sum << std::endl;

  return 0;
}
