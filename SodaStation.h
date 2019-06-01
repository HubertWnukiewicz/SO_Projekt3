#pragma once
#include "WorkStation.h"
#include "Worker.h"
#include "Boss.h"
//#include "Viewer.h"
class Viewer;

class SodaStation : WorkStation
{
public:
	enum SodaStationState
	{
		IN_USE,
		FREE
	};
	void startSoda(Viewer* viewer);

	void stopSoda(Viewer* viewer);

	SodaStation(int manager_id, int worker1_id, int worker2_id, Boss& boss);
	Manager* getManager() { return this->manager; }

	Worker* getWorker() { return this->worker; }

private:
	Manager* manager;
	Worker* worker;
	std::mutex sodaMutex;

	int manager_id;
	int worker1_id;
	int worker2_id;
	Boss& boss;

};