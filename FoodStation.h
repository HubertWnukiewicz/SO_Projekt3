#pragma once
#include "WorkStation.h"
#include "Worker.h"
#include "Boss.h"

class Viewer;
//Viewer*  a;

class FoodStation : public WorkStation
{
public:
	enum FoodStationState
	{
		IN_USE,
		FREE
	};

	void startFood(Viewer* viewer);

	void stopFood(Viewer* viewer);
	int currentWorker;
	explicit FoodStation(int manager1_id, int worker1_id, int worker2_id,Boss* boss);// :WorkStation(manager1_id,worker1_id,worker2_id,boss) {}
/*
	Manager* getManager() { return this->manager; }

	Worker* getWorker() { return this->worker; }
private:
	
	Manager* manager;
	Worker* worker;
	std::mutex foodMutex;

	int manager1_id;
	int manager2_id;
	int worker1_id;
	int worker2_id;
	Boss* boss;
	*/
};