#ifndef FORMAT_H
#define FORMAT_H
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

bool isNumber(const string &s, int &a);

enum class Error
{
	NoError,
	WrongStr,
	AllocErr
};

template <class T>
Error build(vector <string> & vec, T && arg)
{
	stringstream out;
	out << boolalpha << arg; 	
	vec.push_back(out.str());
	return Error::NoError;
}


template <class T, class... ArgsT>
Error build(vector <string> & vec, T && arg, ArgsT&&... args)
{
	Error err;
	err = build(vec, arg);
	err = build(vec, forward<ArgsT>(args)...);
	return Error::NoError;
}


template<class... ArgsT>
string format(const string & text, ArgsT&&... args)
{
	string res = "";
	vector <string> vec;
	Error err = build(vec, forward<ArgsT>(args)...);
	int len = text.size();
	int sz = vec.size();
	int flag = 0;
	if (len == 0)
		return res;
	if (text[0] == '}')
		throw::runtime_error("Wrong usage of }\n");
	string cur;
	for (int i = 0; i < len; i++)
	{
		if (flag == 0)
		{
			if (text[i] == '}')
				throw::runtime_error("Wrong usage of }\n");
			else if (text[i] == '{')
			{
				cur = "";
				flag = 1;
			}
			else
				res += text[i];
		}
		else
		{
			if (text[i] == '}')
			{
				int num;
				try
				{
					num = stoull(cur);	
				}
				catch (const exception & invalid_value)
				{
					throw::runtime_error("Wrong number of arguement\n");
				}
				if (num >= sz)
					throw::runtime_error("So large number of arg\n");
				res += vec[num];
				flag = 0;
			}
			else
			{
				cur += text[i];
			}
		}
	} 
	return res;
} 

#endif
