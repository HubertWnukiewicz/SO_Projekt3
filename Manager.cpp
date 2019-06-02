#include "Manager.h"

Manager::Manager(int id, WorkStation *firstStation, WorkStation *secondStation)
{
	this->id = id;
	this->firstStation = firstStation;
	this->secondStation = secondStation;
}

void Manager::changeWorkStation(WorkStation *newWorkStation)
{
	this->currentStation = newWorkStation;
}
