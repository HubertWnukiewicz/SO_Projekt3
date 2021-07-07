#pragma once
#include "WorkStation.h"
#include "Worker.h"
#include "Boss.h"
#include "Viewer.h"

class Viewer;

class CheckTickets :WorkStation
{
public:
	enum CheckTicketsState
	{
		IN_USE,
		FREE
	};

    CheckTickets(int manager1_id, int worker1_id, int worker2_id,Boss* boss);// :WorkStation(manager1_id,worker1_id,worker2_id,boss) {}

	void startCheckTicket(Viewer* viewer);

	void stopCheckTicket(Viewer* viewer);

	void startEnterRoom(Viewer *viewer);

	void stopEnterRoom(Viewer *viewer);


	//Manager* getManager() { return this->manager; }

	//Worker* getWorker() { return this->worker; }
	
private:
	std::vector<class Viewer *> visitors;
	int maxPeopleInQueue;
	std::vector<class Viewer*> viewersInQueue;
	/*

    CheckTickets(int manager1_id, int worker1_id, int worker2_id,Boss* boss);// :WorkStation(manager1_id,worker1_id,worker2_id,boss) {}
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