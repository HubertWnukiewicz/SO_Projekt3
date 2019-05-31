#include "Boss.h"

Boss::Boss(std::deque<class Worker *> workers, std::deque<class Manager *> managers)
{
	this->workers = workers;
	this->managers = managers;
}

void Boss::callForManager(int id)
{
}
