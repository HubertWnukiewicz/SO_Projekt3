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
		BUSY,
		FREE
	};

	std::mutex workerMutex;
	Worker(int id, WorkStation *firstStation, WorkStation *secondStation);

	void changeWorkStation(WorkStation *myWorkStation);

	void cycleOfLife();

	void setCurrentStation(WorkStation* workStation);

	void releaseCurrentStation();

	WorkStation* getCurrentStation();
	void setState(WorkerState nState) {this->state=nState;}

	WorkerState getState() {return this->state;}
	std::thread workerThread;

	int getId() {return this->id;}
private:
	int id;
	
	//std::chrono::milliseconds activityTime;
	WorkerState state;

	WorkStation *currentStation;

	WorkStation *firstStation;

	WorkStation *secondStation;
};