#pragma once
#include "WorkStation.h"
#include "Worker.h"
#include "Boss.h"
#include <vector>

class Viewer;
class TicketBooth : WorkStation
{
public:
	enum TicketBoothState
	{
		IN_USE,
		FREE
	};

	void startTicket(Viewer* viewer);

	void stopTicket(Viewer* viewer);

	TicketBooth(int manager_id, int worker1_id, int worker2_id, Boss& boss);

	Manager* getManager() { return this->manager; }

	Worker* getWorker() { return this->worker; }

private:
	int maxPeopleInQueue;
	std::vector<class Viewer*> viewersInQueue;
	Manager* manager;
	Worker* worker;
	std::mutex boothMutex;
	Boss& boss;

	int manager_id;
	int worker1_id;
	int worker2_id;
};