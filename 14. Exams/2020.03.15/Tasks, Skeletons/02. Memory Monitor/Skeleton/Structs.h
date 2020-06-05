#ifndef STRUCTS_H_
#define STRUCTS_H_

struct MemoryNode
{
	MemoryNode() : data(nullptr), size(0)
	{

	}

	int * data;
	int   size;
};

#endif /* STRUCTS_H_ */
