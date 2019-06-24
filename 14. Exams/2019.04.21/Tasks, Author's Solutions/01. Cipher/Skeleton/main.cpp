#include <iostream>
#include <string>
#include "Defines.h"

ErrorCode decryptMessage(const std::string & commands,
                         const char *        leftBufferData,
                         const size_t	   	 leftBufferSize,
                         const char *        rightBufferData,
                         const size_t	   	 rightBufferSize,
                         std::string &       outMessage);

void printResult(const ErrorCode     errorCode,
                 const std::string & decryptedMessage);

int main()
{
    std::string commands;
    std::string leftBuffer;
    std::string rightBuffer;
    std::string decryptedMessage;

    getline(std::cin, commands);
    getline(std::cin, leftBuffer);
    getline(std::cin, rightBuffer);

    const ErrorCode errorCode = decryptMessage(commands,
                                               leftBuffer.c_str(),
                                               leftBuffer.size(),
                                               rightBuffer.c_str(),
                                               rightBuffer.size(),
                                               decryptedMessage);

    printResult(errorCode, decryptedMessage);

    return 0;
}


