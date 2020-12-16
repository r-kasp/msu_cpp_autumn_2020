#ifndef THREAD_H
#define THREAD_H
#include <cstdio>
#include <iostream>
#include <string>
#include <thread>
#include <functional>
#include <vector>
#include <mutex>
#include <future>
#include <queue>
#include <sstream>
#include <condition_variable>
using namespace std;

class ThreadPool
{
	using f = function<void()>;
private:
	vector <thread> threads;
	queue <f> tasks;
	mutex Qmutex;
	bool flag;
	condition_variable cond;
public:
	explicit ThreadPool(size_t poolSize);
	~ThreadPool();
	template <class Func, class... Args>
	auto exec(Func && func, Args&&... args) -> future<decltype(func(args...))>
	{
		using type_ret = decltype(func(args...));
		auto task = make_shared<packaged_task<type_ret()> > (bind(forward<Func>(func), forward<Args>(args)...));
		future<type_ret> res = task->get_future();
		unique_lock<mutex> ul(Qmutex);
		tasks.emplace([task](){ (*task)();});
		ul.unlock();
		cond.notify_one();
		return res;
	}
};

#endif
