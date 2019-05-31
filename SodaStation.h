#pragma once
#include "WorkStation.h"
#include "Worker.h"
#include "Viewer.h"

class SodaStation : WorkStation
{
public:
	enum SodaStationState
	{
		IN_USE,
		FREE
	};
	void sellSoda(Viewer viewer);
	SodaStation(Manager* manager, Worker* worker);

	Manager* getManager() { return this->manager; }

	Worker* getWorker() { return this->worker; }

private:
	Manager* manager;
	Worker* worker;



};