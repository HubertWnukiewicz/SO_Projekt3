#include "Viewer.h"
#include "FoodStation.h"
#include "SodaStation.h"
#include "TicketBooth.h"
#include "Toilet.h"
#include <thread>
using namespace std;
Viewer::Viewer(const Viewer &)
{
}
Viewer::Viewer(int id, bool isAdult, bool wantFood, bool wantSoda, bool wantToUseToilet, Movie movieToWatch, TicketBooth *ticketBooth, Toilet *toilet, FoodStation *foodStation, SodaStation *sodaStation) : foodStation(foodStation), sodaStation(sodaStation)
{
	this->id = id;
	this->isAdult = isAdult;
	this->wantFood = wantFood;
	this->wantSoda = wantSoda;
	this->wantToUseToilet = wantToUseToilet;
	this->movieToWatch = movieToWatch;
	this->haveTicket = false;
	this->readyToWatch = false;

	this->ticketBooth = ticketBooth;
	this->toilet = toilet;
	this->foodStation = foodStation;
	this->sodaStation = sodaStation;
	this->state = ViewerState::WAITING_FOR_MOVIE;
	this->viewerThread = thread(&Viewer::cycleOfiLife, this);
}

void Viewer::cycleOfiLife()
{
	
	while (true) {
	this_thread::sleep_for(1000ms);
	if (this->wantToUseToilet == true)
	{
		//cout << "ID: " << this->id << "->WAITING_FOR_TOILET" << endl;
		this->state = ViewerState::WAITING_FOR_TOILET;
		toilet->startToilet(this);
		this_thread::sleep_for(1000ms);
		toilet->stopToilet(this);
	}
	if (this->wantFood == true)
	{
		//cout << "ID: " << this->id << "->WAITING_FOR_FOOD" << endl;
		this->state = ViewerState::WAITING_FOR_FOOD;
		foodStation->startFood(this);
		this_thread::sleep_for(1000ms);
		foodStation->stopFood(this);
	}
	if (this->wantSoda == true)
	{
		//cout << "ID: " << this->id << "->WAITING_FOR_SODA" << endl;
		this->state = ViewerState::WAITING_FOR_SODA;
		sodaStation->startSoda(this);
		this_thread::sleep_for(1000ms);
		sodaStation->stopSoda(this);
	}
	
	if (this->haveTicket == false)
	{
		//cout << "ID: " << this->id << "->WAITING_FOR_TICKET" << endl;
		this->state = ViewerState::WAITING_FOR_TICKET;
		ticketBooth->startTicket(this);
		this_thread::sleep_for(1500ms);
		ticketBooth->stopTicket(this);
	}
	if (this->haveTicket == true && this->wantToUseToilet == false && this->wantSoda == false && this->wantFood == false)
	{
		//cout << "ID: " << this->id << "->WAITING_FOR_MOVIE" << endl;
		this->readyToWatch = true;
		this->state = ViewerState::WAITING_FOR_MOVIE;
	}
	}
	//ustalenie state na leaving cinema albo po utowrzeniu zmiennej bool dla viewera i zmiana
	//jej w klasie sali kinowej lub ustawienie state w klasie kinowej bez tworzenia zminnej u widza
}
