#include "thread.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>
#include <string>
#include <chrono>
#include <time.h>
#include <sstream>
using namespace std;

struct A {};
void foo(const A&) {}

mutex mtx;
//функция просто эмулирует тяжелую работу
void emulate()
{
	for (int i = 0; i < 5; i++)
	{
		mtx.lock();
		cout << "iteration : " << i << endl;
		mtx.unlock();
		this_thread::sleep_for(chrono::milliseconds(1000)); 
	}
}

int main()
{
	//Тесты из примера дз
	ThreadPool pool(8);

	auto task1 = pool.exec(foo, A());
	task1.get();

	auto task2 = pool.exec([]() { return 1; });
	task2.get();
	
	//Тестируем параллельную работу
	ThreadPool th(2);
	
	cout << "Без потоков : " << endl;
	emulate();
	emulate();
	cout << endl;
	
	cout << "С потоками : " << endl;
	auto t1 = th.exec(emulate);
	auto t2 = th.exec(emulate);
	t1.get();
	t2.get();
	
	return 0;
}

