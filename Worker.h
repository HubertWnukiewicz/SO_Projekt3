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
		NO_MANAGER,
		NO_WORKER,
		NO_ONE,
		BUSY
	};

	Worker(int id, WorkStation *firstStation, WorkStation *secondStation);

	void changeWorkStation(WorkStation *myWorkStation);

	void cycleOfLife();
	void setCurrentStation(WorkStation* workStation);
	WorkStation* getCurrentStation();

	std::thread workerThread;
private:
	int id;
	
	//std::chrono::milliseconds activityTime;
	WorkerState State;

	WorkStation *currentStation;

	WorkStation *firstStation;

	WorkStation *secondStation;
};