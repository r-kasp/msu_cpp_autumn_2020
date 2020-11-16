#include "serializer.h"
#include <iostream>
#include <cstdio>
#include <cassert>
#include <string>
#include <sstream>
using namespace std;

struct Data
{
	uint64_t a;
	bool b;
	uint64_t c;
	
	template <class Serializer>
	Error serialize(Serializer &serializer)
	{
		return serializer(a, b, c);
	}
};

struct Data2
{
	bool a;
	bool b;
	
	template <class Serializer>
	Error serialize(Serializer &serializer)
	{
		return serializer(a, b);
	}
};


int main()
{
	
	//TEST 1 Проверяется работа сериалайзера
	Serializer h(cout);
	Data x { 12, true, 43}; 
	std::stringstream stream; 
	Serializer serializer(stream); 
	serializer.save(x); 
	std::cout << stream.str() << std::endl; 
	
	//TEST 2 Проверяется работа десериалайзера
	Data y { 0, false, 0 }; 
	Deserializer deserializer(stream); 
	const Error err = deserializer.load(y); 
	assert(err == Error::NoError); 
	assert(x.a == y.a); 
	assert(x.b == y.b); 
	assert(x.c == y.c);
	
	//TEST 3 Снова проверяем сериалайзер на другой структуре
	Serializer h2(cout);
	Data2 x2 {true, false};
	std::stringstream stream2;
	Serializer serializer2(stream2); 
	serializer2.save(x2); 
	std::cout << stream2.str() << std::endl;  
	
	//TEST 4 Десериалайзер
	Data2 y2 {false, false}; 
	Deserializer deserializer2(stream2); 
	const Error err2 = deserializer2.load(y2); 
	assert(err2 == Error::NoError); 
	assert(x2.a == y2.a); 
	assert(x2.b == y2.b);	
		 
	std::cout << "OK" << std::endl; 
	
	return 0;
}

