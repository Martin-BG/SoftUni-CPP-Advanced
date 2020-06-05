#include <string>
#include <iostream>
#include <sstream>
#include "Defines.h"

ErrorCode decryptMessage(const std::string& commands,
                         const char* leftBufferData,
                         const size_t leftBufferSize,
                         const char* rightBufferData,
                         const size_t rightBufferSize,
                         std::string& outMessage) {

  if (commands.empty()) {
    return DECRYPT_EMPTY;
  }
  std::ostringstream result;
  for (size_t i = 0; i < commands.length() - 1;) {
    char command = commands[i++];
    size_t index = commands[i++] - '0';
    if (command == 'r' && index < rightBufferSize) {
      result << rightBufferData[index];
    } else if (command == 'l' && index < leftBufferSize) {
      result << leftBufferData[index];
    } else {
      outMessage = result.str();
      return DECRYPT_FAILURE;
    }
  }
  outMessage = result.str();
  return DECRYPT_SUCCESS;
};

void printResult(const ErrorCode errorCode,
                 const std::string& decryptedMessage) {
  std::string result{ };
  switch (errorCode) {
  case DECRYPT_SUCCESS:
    result = decryptedMessage;
    break;
  case DECRYPT_FAILURE:
    result = decryptedMessage + " Warning, buffer out-of-bound detected";
    break;
  case DECRYPT_EMPTY:
    result = "No input provided";
    break;
  }
  std::cout << result << std::endl;
};
