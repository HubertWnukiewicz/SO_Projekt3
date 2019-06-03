#pragma once
//#include <deque>
#include <mutex>
#include <vector>
#include <condition_variable>
class CheckTickets;
class CleanRoom;
class FoodStation;
class SodaStation;

class Boss
{
	std::vector<class Worker *> workers;
	std::vector<class Manager *> managers;
	int numberOfWorkers;
	int numberOfManagers;
	std::vector<class CleanRoom*> cleanRooms;
	std::vector<class TicketBooth *> ticketBooths;
	FoodStation* foodStation;
	SodaStation* sodaStation;
	CheckTickets* checkTickets;
	std::mutex bossMutex;
	std::condition_variable cv;

public:
	Boss(int numberOfWorkers, int numberOfManagers);

	Boss();

	void callForManager(int id);

	void callForWorker(int id1, int id2);

	int getNumberOfWorkers() { return this->numberOfWorkers; }

	int getNumberOfManagers() { return this->numberOfManagers; }

	std::vector<class Manager *> getManagers() { return this->managers; }

	std::vector<class Worker *> getWorkers() { return this->workers; }

	std::vector<class CleanRoom *> getRoomsToClean() { return this->cleanRooms; }

	std::vector<class TicketBooth *> getTicketBooths() { return this->ticketBooths; }

	FoodStation* getFoodStation() {return this->foodStation;}

	SodaStation* getSodaStation() {return this->sodaStation;}

	CheckTickets* getCheckTickets() {return this->checkTickets;}
};