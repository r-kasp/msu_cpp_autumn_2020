#ifndef FORMAT_H
#define FORMAT_H
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class myExc
{
private:
	string myerror;
public:
	myExc(const string & error) : myerror(error)
    	{
    	}
    	const char * getError() const noexcept
    	{ 
    		return myerror.c_str(); 
    	}
};

bool isNumber(const string &s, int &a);

enum class Error
{
	NoError,
	WrongStr,
	AllocErr
};

template <class T>
Error build(vector <string> & vec, const T & arg)
{
	stringstream out;
	out << boolalpha << arg; 	
	vec.push_back(out.str());
	return Error::NoError;
}


template <class T, class... ArgsT>
Error build(vector <string> & vec, const T & arg, const ArgsT&... args)
{
	Error err;
	err = build(vec, arg);
	err = build(vec, args...);
	return Error::NoError;
}


template<class... ArgsT>
string format(const string & text, const ArgsT&... args)
{
	string res = "";
	vector <string> vec;
	Error err = build(vec, args...);
	int len = text.size();
	int sz = vec.size();
	int flag = 0;
	if (len == 0)
		return res;
	if (text[0] == '}')
		throw myExc("Wrong usage of }\n");
	string cur;
	for (int i = 0; i < len; i++)
	{
		if (flag == 0)
		{
			if (text[i] == '}')
				throw myExc("Wrong usage of }\n");
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
					throw myExc("Wrong number of arguement\n");
				}
				if (num >= sz)
					throw myExc("So large number of arg\n");
				res += vec[num];
				flag = 0;
			}
			else
			{
				cur += text[i];
			}
		}
	} 
	if (flag == 1)
	{
		throw myExc("Hasn't closed } \n");
	}
	return res;
} 

#endif
