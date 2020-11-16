#ifndef SERIALIZER_H
#define SERIALIZER_H
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
#pragma once
bool isNumber(const string &s);

enum class Error
{
	NoError,
	CorruptedArchive
};


class Serializer
{
	static constexpr char Separator = ' ';
	std::ostream &out_;
public:
	explicit Serializer(std::ostream &out) : out_(out)
	{
	}
	
	template <class T>
	Error save(T& object)
	{
		return object.serialize(*this);
	}
	
	template <class... ArgsT>
	Error operator()(ArgsT... args)
	{
		return process(args...);
	}
private:
	template <class T>
	Error process(T && val)
	{
		
		out_ << val << Separator;
		return Error::NoError;
	}
	template <class T, class... Args>
	Error process(T && val, Args&&... args)
	{
		out_ << std::boolalpha << val << Separator;
		process(std::forward<Args>(args)...);
		return Error::NoError;
	}
};


class Deserializer
{
    	static constexpr char Separator = ' ';
    	std::istream &in_;
public:
    	explicit Deserializer(std::istream& in): in_(in)
   	{
    	}

    	template <class T>
    	Error load(T& object)
    	{
      	  return object.serialize(*this);
    	}	

    	template <class... ArgsT>
   	Error operator()(ArgsT&&... args)
    	{
        	return process(std::forward<ArgsT>(args)...);
    	}
private:
	template <class T>
	Error process(T && val)
	{
		string str;
		in_ >> str;
		if (isNumber(str))
		{
			try
			{
				val = stoull(str);
			}
			catch (const out_of_range &)
			{
				return Error::CorruptedArchive;
			}
		}
		else if (str == "true")
			val = true;
		else if (str == "false")
			val = false;
		else
			return Error::CorruptedArchive;
		return Error::NoError;
	}
	template <class T, class... Args>
	Error process(T && val, Args&&... args)
	{
		bool res = true;
		if (process(val) != Error::NoError)
			res = false;
		if (process(std::forward<Args>(args)...) != Error::NoError)
			res = false;
		if (res)
			return Error::NoError;
		return Error::CorruptedArchive;
	}
};


#endif
