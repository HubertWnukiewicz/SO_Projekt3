#include "Viewer.h"
#include "FoodStation.h"
#include "SodaStation.h"
#include "Toilet.h"
#include <thread>
using namespace std;
Viewer::Viewer(int id, bool isAdult, bool wantFood, bool wantSoda, bool wantToUseToilet, Movie movieToWatch, TicketBooth* ticketBooth, Toilet* toilet, FoodStation* foodStation, SodaStation* sodaStation) :foodStation(foodStation)
{
	this->id = id;
	this->isAdult=isAdult;
	this->wantFood=wantFood;
	this->wantSoda = wantSoda;
	this->wantToUseToilet = wantToUseToilet;
	this->movieToWatch = movieToWatch;
	this->haveTicket = false;
	this->readyToWatch = false;
	
	this->ticketBooth = ticketBooth;
	this->toilet = toilet;
	this->foodStation = foodStation;
	this->sodaStation = sodaStation;
}

void Viewer::cycleOfiLife()
{
	if (this->wantFood == true)
	{
		this->state = ViewerState::WAITING_FOR_FOOD;
		foodStation->startFood(this);
		this_thread::sleep_for(20ms);
		foodStation->stopFood(this);
	}
	if (this->wantSoda == true)
	{
		this->state = ViewerState::WAITING_FOR_SODA;
		sodaStation->startSoda(this);
		this_thread::sleep_for(20ms);
		sodaStation->stopSoda(this);
	}
	if (this->wantToUseToilet == true)
	{
		this->state = ViewerState::WAITING_FOR_TOILET;
		toilet->startToilet(this);
		this_thread::sleep_for(20ms);
		toilet->stopToilet(this);
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
