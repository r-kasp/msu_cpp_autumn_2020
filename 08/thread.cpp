#include "thread.h"
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

ThreadPool::ThreadPool(size_t poolSize)
{
	flag = false;
	for (int i = 0; i < poolSize; i++)
	{
		threads.emplace_back([this]
		{
			while (true)
			{
				f task;
				unique_lock<mutex> ul(Qmutex);
				cond.wait(ul, [this]{return !tasks.empty() || flag;} );
				if (flag && tasks.empty())
					return;
				task = move(tasks.front());
				tasks.pop();
				ul.unlock();
				task();	
			}
		});
	}
}

ThreadPool::~ThreadPool()
{
	unique_lock<mutex> ul(Qmutex);
	flag = true;
	ul.unlock();
	cond.notify_all();
	for (thread & x : threads)
		x.join();
}
