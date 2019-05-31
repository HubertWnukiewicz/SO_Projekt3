#pragma once
#include "WorkStation.h"
#include "Worker.h"
#include "Boss.h"

class Viewer;
//Viewer*  a;

class FoodStation : WorkStation
{
public:
	enum FoodStationState
	{
		IN_USE,
		FREE
	};

	void startFood(Viewer* viewer);

	void stopFood(Viewer* viewer);

	FoodStation(int manager_id, int worker1_id, int worker2_id,Boss& boss);

	Manager* getManager() { return this->manager; }

	Worker* getWorker() { return this->worker; }
private:
	Manager* manager;
	Worker* worker;
	std::mutex foodMutex;

	int manager_id;
	int worker1_id;
	int worker2_id;
	Boss& boss;
};