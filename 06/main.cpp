#include "format.h"
#include <iostream>
#include <cstdio>
#include <cassert>
#include <string>
#include <sstream>
using namespace std;


int main()
{
	//TEST 1 всё хорошо
	auto text = format("{1}+{1} = {0}", 2, "one");
	assert(text == "one+one = 2");	
	
	//TEST 2 всё хорошо
	auto text2 = format("{0}{1}{2} and some tea", "Spagetti ", "soda ", "pizza");
	assert(text2 == "Spagetti soda pizza and some tea");
	
	//TEST 3 всё хорошо
	auto text3 = format("bool is {0} or {1}", false, true);
	assert(text3 == "bool is false or true");
	
	//TEST 4 всё хорошо
	auto text4 = format("{0}{1}{2}{3}{4}{5}{6}", 0,1,2,3,4,5,6);
	assert(text4 == "0123456");

	//TEST 5 нет закрывающей скобки
	try
	{
		auto text5 = format("{0", 0);
	}
	catch (const myExc & err)
	{
		cout << "TEST 5 : " << err.getError() << endl;
	}
	
	//TEST 6 нет открывающей скобки
	try
	{
		auto text6 = format("}0", 0);
	}
	catch (const myExc & err)
	{
		cout << "TEST 6 : " << err.getError() << endl;
	}
	
	//TEST 7 неправильное выражение в скобках
	try
	{
		auto text5 = format("{a}", 0);
	}
	catch (const myExc & err)
	{
		cout << "TEST 7 : " << err.getError() << endl;
	}
	
	//TEST 8 подаём аргумент которого нет
	try
	{
		auto text8 = format("{0}{23}", 0, true, "sad");
	}
	catch (const myExc & err)
	{
		cout << "TEST 8 : " << err.getError() << endl;
	}
	
	cout << "OK" << endl;
	return 0;
}

