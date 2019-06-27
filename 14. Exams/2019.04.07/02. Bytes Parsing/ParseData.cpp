#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include "Defines.h"

ErrorCode parseData(const std::string& commands,
                    const char* rawDataBytes,
                    const size_t rawDataBytesCount,
                    std::vector<long long>& outParsedNumbers) {
  if (commands.length() == 0 ||
      rawDataBytesCount == 0 ||
      rawDataBytes == nullptr) {
    return PARSE_EMPTY;
  }

  size_t dataIndex = 0;
  for (const auto command : commands) {
    size_t dataSize = 0;

    switch (command) {
    case 's':
      dataSize = 2;
      break;
    case 'i':
      dataSize = 4;
      break;
    case 'l':
      dataSize = 8;
      break;
    default:
      break;
    }

    if ((dataIndex + dataSize) > rawDataBytesCount) {
      return PARSE_FAILURE;
    }

    long long number = 0LL;
    std::memcpy(&number, &rawDataBytes[dataIndex], dataSize);
    outParsedNumbers.emplace_back(number);

    dataIndex += dataSize;
  }

  return PARSE_SUCCESS;
}

void printResult(const ErrorCode errorCode,
                 const std::vector<long long>& parsedNumbers) {
  switch (errorCode) {
  case PARSE_EMPTY:
    std::cout << "No input provided" << std::endl;
    break;
  case PARSE_SUCCESS:
    for (const auto num : parsedNumbers) {
      std::cout << num << " ";
    }
    std::cout << std::endl;
    break;
  case PARSE_FAILURE:
    for (const auto num : parsedNumbers) {
      std::cout << num << " ";
    }
    std::cout << "Warning, buffer underflow detected" << std::endl;
    break;
  }
}
