#include "FoodStation.h"
#include "Viewer.h"
void FoodStation::startFood(Viewer* viewer)
{
	//std::cout << "1. FoodStation" << std::endl;
	//(WorkStation)
	this->mutex.lock();
	viewer->setState(viewer->BUYING_FOOD);
	//std::cout<<"aaaaa"<<std::endl;
	//reinterpret_cast<WorkStation*>(this->mutex.lock());
	//std::cout << "2. FoodStation" << std::endl;
	//if (manager != nullptr && worker != nullptr)
	//zawolanie obiektu klasy Boss jesli nie ma managera o jego przybycie i wydanie sody


	//TO MUSI ZOSTAC
	
	if (manager == nullptr)
		this-> manager=this->boss->callForManager(this->manager_id,reinterpret_cast<WorkStation*>(this));

	//add random later worker1_id or worker2_id
	if (worker == nullptr)
		this->worker=this->boss->callForWorker(this->worker1_id,this->worker2_id,reinterpret_cast<WorkStation*>(this));

	

}
void FoodStation::stopFood(Viewer* viewer)
{
	//std::cout << "3. FoodStation" << std::endl;
	viewer->setWantFood(false);
	viewer->setState(viewer->WAITING_FOR_MOVIE);
	this->boss->dismissManager(this->manager_id,reinterpret_cast<WorkStation*>(this));
	this->boss->dismissWorker(this->worker->getId(),reinterpret_cast<WorkStation*>(this));
	manager=nullptr;
	worker=nullptr;
	this->mutex.unlock();
	//(WorkStation)this->mutex.unlock();
	//reinterpret_cast<WorkStation*>(this->mutex.unlock());
	//std::cout << "4. FoodStation" << std::endl;
}

FoodStation::FoodStation(int manager1_id, int worker_id, int worker2_id,Boss* boss) //:boss(boss)
{
	this->manager_id = manager1_id;
	this->worker1_id = worker_id;
	this->worker2_id = worker2_id;
	this->boss=boss;
}
