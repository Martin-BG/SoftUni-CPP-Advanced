#include "StringConcatenator.h"

enum InternalDefines
{
	SINGLE_CHAR = 1,
	DOUBLE_CHAR = 2
};

StringConcatenator::StringConcatenator()
{

}

StringConcatenator::~StringConcatenator()
{

}

std::string StringConcatenator::concatenate(
									const ConcatenateStrategy strategy,
									const char * 			  left,
									const size_t 			  leftSize,
									const char * 			  right,
									const size_t 		      rightSize) const
{
	std::string result;
	result.reserve(leftSize + rightSize);

	const int LEFT_CHARS = ((ConcatenateStrategy::LEFT_1_RIGHT_1 == strategy) ||
							(ConcatenateStrategy::LEFT_1_RIGHT_2 == strategy)) ?
													 SINGLE_CHAR : DOUBLE_CHAR;

	const int RIGHT_CHARS = (ConcatenateStrategy::LEFT_1_RIGHT_2 == strategy) ?
													 DOUBLE_CHAR : SINGLE_CHAR;

	size_t leftProccessedChars = 0;
	size_t rightProccessedChars = 0;

	while((leftProccessedChars != leftSize) ||
		  (rightProccessedChars != rightSize))
	{
		for(int i = 0; i < LEFT_CHARS; ++i)
		{
			if(leftProccessedChars == leftSize)
			{
				break;
			}

			result.push_back(left[leftProccessedChars]);
			++leftProccessedChars;
		}

		for(int i = 0; i < RIGHT_CHARS; ++i)
		{
			if(rightProccessedChars == rightSize)
			{
				break;
			}

			result.push_back(right[rightProccessedChars]);
			++rightProccessedChars;
		}
	}

	return result;
}

