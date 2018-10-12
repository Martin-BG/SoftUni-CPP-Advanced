#include<iostream>

#include "BigInt.h"

int getSumOfDigits(const std::string&);

BigInt getFirstNumber(const std::string& numStr);

int main() {
  std::string startNumStr, endNumStr;
  std::cin >> startNumStr >> endNumStr;

  BigInt currentNum = getFirstNumber(startNumStr);
  const BigInt endNum(endNumStr);
  const BigInt fortyFive(45);

  while (currentNum < endNum) {
    std::cout << currentNum << std::endl;
    currentNum += fortyFive;
  }

  return 0;
}

BigInt getFirstNumber(const std::string& numStr) {
  BigInt firstNumber(numStr);

  const int endDigit = numStr[numStr.size() - 1] - '0';
  if (endDigit != 0 && endDigit != 5) {
    if (endDigit > 5) {
      firstNumber += BigInt(10 - endDigit);
    } else {
      firstNumber += BigInt(5 - endDigit);
    }
  }

  const BigInt five(5);

  int sumOfDigits = getSumOfDigits(firstNumber.getDigits());
  while (sumOfDigits % 9 != 0) {
    firstNumber += five;
    sumOfDigits = getSumOfDigits(firstNumber.getDigits());
  }

  return firstNumber;
}

int getSumOfDigits(const std::string& digits) {
  int sum = 0;
  for (char digit : digits) {
    sum += digit - '0';
  }
  return sum;
}
