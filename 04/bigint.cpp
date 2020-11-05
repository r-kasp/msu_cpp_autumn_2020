#include "bigint.h"
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

BigInt::BigInt()
{
	size = 0;
	num = nullptr;
	sign = 1;
}

BigInt::BigInt(const string &h)
{
	if (h.size() > 0 && h[0] == '-')
	{
		size = h.size()-1;
		num = new int[size];
		sign = 0;
		for (int i = 1; i <= size; i++)
		{
			if (!isdigit(h[size+1-i]))
				throw std::runtime_error("Not a number");
			else
				num[i-1] = h[size+1-i] - '0';
		}
	}
	else
	{
		size = h.size();
		num = new int[size];
		sign = 1;
		for (int i = 0; i < size; i++)
		{
			if (!isdigit(h[size-1-i]))
				throw std::runtime_error("Not a number");
			else
				num[i] = h[size-1-i] - '0';
		}
	}
}

BigInt::BigInt(const BigInt &b)
{
	sign = b.sign;
	size = b.size;
	num = new int[size];
	for (int i = 0; i < size; i++)
		num[i] = b.num[i];
}	

BigInt::BigInt(BigInt && b)
{
	size = b.size;
	b.size = 0;
	sign = b.sign;
	b.sign = 1;
	num = b.num;
	b.num = nullptr;
}

BigInt::~BigInt()
{
	size = 0;
	sign = 1;
	delete num;
}

BigInt &BigInt::operator = (const BigInt &b)
{
	if (b == *this)
		return *this;
	sign = b.sign;
	size = b.size;
	if (num != nullptr)
		delete num;
	num = new int[size];
	for (int i = 0; i < size; i++)
		num[i] = b.num[i];
	return *this;
}

BigInt &BigInt::operator = (const int a)
{
	string h = to_string(a);
	BigInt b(h);
	if (b == *this)
		return *this;
	sign = b.sign;
	size = b.size;
	if (num != nullptr)
		delete num;
	num = new int[size];
	for (int i = 0; i < size; i++)
		num[i] = b.num[i];
	return *this;
	
}

BigInt BigInt::operator - () const
{
	BigInt buf(*this);
	if (!(size == 1 && num[0] == 0))
		buf.sign = !sign;
	return buf;	
}

bool BigInt::operator == (const BigInt &b) const
{
	if (b.size == 0 && size == 0 && num[0] == 0 && b.num[0] == 0)
		return true;
	if (sign != b.sign)
		return false;
	int i1 = 0, i2 = 0;
	while (i1 < size && i2 < b.size)
	{
		if (num[i1] != b.num[i2])
			return false;
		i1++;
		i2++;
	}
	if (i1 != size || i2 != b.size)
		return false;
	return true;
}

bool BigInt::operator == (const int a) const
{
	string h = to_string(a);
	BigInt b(h);
	return (*this == b);
}

bool BigInt::operator != (const BigInt &b) const
{
	if (b.size == 0 && size == 0 && num[0] == 0 && b.num[0] == 0)
		return false;
	if (sign != b.sign)
		return true;
	int i1 = 0, i2 = 0;
	while (i1 < size && i2 < b.size)
	{
		if (num[i1] != b.num[i2])
			return true;
		i1++;
		i2++;
	}
	if (i1 != size || i2 != b.size)
		return true;
	return false;
}


bool BigInt::operator != (const int a) const
{
	string h = to_string(a);
	BigInt b(h);
	return (*this != b);
}

bool BigInt::operator < (const BigInt &b) const
{
	if (!sign && b.sign)
		return true;
	if (sign && !b.sign)
		return false;
	if (sign)
	{
		if (size < b.size)
			return true;
		if (size > b.size)
			return false;
		bool flag = 0;
		for (int i = 0; i < size; i++)
		{
			if (num[size-1-i] < b.num[size-1-i])
				return true;
			if (num[size-1-i] > b.num[size-1-i])
				return false;
			if (num[size-1-i] != b.num[size-1-i])
				flag = 1;
		}
		return flag;
	}
	else
	{
		if (size > b.size)
			return true;
		if (size < b.size)
			return false;
		bool flag = 0;
		for (int i = 0; i < size; i++)
		{
			if (num[size-1-i] > b.num[size-1-i])
				return true;
			if (num[size-1-i] < b.num[size-1-i])
				return false;
			if (num[size-1-i] != b.num[size-1-i])
				flag = 1;
		}
		return flag;
	}
}

