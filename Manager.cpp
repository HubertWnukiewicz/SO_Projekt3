#include "Manager.h"
#include "WorkStation.h"
Manager::Manager(int id, WorkStation *firstStation, WorkStation *secondStation)
{
	this->id = id;
	this->firstStation = firstStation;
	this->secondStation = secondStation;
	this->currentStation=nullptr;
	this->managerThread=std::thread(&Manager::cycleOfLife, this);
}

void Manager::changeWorkStation(WorkStation *newWorkStation)
{	this->managerMutex.lock();
	this->currentStation = newWorkStation;
}
void Manager::releaseWorkStation()
{
	this->currentStation = nullptr;
	this->managerMutex.unlock();

}
void Manager::cycleOfLife()
{
	while(true)
	{
		this->currentStation->superviseTask(this);
	}
}
