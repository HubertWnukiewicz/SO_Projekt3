#include "Worker.h"
#include "WorkStation.h"
Worker::Worker(int id, WorkStation *firstStation, WorkStation *secondStation) : firstStation(firstStation), secondStation(secondStation)
{
	this->id = id;
	this->firstStation = firstStation;
	this->secondStation = secondStation;
	this->currentStation = nullptr;
	this->workerThread = std::thread(&Worker::cycleOfLife, this);
}

void Worker::cycleOfLife()
{
	while (true)
	{
		this->currentStation->executeTask(this);
	}
}
void Worker::changeWorkStation(WorkStation *myWorkStation)
{	this->workerMutex.lock();
	this->currentStation = myWorkStation;
}
void Worker::releaseCurrentStation()
{
	this->currentStation=nullptr;
	this->workerMutex.unlock();
}
void Worker::setCurrentStation(WorkStation* newWorkStation)
{
	this->currentStation=newWorkStation;
}
WorkStation* Worker::getCurrentStation()
{
	return this->currentStation;
}
