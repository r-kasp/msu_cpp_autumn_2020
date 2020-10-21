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
	int TokenParser(const string &s, vector<string> &a, vector<int> &b)
	{
		string s1 = "Hello my dear user!";
		string s2 = "Goodbye my dear user";
		startcallback(s1);
		string token = "";
		int i = 0, n = s.size();
		bool isdigit = 1;
		while (i < n)
		{
			isdigit = 1;
			while (s[i] != '\0' && s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
			{
				token += s[i];
				if (!(s[i] >= '0' && s[i] <= '9'))
					isdigit = 0;
				i++;
			}
			if (isdigit)
			{
				try
				{
					digitcallback(stoi(token), b);
				}
				catch (const exception &ex)
				{
					cout << ex.what() << endl;
					return -1;
				}
			}
			else
			{
				try
				{
					strcallback(token, a);
				}
				catch (const exception &ex)
				{
					cout << ex.what() << endl;
					return -2;
				}
			}
			token = "";
			i++;
		}
		finishcallback(s2);
		return 0;
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
