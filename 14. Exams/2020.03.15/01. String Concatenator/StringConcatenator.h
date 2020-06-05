#ifndef STRINGCONCATENATOR_H_
#define STRINGCONCATENATOR_H_

#include <string>

#include "Defines.h"

class StringConcatenator
{
	public:
		StringConcatenator();
		~StringConcatenator();

		std::string concatenate(const ConcatenateStrategy strategy,
								const char * 			  left,
								const size_t 			  leftSize,
								const char * 			  right,
								const size_t 		      rightSize) const;
};

#endif /* STRINGCONCATENATOR_H_ */
