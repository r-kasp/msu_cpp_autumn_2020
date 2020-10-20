#include <cstdio>
#include <iostream>
#include <string>
#include <functional>
using namespace std;
void Ffinish(string &s);
void Fstart(string &s);
void Fdigit(int n);
void Fstr(string &s);


class Parser
{
private:
	function<void(string &s)> strcallback;
	function<void(const int n)> digitcallback;
	function<void(string &s)> startcallback;
	function<void(string &s)> finishcallback;
public:
	int TokenParser(string &s)
	{
		string s1 = "Hello my dear user!";
		string s2 = "Goodbye my dear user";
		startcallback(s1);
		string token = "";
		int i = 0, n = s.size();
		bool isdigit = 1;
		size_t a = 0;
		while (i < n)
		{
			isdigit = 1;
			a = 0;
			while (s[i] != '\0' && s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
			{
				token += s[i];
				if (!(s[i] >= '0' && s[i] <= '9'))
					isdigit = 0;
				else if (isdigit)
					a = a*10 + s[i] - '0';
				i++;
			}
			if (isdigit)
				digitcallback(a);
			else
				strcallback(token);
			token = "";
			i++;
		}
		finishcallback(s2);
		return 0;
	}
	void SetStartCallback(function<void(string &s)> f)
	{
		startcallback = f;
	}
	void SetFinishCallback(function<void(string &s)> f)
	{
		finishcallback = f;
	}
	void SetDigitTokenCallback(function<void(const int n)> f)
	{
		digitcallback = f;
	}
	void SetStingTokenCallback(function<void(string &s)> f)
	{
		strcallback = f;
	}
};
