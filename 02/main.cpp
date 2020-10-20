#include "parser.h"
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
	void (*fstart)(string&) = &Fstart;
	void (*ffinish)(string&) = &Ffinish;
	void (*fdigit)(int) = &Fdigit;
	void (*fstring)(string&) = &Fstr;
	Parser A;
	A.SetStartCallback(*fstart);
	A.SetFinishCallback(*ffinish);
	A.SetDigitTokenCallback(*fdigit);
	A.SetStingTokenCallback(*fstring);
	
	//TEST 1
	
	string s = "asd 123";
	int test1 = A.TokenParser(s);
	if (test1 != 0)
		throw std::runtime_error("Test 1: Can't parse a string");
	cout << endl;
	
	//TEST 2 
	s = "Рублевые пакеты что-то подорожали...";
	int test2 = A.TokenParser(s);
	if (test2 != 0)
		throw std::runtime_error("Test 2: Can't parse a string");
	cout << endl;
	
	//TEST 3
	s = "sdkjfhsdlflkshfkjlashdjflhiuqw djkshfjkasdh\nflkad!! sdkjfhsjdkfhjkd s wfwe we we fwe wefwe asdqwdqwd!!!";
	int test3 = A.TokenParser(s);
	if (test3 != 0)
		throw std::runtime_error("Test 3: Can't parse a string");
	cout << endl;
	
	//TEST 4
	s = "Надоело сидеть дома на карантине? Звоните нам! 88005535	Мы поставили табуляцию! Мы скрасим ваш вечер!";	
	int test4 = A.TokenParser(s);
	if (test4 != 0)
		throw std::runtime_error("Test 4: Can't parse a string");
	cout << endl;
	
	return 0;
}
