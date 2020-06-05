#ifndef DEFINES_H_
#define DEFINES_H_

enum ErrorCode
{
    REQUEST_SUCCESS                    = 0,
	REQUEST_FAILURE_NOT_ENOUGH_MEMORY  = 1,
    REQUEST_FAILURE_BIGGER_THAN_BUFFER = 2
};

enum InputCommands
{
	REQUEST_MEMORY       = 0,
	RELEASE_MEMORY       = 1,
	ZERO_MEMORY    		 = 2,
	SUM_NODE_DATA        = 3,
	INCR_NODE_DATA_VALUE = 4
};

#endif /* DEFINES_H_ */
