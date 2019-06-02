#include "Worker.h"
#include "WorkStation.h"
Worker::Worker(int id, WorkStation *firstStation, WorkStation *secondStation) : firstStation(firstStation), secondStation(secondStation)
{
	this->id = id;
	this->firstStation = firstStation;
	this->secondStation = secondStation;
	this->currentStation = nullptr;
	this->thread = std::thread(&Worker::cycleOfLife, this);
}

void Worker::cycleOfLife()
{
	while (true)
	{
		this->currentStation->executeTask();
	}
}
void Worker::changeWorkStation(WorkStation *myWorkStation)
{
	this->currentStation = myWorkStation;
}
