#include "parser.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

void Fstr(string &s, vector<string> &v)
{
	v.push_back(s); 
}

void Fdigit(int n, vector<int> &v)
{
	v.push_back(n);
}

void Fstart(string &s)
{
	cout << s << endl;
}

void Ffinish(string &s)
{
	cout << s << endl;
}

