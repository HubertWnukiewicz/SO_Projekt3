#pragma once
#include <thread>
#include <random>
#include <memory>
#include <cstdio>
#include <atomic>
#include <functional>
#include <condition_variable>

class WorkStation;

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

	Worker(int id, WorkStation *firstStation, WorkStation *secondStation);

	void changeWorkStation(WorkStation *myWorkStation);

	void cycleOfLife();

private:
	int id;
	std::thread thread;
	//std::chrono::milliseconds activityTime;
	WorkerState State;

	WorkStation *currentStation;

	WorkStation *firstStation;

	WorkStation *secondStation;
};