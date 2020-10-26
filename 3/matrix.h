#include <cstdio>
#include <iostream>
using namespace std;

class Matrix
{
private:
	class proxy;
	int rows;
	int columns;
	proxy *arr;
	class proxy
	{
	public:
		int *tmp;
		proxy() {}
		proxy(int sz)
		{
			tmp = new int[sz];
			for (int i = 0; i < sz; i++)
				tmp[i] = 0;
		}
		int &operator [] (int i)
		{
			return tmp[i];
		}
	};
public:
	Matrix();
	Matrix(int n, int m);
	~Matrix();
	int get_rows();
	int get_columns();
	proxy & operator [] (int i)
	{
		return arr[i];
	}
	void operator = (const Matrix &b) const
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				arr[i].tmp[j] = b.arr[i].tmp[j];
	}
	void operator *= (const int a) const
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				arr[i].tmp[j] *= a;				
	}
	Matrix operator + (const Matrix &b) const
	{
		Matrix buf(rows,columns);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				buf.arr[i].tmp[j] = arr[i].tmp[j] + b.arr[i].tmp[j];
		return buf;
	}
	bool operator == (const Matrix &b) const
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				if (arr[i].tmp[j] != b.arr[i].tmp[j])
					return 0;
		return 1;
	}
	bool operator != (const Matrix &b) const
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				if (arr[i].tmp[j] != b.arr[i].tmp[j])
					return 1;
		return 0;
	}
	friend std::ostream& operator<<(ostream &out, const Matrix &a)
	{
		for (int i = 0; i < a.rows; i++)
		{
			for (int j = 0; j < a.columns; j++)
				out << a.arr[i].tmp[j] << " ";
			out << endl;
		}
		return out;
	}
};
