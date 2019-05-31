#include "FoodStation.h"
void FoodStation::sellFood(Viewer viewer)
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

FoodStation::FoodStation(Manager * manager, Worker * worker)
{
	this->manager = manager;
	this->worker = worker;
}
