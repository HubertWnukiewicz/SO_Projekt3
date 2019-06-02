#pragma once
//#include <deque>
#include <mutex>
#include <vector>
#include <condition_variable>
class Boss
{
	std::vector<class Worker *> workers;
	std::vector<class Manager *> managers;
	std::vector<class WorkStation *> stations;
	int numberOfWorkers;
	int numberOfManagers;
	//std::deque<class Worker *> workers;
	//std::deque<class Manager *> managers
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
};