bool BigInt::operator < (const int a) const
{
	string h = to_string(a);
	BigInt b(h);
	return (*this < b);
}

bool BigInt::operator <= (const BigInt &b) const
{
	if (!sign && b.sign)
		return true;
	if (sign && !b.sign)
		return false;
	if (sign)
	{
		if (size < b.size)
			return true;
		if (size > b.size)
			return false;
		for (int i = 0; i < size; i++)
		{
			if (num[size-1-i] < b.num[size-1-i])
				return true;
			if (num[size-1-i] > b.num[size-1-i])
				return false;
		}
		return true;
	}
	else
	{
		if (size > b.size)
			return true;
		if (size < b.size)
			return false;
		for (int i = 0; i < size; i++)
		{
			if (num[size-1-i] > b.num[size-1-i])
				return true;
			if (num[size-1-i] < b.num[size-1-i])
				return false;
		}
		return true;
	}
}

bool BigInt::operator <= (const int a) const
{
	string h = to_string(a);
	BigInt b(h);
	return (*this <= b);
}

bool BigInt::operator > (const BigInt &b) const
{
	if (!sign && b.sign)
		return false;
	if (sign && !b.sign)
		return true;
	if (sign)
	{
		if (size > b.size)
			return true;
		if (size < b.size)
			return false;
		bool flag = 0;
		for (int i = 0; i < size; i++)
		{
			if (num[size-1-i] > b.num[size-1-i])
				return true;
			if (num[size-1-i] < b.num[size-1-i])
				return false;
			if (num[size-1-i] != b.num[size-1-i])
				flag = 1;
		}
		return flag;
	}
	else
	{
		if (size > b.size)
			return true;
		if (size < b.size)
			return false;
		bool flag = 0;
		for (int i = 0; i < size; i++)
		{
			if (num[size-1-i] < b.num[size-1-i])
				return true;
			if (num[size-1-i] > b.num[size-1-i])
				return false;
			if (num[size-1-i] != b.num[size-1-i])
				flag = 1;
		}
		return flag;
	}
}

bool BigInt::operator > (const int a) const
{
	string h = to_string(a);
	BigInt b(h);
	return (*this > b);
}

bool BigInt::operator >= (const BigInt &b) const
{
	if (!sign && b.sign)
		return false;
	if (sign && !b.sign)
		return true;
	if (sign)
	{
		if (size > b.size)
			return true;
		if (size < b.size)
			return false;
		for (int i = 0; i < size; i++)
		{
			if (num[size-1-i] > b.num[size-1-i])
				return true;
			if (num[size-1-i] < b.num[size-1-i])
				return false;
		}
		return true;
	}
	else
	{
		if (size > b.size)
			return true;
		if (size < b.size)
			return false;
		for (int i = 0; i < size; i++)
		{
			if (num[size-1-i] < b.num[size-1-i])
				return true;
			if (num[size-1-i] > b.num[size-1-i])
				return false;
		}
		return true;
	}
}

bool BigInt::operator >= (const int a) const
{
	string h = to_string(a);
	BigInt b(h);
	return (*this >= b);
}

BigInt BigInt::operator + (const BigInt &b) const
{
	if (sign && b.sign || !sign && !b.sign)
	{
		int sz = max(size, b.size);
		BigInt res;
		res.num = new int[sz];
		res.size = sz;
		res.sign = sign;
		for (int i = 0; i < sz; i++)
			res.num[i] = 0;
		int i;
		for (i = 0; i < size && i < b.size; i++)
			res.num[i] = num[i] + b.num[i];
		while (i < size)
		{
			res.num[i] = num[i];
			i++;
		}
		while (i < b.size)
		{
			res.num[i] = b.num[i];
			i++;
		}
		if (res.num[sz-1] > 9)
		{
			int *res2 = new int[sz+1];	
			for (int i = 0; i < sz; i++)
				res2[i] = res.num[i];
			res2[sz] = 0;
			for (int i = 1; i <= sz; i++)
			{
				res2[i] += res2[i-1]/10;
				res2[i-1] %= 10;
			} 
			delete [] res.num;
			res.size++;
			res.num = new int[res.size];
			for (i = 0; i <= sz; i++)
				res.num[i] = res2[i];
			delete [] res2;
		}
		else
		{
			for (i = 1; i < sz; i++)
			{
				res.num[i] += res.num[i-1]/10;
				res.num[i-1] %= 10;
			}
		}
		return res;
	}
	if (sign && !b.sign)
		return *this - (-b);
	//if (!sign && b.sign)
	return -(-(*this) - b);	
}

