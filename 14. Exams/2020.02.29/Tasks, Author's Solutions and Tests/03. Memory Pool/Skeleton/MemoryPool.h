#ifndef MEMORYPOOL_H_
#define MEMORYPOOL_H_

#include "Defines.h"
#include "Structs.h"

class MemoryPool
{
	public:
		MemoryPool(const int memoryPoolSize);
		virtual ~MemoryPool();

		ErrorCode requestMemory(MemoryNode & outNode);

		void releaseMemory(const MemoryNode & outNode);

		void zeroMemoryValue(const MemoryNode & node);

	private:
		void occupyMemory(const MemoryNode & node);

		int *     _memoryBuffer;

		bool *    _isMemoryBufferOccupied;

		const int _MEMORY_POOL_SIZE;
};

#endif /* MEMORYPOOL_H_ */
