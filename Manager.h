#pragma once
#include <thread>
#include <random>
#include <memory>
#include <cstdio>
#include <atomic>
#include <functional>
#include <condition_variable>

class WorkStation;

class Manager
{

public:
	enum ManagerState
	{
		BUSY,
		FREE
	};

private:
	int id;
	std::mutex managerMutex;
	//std::chrono::milliseconds activityTime;
	ManagerState state;
	WorkStation *currentStation;

	WorkStation *firstStation;

	WorkStation *secondStation;

public:
	Manager(int id, WorkStation *firstStation, WorkStation *secondStation);

	std::thread managerThread;

	int getId() { return this->id; }

	void changeWorkStation(WorkStation *myWorkStation);

	void cycleOfLife();

	void releaseWorkStation();

	void setState(ManagerState nState) {this->state=nState;}

	ManagerState getState() {return this->state;}
};