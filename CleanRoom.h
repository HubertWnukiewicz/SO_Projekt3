#pragma once
#include "WorkStation.h"
#include "Worker.h"
#include "Boss.h"

class CleanRoom :WorkStation{

    public:

    CleanRoom(int manager1_id, int worker1_id, int worker2_id,Boss* boss);// :WorkStation(manager1_id,worker1_id,worker2_id,boss) {}
/*
	Manager* getManager() { return this->manager; }

	Worker* getWorker() { return this->worker; }
private:
	Manager* manager;
	Worker* worker;
	std::mutex foodMutex;

	int manager1_id;
	int manager2_id;
	int worker1_id;
	int worker2_id;
	Boss* boss;
    */
};