#pragma once
#include "WorkStation.h"
#include "Worker.h"
#include "Viewer.h"
#include <vector>
class TicketBooth : WorkStation
{
public:
	enum TicketBoothState
	{
		IN_USE,
		FREE
	};

	void startTicket(Viewer viewer);

	void stopTicket(Viewer viewer);

	TicketBooth(Manager* manager, Worker* worker);

	Manager* getManager() { return this->manager; }

	Worker* getWorker() { return this->worker; }

private:
	int maxPeopleInQueue;
	std::vector<class Viewer*> viewersInQueue;
	Manager* manager;
	Worker* worker;
	std::mutex boothMutex;

	int manager_id;
	int worker_id1;
	int worker_id2;
};