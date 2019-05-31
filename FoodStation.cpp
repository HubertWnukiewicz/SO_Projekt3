#include "FoodStation.h"
#include "Viewer.h"
void FoodStation::startFood(Viewer* viewer)
{
	this->foodMutex.lock();
	//if (manager != nullptr && worker != nullptr)
	//zawolanie obiektu klasy Boss jesli nie ma managera o jego przybycie i wydanie sody
	if (manager == nullptr)
		this->boss.callForManager(this->manager_id);

	//add random later worker1_id or worker2_id
	if (worker == nullptr)
		this->boss.callForManager(this->worker1_id);
}
void FoodStation::stopFood(Viewer* viewer)
{
	viewer->setWantFood(false);
	this->foodMutex.unlock();
}

FoodStation::FoodStation(int manager_id, int worker_id, int worker2_id,Boss& boss) :boss(boss)
{
	this->manager_id = manager_id;
	this->worker1_id = worker_id;
	this->worker2_id = worker2_id;
}
