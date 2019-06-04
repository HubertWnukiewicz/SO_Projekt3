#include "SodaStation.h"
#include "Viewer.h"
/*
void SodaStation::sellSoda(Viewer viewer)
{
	//if (manager != nullptr && worker != nullptr)
	//zawolanie obiektu klasy Boss jesli nie ma managera o jego przybycie i wydanie sody

	if (viewer.getWantSoda() == true)
	{
		//TODO lock zmiennej warunkowej
		viewer.setWantSoda(false);
		//TODO unlock zmiennej warunkowej
	}
}

SodaStation::SodaStation(Manager* manager, Worker* worker)
{
	this->manager = manager;
	this->worker = worker;
}*/

void SodaStation::startSoda(Viewer* viewer)
{
	//std::cout << "1. SodaStation" << std::endl;
	//(WorkStation*)this->mutex.lock();
	this->mutex.lock();
	//std::cout<<"bbbb"<<std::endl;
	//reinterpret_cast<WorkStation*>(this->mutex.lock());
	viewer->setState(viewer->BUYING_SODA);
	//if (manager != nullptr && worker != nullptr)
	//zawolanie obiektu klasy Boss jesli nie ma managera o jego przybycie i wydanie sody
	/*
	if (manager == nullptr)
		this->boss.callForManager(this->manager_id);

	//add random later worker1_id or worker2_id
	if (worker == nullptr)
		this->boss.callForManager(this->worker1_id);
	*/
	//std::cout << "2. SodaStation" << std::endl;
}
void SodaStation::stopSoda(Viewer* viewer)
{
	//std::cout << "3. SodaStation" << std::endl;
	viewer->setWantSoda(false);
	viewer->setState(viewer->WAITING_FOR_MOVIE);
	this->mutex.unlock();
	//reinterpret_cast<WorkStation*>(this->mutex.unlock());
	//(WorkStation)this->mutex.unlock();
	//std::cout << "4. SodaStation" << std::endl;
}


SodaStation::SodaStation(int manager1_id, int worker_id, int worker2_id, Boss* boss)
{
	this->manager_id = manager1_id;
	this->worker1_id = worker_id;
	this->worker2_id = worker2_id;
	this->boss=boss;
}
