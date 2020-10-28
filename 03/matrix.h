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
		int cols;
		proxy() {}
		proxy(int sz)
		{
			cols = sz;
			tmp = new int[sz];
			for (int i = 0; i < sz; i++)
				tmp[i] = 0;
		}
		int &operator [] (int i)
		{
			if (i < 0 || i >= cols)
				throw std::out_of_range("out of range\n");
			return tmp[i];
		}
		const int &operator [] (int i) const
		{
			if (i < 0 || i >= cols)
				throw std::out_of_range("out of range\n");
			return tmp[i];
		}
	};
public:
	Matrix();
	Matrix(int n, int m);
	Matrix(const Matrix &b);
	~Matrix();
	int get_rows() const;
	int get_columns() const;
	proxy & operator [] (int i)
	{
		if (i < 0 || i >= rows)
			throw std::out_of_range("out of range\n");
		return arr[i];
	}
	const proxy & operator [] (int i) const
	{
		if (i < 0 || i >= rows)
			throw std::out_of_range("out of range\n");
		return arr[i];
	}
	Matrix & operator = (const Matrix &b)
	{
		if (b == *this)
			return *this;
		
		if (arr != nullptr)
			delete [] arr;
		rows = b.rows;
		columns = b.columns;
		arr = new proxy[rows];
		for (int i = 0; i < rows; i++)
      		arr[i] = proxy(columns);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				arr[i].tmp[j] = b.arr[i].tmp[j];		
				
		return *this;
	}
	Matrix & operator *= (const int a)
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				arr[i].tmp[j] *= a;
		return *this;				
	}
	Matrix operator + (const Matrix &b) const
	{
		if (rows != b.rows || columns != b.columns)
			throw std::out_of_range("");
		Matrix buf(rows,columns);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				buf.arr[i].tmp[j] = arr[i].tmp[j] + b.arr[i].tmp[j];
		return buf;
	}
	bool operator == (const Matrix &b) const
	{
		if (b.rows != rows || b.columns != columns)
			return false;
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				if (arr[i].tmp[j] != b.arr[i].tmp[j])
					return false;
		return true;
	}
	bool operator != (const Matrix &b) const
	{
		if (b.rows != rows || b.columns != columns)
			return true;
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				if (arr[i].tmp[j] != b.arr[i].tmp[j])
					return true;
		return false;
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
