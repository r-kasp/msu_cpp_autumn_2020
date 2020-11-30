#ifndef VECTOR_H
#define VECTOR_H
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

template <class Iter>
class Iterator
{
    Iter * current_;
    Iter * end_;
public:
    Iterator(Iter * begin, Iter * end): current_(begin), end_(end)
    {
    }
    bool operator == (const Iterator& other) const
    {
        return current_ == other.current_;
    }
    bool operator != (const Iterator& other) const
    {
        return !(*this == other);
    }
    void operator ++ ()
    {
        if (current_ != end_)
            ++current_;  
    }
    Iter & operator * () const
    {
        return *current_;
    }
};


template <class Iter>
class RIterator 
{
    Iter * current_;
    Iter * start_;
public:
    RIterator(Iter * begin, Iter * end): current_(end), start_(begin)
    {
    }
    bool operator == (const RIterator& other) const
    {
        return current_ == other.current_;
    }
    bool operator != (const RIterator& other) const
    {
        return !(*this == other);
    }
    void operator ++ ()
    {
        if (current_ != start_)
            --current_;  
    }
    Iter & operator * () const
    {
        return *current_;
    }

};


template<class T>
class Allocator
{
public:
	void alloc(T* &vec, unsigned int & capacity, unsigned int sz, unsigned int newsz)
	{
		if (newsz <= capacity)
			return;
		capacity = newsz + 10;
		T* vec2 = new T[capacity];
		for (int i = 0; i < sz; i++)
			vec2[i] = vec[i];
		if (vec != nullptr)
			delete [] vec;
		vec = vec2;
	}
};


template<class T>
class Vector
{
private:
	T * arr;
	unsigned int sz;
	unsigned int cap;
	Allocator<T> allocator;
public:
	Vector()
	{
		arr = nullptr;
		sz = 0;
		cap = 0;
	}
	Vector(unsigned int size)
	{
		arr = new T[size];
		sz = size;
		cap = size;
	}
	Vector(unsigned int size, const T & init)
	{
		arr = new T[size];
		for (int i = 0; i < sz; i++)
			arr[i] = init;
		sz = size;
		cap = size;
	}
	Vector(const Vector<T> & vec)
	{
		sz = vec.sz;
		cap = vec.cap;
		arr = new T[sz];
		for (int i = 0; i < sz; i++)
			arr[i] = vec.arr[i];
	}
	Vector(Vector<T> && vec)
	{
		sz = vec.sz; 
		vec.sz = 0;
		cap = vec.cap; 
		vec.cap = 0;
		arr = vec.arr; 
		vec.arr = nullptr;
	}
	~Vector()
	{
		if (arr != nullptr)
			delete [] arr;
		sz = 0;
		cap = 0;
	}
	Vector<T> & operator = (const Vector<T> & b)
	{
		if (b == *this)
			return *this;
		sz = b.sz;
		cap = b.cap;
		if (arr != nullptr)
			delete [] arr;
		arr = new T[sz];
		for (int i = 0; i < sz; i++)
			arr[i] = b.arr[i];
		return *this;
	}
	Vector<T> & operator = (Vector<T> && b)
	{
		if (&b == this)
			return *this;
		sz = b.sz;
		b.sz = 0;
		cap = b.cap;
		b.cap = 0;
		if (arr != nullptr)
			delete [] arr;
		arr = b.arr;
		b.arr = nullptr;
		return *this;
	}
	T & operator[](unsigned int ind)
	{
		if (ind >= sz)
			throw std::out_of_range("Index is out of range\n");
		return arr[ind];
	} 
	const T& operator[](unsigned int ind) const
	{
		if (ind >= sz)
			throw std::out_of_range("Index is out of range\n");
		return arr[ind];
	}
	void push_back(const T & val)
	{
		allocator.alloc(arr, cap, sz, sz+1);
		arr[sz] = val;
		sz++;
	} 
    	void pop_back()
    	{
		if (sz == 0)
			throw std::out_of_range("The Vector is empty\n");
		sz--;
	}
    	
    	template<class... Args>
    	void emplace_back(Args&&... args)
    	{
		push_back(T(std::forward<Args>(args)...));
	}
    	bool empty() const
    	{
		if (arr == nullptr)
			return true;
		return false;
	}
    	unsigned int size() const
    	{
		return sz;
	}
    	void clear()
    	{
		if (arr != nullptr)
			delete [] arr;
		arr = nullptr;
		sz = 0;
		cap = 0;
	}
	Iterator<T> begin()
	{
		return Iterator<T>(arr, arr+sz);
	}
	RIterator<T> rbegin()
	{
		return RIterator<T>(arr+sz-1, arr-1);
	}
	Iterator<T> end()
	{
		return Iterator<T>(arr+sz, arr+sz);
	}
	RIterator<T> rend()
	{
		return RIterator<T>(arr-1, arr-1);
	}
	void resize(unsigned int size)
	{
		reserve(size);
		sz = size;
	}
	void reserve(unsigned int len)
	{
		allocator.alloc(arr, cap, sz, len);
	}
	unsigned int capacity() const
	{
		return cap;
	}
};

#endif
