#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <functional>
using namespace std;
void Ffinish(string &s);
void Fstart(string &s);
void Fdigit(int n, vector<int> &v);
void Fstr(string &s, vector<string> &v);


class Parser
{
private:
	function<void(string &s, vector<string> &v)> strcallback;
	function<void(const int n, vector<int> &v)> digitcallback;
	function<void(string &s)> startcallback;
	function<void(string &s)> finishcallback;
public:
	void TokenParser(const string &s, vector<string> &a, vector<int> &b)
	{
		string s1 = "Hello my dear user!";
		string s2 = "Goodbye my dear user";
		startcallback(s1);
		string token = "";
		int i = 0, n = s.size();
		bool digit = 1;
		while (i < n)
		{
			digit = 1;
			if (isspace(s[i]))
			{
				i++;
				continue;
			}
			while (s[i] != '\0' && !(isspace(s[i])))
			{
				token += s[i];
				if (!(isdigit(s[i])))
					digit = 0;
				i++;
			}
			if (digit)
			{
				digitcallback(stoi(token), b);
			}
			else
			{
				strcallback(token, a);
			}
			token = "";
			i++;
		}
		finishcallback(s2);
	}
	void SetStartCallback(const function<void(string &s)> &f)
	{
		startcallback = f;
	}
	void SetFinishCallback(const function<void(string &s)> &f)
	{
		finishcallback = f;
	}
	void SetDigitTokenCallback(const function<void(const int n, vector<int> &v)> &f)
	{
		digitcallback = f;
	}
	void SetStingTokenCallback(const function<void(string &s, vector<string> &v)> &f)
	{
		strcallback = f;
	}
};
