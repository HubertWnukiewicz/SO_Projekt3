#include "Boss.h"
#include "Worker.h"
#include "Manager.h"
#include "CleanRoom.h"
#include "SodaStation.h"
#include "CheckTickets.h"
#include "TicketBooth.h"
#include "FoodStation.h"
#include "WorkStation.h"
Boss::Boss(int numberOfWorkers, int numberOfManagers) //: stations(stations)
{
	//std::deque<class Worker *>;
	this->workers = workers;
	this->managers = managers;
	this->foodStation=new FoodStation(0,0,6,this);
	this->sodaStation=new SodaStation(1,1,7,this);
	this->checkTickets=new CheckTickets(4,8,9,this);
	this->cleanRooms.push_back(new CleanRoom(2,2,8,this));
	this->cleanRooms.push_back(new CleanRoom(3,3,9,this));
	this->cleanRooms.push_back(new CleanRoom(4,4,5,this));
	this->ticketBooths.push_back(new TicketBooth(0,0,4,this));
	this->ticketBooths.push_back(new TicketBooth(1,1,5,this));
	this->ticketBooths.push_back(new TicketBooth(2,2,6,this));
	this->ticketBooths.push_back(new TicketBooth(3,3,7,this));


//(int id, WorkStation *firstStation, WorkStation *secondStation)
	workers.push_back(new Worker(0, reinterpret_cast<WorkStation*>(ticketBooths[0]) ,reinterpret_cast<WorkStation*>(foodStation))); //0
	workers.push_back(new Worker(1, reinterpret_cast<WorkStation*>(ticketBooths[1]) ,reinterpret_cast<WorkStation*>(sodaStation))); //1
	workers.push_back(new Worker(2, reinterpret_cast<WorkStation*>(ticketBooths[2]) ,reinterpret_cast<WorkStation*>(cleanRooms[0]))); //2
	workers.push_back(new Worker(3, reinterpret_cast<WorkStation*>(ticketBooths[3]) ,reinterpret_cast<WorkStation*>(cleanRooms[1])));   //3
	workers.push_back(new Worker(4, reinterpret_cast<WorkStation*>(ticketBooths[0]) ,reinterpret_cast<WorkStation*>(cleanRooms[2])));    //4
	workers.push_back(new Worker(5, reinterpret_cast<WorkStation*>(ticketBooths[1]) ,reinterpret_cast<WorkStation*>(cleanRooms[2])));    //5
	workers.push_back(new Worker(6, reinterpret_cast<WorkStation*>(ticketBooths[2]) ,reinterpret_cast<WorkStation*>(foodStation)));   //6
	workers.push_back(new Worker(7,reinterpret_cast<WorkStation*>(ticketBooths[3]) ,reinterpret_cast<WorkStation*>(sodaStation)));  //7
	workers.push_back(new Worker(8, reinterpret_cast<WorkStation*>(cleanRooms[0]) ,reinterpret_cast<WorkStation*>(checkTickets)));   //8
	workers.push_back(new Worker(9, reinterpret_cast<WorkStation*>(cleanRooms[1]) ,reinterpret_cast<WorkStation*>(checkTickets)));   //9

	managers.push_back(new Manager(0, reinterpret_cast<WorkStation*>(ticketBooths[0]) ,reinterpret_cast<WorkStation*>(foodStation))); //0
	managers.push_back(new Manager(1, reinterpret_cast<WorkStation*>(ticketBooths[1]) ,reinterpret_cast<WorkStation*>(sodaStation))); //1
	managers.push_back(new Manager(2, reinterpret_cast<WorkStation*>(ticketBooths[2]) ,reinterpret_cast<WorkStation*>(cleanRooms[0]))); //2
	managers.push_back(new Manager(3, reinterpret_cast<WorkStation*>(ticketBooths[3]) ,reinterpret_cast<WorkStation*>(cleanRooms[1])));   //3
	managers.push_back(new Manager(4, reinterpret_cast<WorkStation*>(checkTickets) ,reinterpret_cast<WorkStation*>(cleanRooms[2])));    //4
}

Boss::Boss()
{
	
}

Manager* Boss::callForManager(int id,WorkStation* workStation)
{
	this->bossMutex.lock();
	
	 for (Manager *el : managers)
	 {
		if(el->getId()==id )
		{
			el->setState(el->BUSY);
			el->changeWorkStation(workStation);
			return el;
		}
	 }
	 return nullptr;
}
void Boss::dismissManager(int id,WorkStation* workStation)
{
	for (Manager *el : managers)
	 {
		if(el->getId()==id )
		{
			el->changeWorkStation(nullptr);
			el->setState(el->FREE);
			this->bossMutex.unlock();
		}
	 }
}
void Boss::dismissWorker(int id,WorkStation* workStation)
{
	for (Worker *el : workers)
	 {
		if(el->getId()==id )
		{
			el->releaseCurrentStation();
			el->setState(el->FREE);
			this->bossMutex2.unlock();
		}
	 }
}
Worker* Boss::callForWorker(int id1, int id2,WorkStation* workStation)
{
	this->bossMutex2.lock();
	for (Worker *el : workers)
	{
		if(el->getId()==id1 && el->getState()==el->FREE)
		{
			el->changeWorkStation(workStation);
			return el;
		}
		if(el->getId()==id1 && el->getState()==el->FREE)
		{
			el->changeWorkStation(workStation);
			return el;
		}
	}
	for (Worker *el : workers)
	{
		if(el->getId()==id1 )
		{
			el->changeWorkStation(workStation);
			return el;
		}
	}
	return nullptr;
}
void Boss::start()
{
	for (Worker *el : workers)
	{
		el->workerThread.join();
	}
	for (Manager *el : managers)
	{
		el->managerThread.join();
	}
}