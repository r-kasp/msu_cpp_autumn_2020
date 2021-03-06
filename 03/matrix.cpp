#include "matrix.h"
#include <iostream>
using namespace std;

Matrix::Matrix()
{
	rows = 0;
	columns = 0;
}

Matrix::Matrix(int n, int m)
{
	if (n >= 1 && m >= 1)
	{
		rows = n;
		columns = m;
		arr = new proxy[rows];
    		for (int i = 0; i < rows; i++)
        		arr[i] = proxy(columns);
	}
	else
	{
		throw std::out_of_range("out of range\n");
	}
}

Matrix::Matrix(const Matrix &b)
{
	rows = b.rows;
	columns = b.columns;
	arr = new proxy[rows];

    	for (int i = 0; i < rows; i++)
      	arr[i] = proxy(columns);

    	for (int i = 0; i < rows; i++)
      	for (int j = 0; j < columns; j++)
        		arr[i].tmp[j] = b.arr[i].tmp[j];	
}

Matrix::~Matrix()
{
	for (int i = 0; i < rows; i++)
		if (arr[i].tmp != nullptr)
			delete [] (arr[i].tmp);
	if (arr != nullptr)
		delete [] arr;  
	rows = columns = 0;
}

int Matrix::get_rows() const
{
	return rows;
}

int Matrix::get_columns() const
{
	return columns;
}
