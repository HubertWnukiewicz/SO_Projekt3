#include "WorkStation.h"
#include "Worker.h"
#include "Manager.h"
#include "Boss.h"
WorkStation::WorkStation()
{
	id = 0;
	//manager = nullptr;
}
WorkStation::WorkStation(int id, int manager_id,int worker1_id,int worker2_id,Boss* boss) : boss(boss)
{
	this->id = id;
	this->manager_id=manager_id;
	this->worker1_id=worker1_id;
	this->worker2_id=worker2_id;
}
void WorkStation::executeTask(Worker* worker)
{
	//worker->workerThread.sleep(1000);
}
void WorkStation::superviseTask(Manager* manager)
{
	//manager->managerThread.sleep(1000);
}