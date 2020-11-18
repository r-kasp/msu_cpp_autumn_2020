#include "format.h"
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

bool isNumber(const string &s, int &a)
{
	bool res = true;
	a = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (!isdigit(s[i]))
		{
			res = false;
			break;
		}
		else
		{
			a = a*10 + s[i] - '0';
		}
	}
	return res;
}
