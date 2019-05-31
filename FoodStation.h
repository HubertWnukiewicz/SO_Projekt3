#pragma once
#include "WorkStation.h"
#include "Worker.h"
#include "Viewer.h"

class FoodStation : WorkStation
{
public:
	enum FoodStationState
	{
		IN_USE,
		FREE
	};

	void sellFood(Viewer viewer);

	FoodStation(Manager* manager, Worker* worker);

	Manager* getManager() { return this->manager; }

	Worker* getWorker() { return this->worker; }
private:
	Manager* manager;
	Worker* worker;
};