#include <cstdio>

class Allocator
{
private:
	int offset = 0;
	int memsize = 0;
	char* mem;
public:
	void MakeAllocator(size_t );
	char* alloc(size_t );
	void reset();
	Allocator();
	~Allocator();
	int get_offset()
	{
		return offset;
	}
	char* get_mem()
	{
		return mem;
	}
	int get_size()
	{
		return memsize;
	}
	
};
