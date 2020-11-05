#include "bigint.h"
#include <iostream>
#include <cstdio>
#include <cassert>
#include <string>
using namespace std;

int main()
{
	//TEST1
	BigInt A1("1234289345723759832");
	BigInt test1("1234289345726103366");
	if (A1 + 2343534 != test1)
	{
		throw::runtime_error("TEST 1 : Wrong addition\n");
	}
	
	//TEST2
	BigInt A2("-123");
	BigInt test2("2343411");
	if (A2 + 2343534 != test2)
	{
		throw::runtime_error("TEST 2 : Wrong addition\n");
	}
	
	//TEST3
	BigInt A3("0");
	BigInt test3("-99");
	if (A3 - 99 != test3)
	{
		throw::runtime_error("TEST 3 : Wrong subtraction\n");
	}
	
	//TEST4
	BigInt A4("39048293840923849028999686796796796796794634");
	BigInt B4("4674321");
	BigInt test4("39048293840923849028999686796796796792120313");
	if (A4 - B4 != test4)
	{
		throw::runtime_error("TEST 4 : Wrong subtraction\n");
	}
	return 0;

	//TEST5
	BigInt A5("9876545678909875456787654");
	BigInt B5("9876545678909875456787654");
	if (A5 != B5)
	{
		throw::runtime_error("TEST 5 : Wrong work of unequal operator\n");
	}
	
	//TEST6
	BigInt A6("9876545678909875456787654");
	BigInt B6("1876545678909875456787654");
	if (A6 == B6)
	{
		throw::runtime_error("TEST 6 : Wrong work of equal operator\n");
	}
	
	//TEST7
	BigInt A7("423948209348923849023480932749823748");
	BigInt B7("-2304829038492384871987879999999999999999999");
	BigInt test7("-977128143724248446069807618082983990788691985328403043250390976519067250176252");
	if (A7 * B7 != test7)
	{
		throw::runtime_error("TEST 7 : Wrong work of multiplication\n");
	}
	
	//TEST8
	BigInt A8("324234");
	BigInt test8("0");
	if (A8 * 0 != test8)
	{
		throw::runtime_error("TEST 8 : Wrong work of multiplication\n");
	}
	
	//TEST9
	BigInt A9("2342");
	BigInt B9(A9);
	if (A9 != B9)
	{
		throw::runtime_error("TEST 9 : Copy constructor doesn't work\n");
	}
	
	//TEST10
	BigInt A10("234");
	BigInt B10 = move(A10);
	BigInt test10("234");
	if (B10 != test10)
	{
		throw::runtime_error("TEST 10 : Move constructor doesn't work\n");
	}
	
	//TEST11
	BigInt A11("3");
	BigInt test11("-3");
	if (-A11 != test11)
	{
		throw::runtime_error("TEST 11 : Wrong work of minus\n");
	} 
}

