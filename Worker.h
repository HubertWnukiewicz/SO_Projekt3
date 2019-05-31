#pragma once
#include <thread>
#include <random>
#include <memory>
#include <cstdio>
#include <atomic>
#include <functional>
#include <condition_variable>

class Worker
{
public:
	enum WorkerState
	{
		activity1,
		activity2,
		activity3,
		activity4,
		activity5
	};

	Worker(int id);
private:
	int id;
	//std::thread thread;
	std::chrono::milliseconds activityTime;
	WorkerState nextState;


};