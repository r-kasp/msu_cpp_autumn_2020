#include "format.h"
#include <iostream>
#include <cstdio>
#include <cassert>
#include <string>
#include <sstream>
using namespace std;


int main()
{
	//TEST 1
	auto text = format("{1}+{1} = {0}", 2, "one");
	assert(text == "one+one = 2");	
	
	//TEST 2
	auto text2 = format("{0}{1}{2} and some tea", "Spagetti ", "soda ", "pizza");
	assert(text2 == "Spagetti soda pizza and some tea");
	
	//TEST 3
	auto text3 = format("bool is {0} or {1}", false, true);
	assert(text3 == "bool is false or true");
	
	//TEST 4
	auto text4 = format("{0}{1}{2}{3}{4}{5}{6}", 0,1,2,3,4,5,6);
	assert(text4 == "0123456");

	cout << "OK" << endl;
	return 0;
}

