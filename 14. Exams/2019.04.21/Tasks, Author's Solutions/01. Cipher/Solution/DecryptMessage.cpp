#include <iostream>
#include <string>
#include "Defines.h"

ErrorCode decryptMessage(const std::string & commands,
                         const char *        leftBufferData,
                         const size_t	   	 leftBufferSize,
                         const char *        rightBufferData,
                         const size_t	   	 rightBufferSize,
                         std::string &       outMessage)
{
    if(commands.empty())
    {
        return ErrorCode::DECRYPT_EMPTY;
    }

    const size_t SIZE = commands.size();
    outMessage.reserve(SIZE);

    for(size_t i = 0; i < SIZE; i += 2)
    {
        const size_t index = commands[i + 1] - '0';

        if('l' == commands[i])
        {
            if(index >= leftBufferSize)
            {
                return ErrorCode::DECRYPT_FAILURE;
            }

            outMessage.push_back(leftBufferData[index]);
        }
        else if('r' == commands[i])
        {
            if(index >= rightBufferSize)
            {
                return ErrorCode::DECRYPT_FAILURE;
            }

            outMessage.push_back(rightBufferData[index]);
        }
        else
        {
            std::cerr << "Unknown buffer destination: "
                      << commands[i] << std::endl;
        }
    }

    return ErrorCode::DECRYPT_SUCCESS;
    }

void printResult(const ErrorCode     errorCode,
        		 const std::string & decryptedMessage)
{
    std::cout << decryptedMessage;

    switch(errorCode)
    {
        case ErrorCode::DECRYPT_EMPTY:
            std::cout << "No input provided";
            break;

        case ErrorCode::DECRYPT_FAILURE:
            std::cout << " Warning, buffer out-of-bound detected";
            break;

        case ErrorCode::DECRYPT_SUCCESS:
            //do nothing
            break;

        default:
            std::cerr << "Warning, received unknown ErrorCode: " << errorCode;
            break;
    }

    std::cout << std::endl;
}


