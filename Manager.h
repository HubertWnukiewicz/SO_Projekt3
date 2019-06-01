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

	WorkStation* myWorkStation;

	int id;
	//std::thread thread;
	std::chrono::milliseconds activityTime;
	ManagerState state;

public:

	Manager(int id, WorkStation* workStation);



	void changeWorkStation(WorkStation& myWorkStation);
};