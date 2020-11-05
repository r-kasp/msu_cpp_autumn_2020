#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

class BigInt
{
private:
	int *num;
	int size;
	bool sign;  // знак, если отрицательный, то он равен 0, иначе 1
public:
	BigInt();
	BigInt(const string &h);
	BigInt(const BigInt &b);
	BigInt(BigInt && b);
	~BigInt();
	BigInt & operator = (const int a);
	BigInt & operator = (const BigInt &b);
	BigInt operator - () const;
	bool operator == (const int a) const;
	bool operator == (const BigInt &b) const;
	bool operator != (const int a) const;
	bool operator != (const BigInt &b) const;
	bool operator < (const int a) const;
	bool operator < (const BigInt &b) const;
	bool operator <= (const int a) const;
	bool operator <= (const BigInt &b) const;
	bool operator > (const int a) const;
	bool operator > (const BigInt &b) const;
	bool operator >= (const int a) const;
	bool operator >= (const BigInt &b) const;
	BigInt operator + (const int a) const;
	BigInt operator + (const BigInt &b) const;
	BigInt operator - (const int a) const;
	BigInt operator - (const BigInt &b) const;
	BigInt operator * (const int a) const;
	BigInt operator * (const BigInt &b) const;
	friend std::ostream& operator<<(ostream &out, const BigInt &a)
	{
		if (!a.sign)
			out << '-';
		for (int i = a.size-1; i >= 0; i--)
			out << a.num[i];
		return out;
	}
};

