#include "matrix.h"
#include <iostream>
#include <cstdio>
#include <cassert>
using namespace std;

int main()
{
	Matrix arr(2,2);
	//TEST 1
	if (arr.get_rows() != 2)
	{
		throw std::runtime_error("Test 1: Wrong size of first dimension");
	}
	
	//TEST 2
	if (arr.get_rows() != 2)
	{
		throw std::runtime_error("Test 2: Wrong size of second dimension");
	}
	
	//TEST 3
	arr[0][0] = 1;
	arr[0][1] = 2;
	arr[1][0] = 3;
	arr[1][1] = 4; 
	
	if (arr[0][0] != 1 || arr[0][1] != 2 || arr[1][0] != 3 || arr[1][1] != 4)
	{
		throw std::runtime_error("Test 3: Wrong initialization");
	}
	cout << "TEST 3: initialization is OK " << endl;
	cout << arr << endl;
	
	//TEST 4
	arr *= 2;
	if (arr[0][0] != 2 || arr[0][1] != 4 || arr[1][0] != 6 || arr[1][1] != 8)
	{
		throw std::runtime_error("Test 4: Wrong multiplication");
	}
	
	//TEST 5
	Matrix arr2(2,2);
	if (!(arr != arr2))
	{
		throw std::runtime_error("Test 5: Wrong work of operator !=");
	}
	
	//TEST 6
	arr2[0][0] = 2;
	arr2[0][1] = 4;
	arr2[1][0] = 6;
	arr2[1][1] = 8;
	if (!(arr == arr2))
	{
		throw std::runtime_error("Test 6: Wrong work of operator ==");
	}
	
	
	//TEST 7
	
	Matrix arr3(2,2);
	arr3 = arr + arr2;
	if (arr3[0][0] != 4 || arr3[0][1] != 8 || arr3[1][0] != 12 || arr3[1][1] != 16)
	{
		throw std::runtime_error("Test 7: Wrong addition");
	}
	cout << "TEST 7: OK" << endl;
	cout << arr3 << endl;
	return 0;
}
