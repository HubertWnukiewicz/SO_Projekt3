#include "CheckTickets.h"

CheckTickets::CheckTickets(int manager1_id, int worker_id, int worker2_id,Boss* boss)
{
	this->manager_id = manager1_id;
	this->worker1_id = worker_id;
	this->worker2_id = worker2_id;
    this->boss=boss;

	this->visitors.reserve(2);
	this->visitors[0]=nullptr;
	this->visitors[1]=nullptr;
}

void CheckTickets::startEnterRoom(Viewer *viewer){

	for (int i = 0; i < 2; i++)
	{
		if (this->visitors[i] == nullptr)
		{
			if (i == 0)
			{
			//	this->cabine0Mutex.lock();
				viewer->setState(viewer->WATCHING_MOVIE);
				//this->visitors.insert(this->visitors.begin() + i, viewer);
				this->visitors[i]=viewer;
				return;
			}
			else if (i == 1)
			{
			//	this->cabine1Mutex.lock();
				viewer->setState(viewer->WATCHING_MOVIE);
				//this->visitors.insert(this->visitors.begin() + i, viewer);
				this->visitors[i]=viewer;
				return;
			}
		}
	}
}

void CheckTickets::stopEnterRoom(Viewer *viewer){

	for (int i = 0; i < 2; i++)
	{
		if (this->visitors[i] == viewer)
		{
			if (i == 0)
			{
				viewer->setReadyToWatch(true);
				//viewer->setState(viewer->WATCHING_MOVIE);
				this->visitors[i]=nullptr;
				return;
			}
			else if (i == 1)
			{
				viewer->setReadyToWatch(true);
				//viewer->setState(viewer->WATCHING_MOVIE);
				this->visitors[i]=nullptr;
				return;
			}
		}
	}
}

void CheckTickets::startCheckTicket(Viewer* viewer){

	this->mutex.lock();

	viewer->setState(viewer->CHECKING_TICKET);
}

void CheckTickets::stopCheckTicket(Viewer* viewer){
	viewer->setifTicketCheck(true);
	viewer->setState(viewer->LEAVING_CINEMA);
	this->mutex.unlock();
}