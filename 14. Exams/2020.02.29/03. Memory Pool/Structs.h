#ifndef STRUCTS_H_
#define STRUCTS_H_

struct MemoryNode
{
	MemoryNode() : memory(nullptr),
				   size(0),
				   bufferStartIndex(-1)
	{

	}

	int * memory;
	int   size;
	int   bufferStartIndex;
};



#endif /* STRUCTS_H_ */
