#include "vector.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>
#include <string>
#include <sstream>
using namespace std;

class Data
{
public:
	bool a;
	string b;
	Data() {a = false;b = "";}
	Data(bool p, string q) {a = p; b=q;}
};

int main()
{
	//Проверяем работу push_back и size
	Vector <int> v;	
	v.push_back(1); 
	v.push_back(2);
	v.push_back(3);
	assert(v.size() == 3);
	assert(v[0] == 1);
	assert(v[1] == 2);
	assert(v[2] == 3);
	
	//Проверяем pop_back
	v.pop_back();
	assert(v.size() == 2);
	
	//Проверяем работу empty
	assert(v.empty() == false);
	
	//Проверяем работу итераторов
	vector <int> stdv;
	stdv.push_back(1);
	stdv.push_back(2);
	stdv.push_back(3);
	auto it = v.begin();
	auto it2 = stdv.begin();
	while (it != v.end() && it2 != stdv.end())
	{
		assert(*it == *it2);
		++it;
		++it2;
	}
	auto rit = v.rbegin();
	auto rit2 = stdv.rbegin();
	while (rit != v.rend() && rit2 != stdv.rend())
	{
		assert(*rit == *rit2);
		++rit;
		++rit2;
	}
	
	//Проверяем работу присваивания
	Vector <int> v2 = v;
	assert(v.size() == v2.size() && v[0] == v2[0] && v[1] == v[1] && v2.capacity() == v.capacity());
	
	//Проверяем работу clear()
	v.clear();
	assert(v.size() == 0);
	
	//Вектор из структуры, Проверяем работу emplace back
	Vector <Data> vec;
	vec.emplace_back(true, "KFC");
	assert(vec[0].a == true && vec[0].b == "KFC");
	
	//проверяем работу capacity и reserve
	vec.reserve(100);
	cout << "CAPACITY : " << vec.capacity() << endl;
	
	//проверяем работу resize
	vec.resize(3);
	assert(vec.size() == 3);
	
	cout << "OK" << endl;
	
	return 0;
}

