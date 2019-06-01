#include "TicketBooth.h"
#include "Viewer.h"
void TicketBooth::startTicket(Viewer* viewer)
{
	//std::cout << "1. TicketBooth" << std::endl;
	this->boothMutex.lock();
	//std::cout << "2. TicketBooth" << std::endl;
	//TO MUSI ZOSTAC
	/*
	if (manager == nullptr)
		this->boss.callForManager(this->manager_id);

	//add random later worker1_id or worker2_id
	if (worker == nullptr)
		this->boss.callForManager(this->worker1_id);
	*/
}
void TicketBooth::stopTicket(Viewer* viewer)
{
//	std::cout << "3. TicketBooth" << std::endl;
	viewer->setHaveTicket(true);
	this->boothMutex.unlock();
//	std::cout << "4. TicketBooth" << std::endl;

}

TicketBooth::TicketBooth(int manager_id, int worker1_id, int worker2_id, Boss& boss) :boss(boss)
{
	this->manager_id = manager_id;
	this->worker1_id = worker1_id;
	this->worker2_id= worker2_id;
}