BigInt BigInt::operator + (const int a) const
{
	string h = to_string(a);
	BigInt b(h);
	return (*this + b);
}

BigInt BigInt::operator - (const BigInt &b) const
{
	if (sign && b.sign)
	{
		if (b > *this)
			return -(b - *this);
		int sz = max(size, b.size);
		BigInt res;
		res.num = new int[sz];
		res.size = sz;
		res.sign = sign;
		for (int i = 0; i < sz; i++)
			res.num[i] = 0;
		int i;
		for (i = 0; i < size && i < b.size; i++)
		{
			res.num[i] += num[i] - b.num[i];
			if (res.num[i] < 0)
			{
				res.num[i] += 10;
				res.num[i+1]--;
			}
		}
		while (i < size)
		{
			res.num[i] += num[i];
			if (res.num[i] < 0)
			{
				res.num[i] += 10;
				if (i < size-1)
					res.num[i+1]--;
			}
			i++;
		}
		while (i < b.size)
		{
			res.sign = 0;
			res.num[i] += b.num[i];
			i++;
		}
		int k = 0;
		for (int i = 0; i < sz && res.num[sz-1-i] == 0; i++)
			k++;
		if (k > 0)
		{
			if (k != sz)
			{
				int *res2 = new int[sz-k];
				for (int i = 0; i < sz-k; i++)
					res2[i] = res.num[i];
				delete [] res.num;
				res.size = sz-k;
				res.num = new int[sz-k];
				for (int i = 0; i < sz-k; i++)
					res.num[i] = res2[i];
				delete [] res2;
			}
			else
			{
				delete [] res.num;
				res.num = new int[1];
				res.num[0] = 0;
				res.size = 1;
			}
		}
		return res;
	}
	if (!sign && !b.sign)
		return (-b) - (-*this);
	if (sign && !b.sign)
		return *this + (-b);
	//if (!sign && b.sign)
	return -(-(*this) + b);
}

BigInt BigInt::operator - (const int a) const
{
	string h = to_string(a);
	BigInt b(h);
	return (*this - b);
}

BigInt BigInt::operator * (const BigInt &b) const
{
	int sz = size + b.size - 1;
	BigInt res;
	res.size = sz;
	res.sign = sign * b.sign;
	res.num = new int[sz];
	for (int i = 0; i < sz; i++)
		res.num[i] = 0;
	for (int i = 0; i < size; i++)
	{
		long long ost = 0;
		for (int j = 0; j < b.size || ost; j++)
		{
			long long cur = res.num[i+j] + ost;
			if (j < b.size)
			{
				cur += 1ll * num[i] * b.num[j];
			}
			res.num[i+j] = cur % 10;
			ost = cur / 10;
		}
	}
	//удаление нулей
	int k = 0;
	for (int i = 0; i < sz && res.num[sz-1-i] == 0; i++)
		k++;
	if (k > 0)
	{
		if (k != sz)
		{
			int *res2 = new int[sz-k];
			for (int i = 0; i < sz-k; i++)
				res2[i] = res.num[i];
			delete [] res.num;
			res.size = sz-k;
			res.num = new int[sz-k];
			for (int i = 0; i < sz-k; i++)
				res.num[i] = res2[i];
			delete [] res2;
		}
		else
		{
			delete [] res.num;
			res.num = new int[1];
			res.num[0] = 0;
			res.sign = 1;
			res.size = 1;
		}
	}
	
	return res;
}

BigInt BigInt::operator * (const int a) const
{
	string h = to_string(a);
	BigInt b(h);
	return (*this * b); 
}
