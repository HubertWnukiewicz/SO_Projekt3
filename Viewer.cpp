#include "Viewer.h"


Viewer::Viewer(int id, bool isAdult, bool wantFood, bool wantSoda, bool wantToUseToilet, Movie movieToWatch)
{
	this->id = id;
	this->isAdult=isAdult;
	this->wantFood=wantFood;
	this->wantSoda = wantSoda;
	this->wantToUseToilet = wantToUseToilet;
	this->movieToWatch = movieToWatch;
	this->haveTicket = false;
	this->readyToWatch = false;
}

void Viewer::cycleOfiLife()
{
	if (this->wantFood == true)
	{
		this->state = ViewerState::WAITING_FOR_FOOD;
		//ustaw sie do kolejki z jedzeniem
	}
	if (this->wantSoda == true)
	{
		this->state = ViewerState::WAITING_FOR_SODA;
		//ustaw sie do kolejki z soda
	}
	if (this->wantToUseToilet == true)
	{
		this->state = ViewerState::WAITING_FOR_TOILET;
		//ustaw sie do kolejki do toalety
	}
	if (this->haveTicket == false)
	{
		this->state = ViewerState::WAITING_FOR_TICKET;
		//ustaw sie do kolejki po bilety
	}
	if (this->haveTicket == true && this->wantToUseToilet == false && this->wantSoda == false && this->wantFood == false)
	{
		this->readyToWatch = true;
		this->state = ViewerState::WAITING_FOR_MOVIE;
		
	}
	//ustalenie state na leaving cinema albo po utowrzeniu zmiennej bool dla viewera i zmiana jej w klasie sali kinowej lub ustawienie state w klasie kinowej bez tworzenia zminnej u widza 
}
