#include "allocator.h"
#include <cstdio>
#include <iostream>

int main()
{
	Allocator allocator;
	allocator.MakeAllocator(3);
	
	
	//CHECK THE WORK OF alloc
	char* test1 = allocator.alloc(3);
	if (test1 == nullptr)
		throw std::runtime_error("Test 1: Can't get an allocate memory");
	
	char* test2 = allocator.alloc(1);
	if (test2 != nullptr)
		throw std::runtime_error("Test 2: Allocate more memory that we have");
	
	//CHECK THE WORK OF reset
	allocator.reset();
	
	char* test3 = allocator.alloc(1);
	if (test3 == nullptr)
		throw std::runtime_error("Test 3: Allocate more memory that we have");
		
	allocator.reset();
	
	char* mem1 = allocator.get_mem();
	char* test4 = allocator.alloc(0);
	if (test4 != mem1)
		throw std::runtime_error("Test 4: Wrong work of alloc");
		
	char* test5 = allocator.alloc(1);
	if (test5 == mem1 + 1)
		throw std::runtime_error("Test 5: Wrong work of alloc");
	
	//CHECK AGAIN THE WORK OF MakeAllocator
	
	allocator.MakeAllocator(3);
	
	char* test6 = allocator.alloc(3);
	if (test6 == nullptr)
		throw std::runtime_error("Test 6: Can't get an allocate memory");
	
	return 0;
}
