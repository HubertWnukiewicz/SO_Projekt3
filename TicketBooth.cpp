#include "TicketBooth.h"

void TicketBooth::startTicket(Viewer viewer)
{
	this->boothMutex.lock();
	
}
void TicketBooth::stopTicket(Viewer viewer)
{

	this->boothMutex.unlock();


}

TicketBooth::TicketBooth(Manager * manager, Worker * worker)
{
	this->manager = manager;
	this->worker = worker;
}
