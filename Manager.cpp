#include "Manager.h"

Manager::Manager(int id, WorkStation * workStation)
{
	this->id = id;
	this->myWorkStation = workStation;
}

void Manager::changeWorkStation(WorkStation & myWorkStation)
{
	//notify boss o zmianie stanowiska 
}
