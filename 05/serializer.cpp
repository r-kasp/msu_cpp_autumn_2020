#include "serializer.h"
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

bool isNumber(const string &s)
{
	bool res = true;
	for (int i = 0; i < s.size(); i++)
		if (!isdigit(s[i]))
		{
			res = false;
			break;
		}
	return res;
}
