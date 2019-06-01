#include "FoodStation.h"
#include "Viewer.h"
void FoodStation::startFood(Viewer* viewer)
{
	//std::cout << "1. FoodStation" << std::endl;
	this->foodMutex.lock();
	//std::cout << "2. FoodStation" << std::endl;
	//if (manager != nullptr && worker != nullptr)
	//zawolanie obiektu klasy Boss jesli nie ma managera o jego przybycie i wydanie sody


	//TO MUSI ZOSTAC
	/*
	if (manager == nullptr)
		this->boss.callForManager(this->manager_id);

	//add random later worker1_id or worker2_id
	if (worker == nullptr)
		this->boss.callForManager(this->worker1_id);
	*/

}
void FoodStation::stopFood(Viewer* viewer)
{
	//std::cout << "3. FoodStation" << std::endl;
	viewer->setWantFood(false);
	this->foodMutex.unlock();
	//std::cout << "4. FoodStation" << std::endl;
}

FoodStation::FoodStation(int manager_id, int worker_id, int worker2_id,Boss& boss) :boss(boss)
{
	this->manager_id = manager_id;
	this->worker1_id = worker_id;
	this->worker2_id = worker2_id;
}
