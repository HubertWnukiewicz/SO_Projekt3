#pragma once
#include <iostream>
#include <mutex>
//#include "Manager.h"

class Manager;
class Worker;
class Boss;

class WorkStation
{
protected:
	int id;
	int manager_id;
	int worker1_id;
	int worker2_id;
	
	Manager* manager;
	Worker* worker;
	Boss* boss;
public:
	std::mutex mutex;

	WorkStation();

	WorkStation(int id, int manager_id,int worker1_id,int worker2_id, Boss* boss);

	void setId(int id){ this->id=id;}

	int getId() {return this->id;}

	Manager* getManager() { return this->manager; }

	Worker* getWorker() { return this->worker; }

	int getManagerId() {return this->manager_id;}

	int getWorker1Id() {return this->worker1_id;}

	int getWorker2Id() {return this->worker2_id;}

	void executeTask(Worker* worker);

	void superviseTask(Manager* manager);

};