#include "TicketBooth.h"
#include "Viewer.h"
void TicketBooth::startTicket(Viewer* viewer)
{
	//std::cout << "1. TicketBooth" << std::endl;
	//this->boothMutex.lock();
	//(WorkStation)
	//reinterpret_cast<WorkStation*>(this->mutex.lock());
	this->mutex.lock();
	//std::cout<<"ccccc"<<std::endl;
	viewer->setState(viewer->BUYING_TICKET);
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
TicketBooth::TicketBooth(int manager1_id, int worker1_id, int worker2_id, Boss* boss) //:WorkStation(manager1_id,worker1_id,worker2_id,boss) {}
{
	this->manager_id=manager1_id;
	this->worker1_id=worker1_id;
	this->worker2_id=worker2_id;
	this->boss=boss;
} 
void TicketBooth::stopTicket(Viewer* viewer)
{
//	std::cout << "3. TicketBooth" << std::endl;
	viewer->setHaveTicket(true);
	viewer->setState(viewer->WAITING_FOR_MOVIE);
	this->mutex.unlock();
	//reinterpret_cast<WorkStation*>(this->mutex.unlock());
	//(WorkStation)this->mutex.unlock();
	//this->boothMutex.unlock();
//	std::cout << "4. TicketBooth" << std::endl;

}
