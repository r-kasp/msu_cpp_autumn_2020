#include "parser.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	function<void(string &s)> fstart = &Fstart;
	function<void(string &s)> ffinish = &Ffinish;
	function<void(int n, vector<int> &v)> fdigit = &Fdigit;
	function<void(string &s, vector<string> &v)> fstring = &Fstr;
	Parser A;
	A.SetStartCallback(fstart);
	A.SetFinishCallback(ffinish);
	A.SetDigitTokenCallback(fdigit);
	A.SetStingTokenCallback(fstring);
	
	vector<string> a;
	vector<int>b;
	
	//TEST 1
	a.clear(); b.clear();
	string s = "asd 123";
	A.TokenParser(s,a,b);
	bool test1 = (a.size() == 1 && b.size() == 1 && a[0] == "asd" && b[0] == 123); 
	if (!test1)
		throw std::runtime_error("Test 1: Wrong parsing");
	cout << endl;
	
	//TEST 2 
	a.clear(); b.clear();
	s = "Рублёвые пакеты что-то подорожали...";
	A.TokenParser(s,a,b);
	bool test2 = (a.size() == 4 && b.size() == 0 && a[0] == "Рублёвые" 
				&& a[1] == "пакеты" && a[2] == "что-то" && a[3] == "подорожали...");
	if (!test2)
		throw std::runtime_error("Test 2: Wrong parsing");
	cout << endl;
	
	//TEST 3
	a.clear(); b.clear();
	s = "sdkjfhsdlflkshfkjlashdjflhiuqw djkshfjkasdh\nflkad!! sdkjfhsjdkfhjkd asdqwdqwd!!!";
	A.TokenParser(s,a,b);
	bool test3 = (a.size() == 5 && b.size() == 0 && a[0] == "sdkjfhsdlflkshfkjlashdjflhiuqw" 
				&& a[1] == "djkshfjkasdh" && a[2] == "flkad!!" 
				&& a[3] == "sdkjfhsjdkfhjkd" && a[4] == "asdqwdqwd!!!");
	if (!test3)
		throw std::runtime_error("Test 3: Wrong parsing");
	cout << endl;

	//TEST 4
	a.clear(); b.clear();
	s = "Звоните нам! 88005535	Мы поставим табуляцию!";	
	A.TokenParser(s,a,b);
	bool test4 = (a.size() == 5 && b.size() == 1 && b[0] == 88005535 
				&& a[0] == "Звоните" && a[1] == "нам!" && a[2] == "Мы" 
				&& a[3] == "поставим" && a[4] == "табуляцию!");
	if (!test4)
		throw std::runtime_error("Test 4: Wrong parsing");
	cout << endl;
	
	//TEST 5 специальный случай, когда идут подряд несколько пробельных символов 
	a.clear(); b.clear();
	s = "1 2\n3	4 \n5	\n 6  7";
	A.TokenParser(s,a,b);
	bool test5 = (a.size() == 0 && b.size() == 7 && b[0] == 1 
				&& b[1] == 2 && b[2] == 3 && b[3] == 4 && b[4] == 5 
				&& b[5] == 6 && b[6] == 7); 
	if (!test5)
		throw std::runtime_error("Test 5: Wrong parsing");
	cout << endl;
	return 0;
}
