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
		activity1,
		activity2,
		activity3,
		activity4,
		activity5
	};

private:
	int id;
	
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
};