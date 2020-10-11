#include "allocator.h"

Allocator::Allocator()
{
	mem = nullptr;
	offset = 0;
	memsize = 0;
}

Allocator::~Allocator()
{
	offset = 0;
	memsize = 0;
	if (mem != nullptr)
	{
		delete [] mem;
		mem = nullptr;
	}
}

void Allocator::MakeAllocator(size_t maxSize)
{
	if (mem != nullptr)
	{
		delete [] mem;
		mem = nullptr;
	}
	mem = new char[maxSize];
	memsize = maxSize;
	offset = 0;
}

char* Allocator::alloc(size_t size)
{
	if (offset + size > memsize)
		return nullptr;
	offset += size;
	return mem+(offset-size);
}

void Allocator::reset()
{
	offset = 0;
}

