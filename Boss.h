#pragma once
#include <deque>
#include <mutex>
#include <condition_variable>
class Boss
{
	std::deque<class Worker *> workers;
	std::deque<class Manager *> managers;
	std::mutex _mutex;
	std::condition_variable cv;
};