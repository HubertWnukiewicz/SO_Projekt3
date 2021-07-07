#pragma once
#include <thread>
#include <random>
#include <memory>
#include <cstdio>
#include <atomic>
#include <functional>
#include "Movie.h"
#include "CheckTickets.h"
//#include "TicketBooth.h"

class TicketBooth;
class Toilet;
class FoodStation;
class SodaStation;
class CheckTickets;

class Viewer
{
public:
	enum ViewerState
	{
		WAITING_FOR_MOVIE,
		WAITING_FOR_FOOD,
		WAITING_FOR_SODA,
		WAITING_FOR_TOILET,
		WAITING_FOR_TICKET,
		WAITING_FOR_CHECK_TICKET,
		IN_TOILET,
		WATCHING_MOVIE,
		//IN_MOVIE,
		BUYING_FOOD,
		BUYING_SODA,
		BUYING_TICKET,
		CHECKING_TICKET,
		LEAVING_CINEMA
	};
	Viewer(const Viewer &);

	int getId() { return this->id; }

	void setId(int id) { this->id = id; }

	bool getIsAdult() { return this->isAdult; }

	void setIsAdult(bool isAdult) { this->isAdult = isAdult; }

	bool getWantFood() { return this->wantFood; }

	void setWantFood(bool wantFood) { this->wantFood = wantFood; }

	bool getWantSoda() { return this->wantSoda; }

	void setWantSoda(bool wantSoda) { this->wantSoda = wantSoda; }

	bool getHaveTicket() { return this->haveTicket; }

	void setHaveTicket(bool haveTicket) { this->haveTicket = haveTicket; }

	bool getWantToUseToilet() { return this->wantToUseToilet; }

	void setWantToUseToilet(bool wantToUseToilet) { this->wantToUseToilet = wantToUseToilet; }

	void setifTicketCheck(bool ifTicketCheck) { this->ifTicketCheck = ifTicketCheck; }

	bool getifTicketCheck() { return this->ifTicketCheck; }

	ViewerState getState() { return this->state; }

	void setReadyToWatch(bool readyToWatch) { this->readyToWatch=readyToWatch; }

	void setState(ViewerState state) { this->state = state; }

	Movie *getMovieToWatch() { return this->movieToWatch; }

	void setMovieToWatch(Movie* movieToWatch) { this->movieToWatch = movieToWatch; }

	Viewer(int id, bool isAdult, bool wantFood, bool wantSoda, bool wantToUseToilet ,Movie* movieToWatch,
		   TicketBooth *ticketBooth, Toilet *toilet, FoodStation *foodStation, SodaStation *sodaStation, CheckTickets *checkTicket);

	void cycleOfiLife();

	std::thread viewerThread;
	
private:
	int id;

	bool isAdult;
	bool wantFood;
	bool wantSoda;
	bool wantToUseToilet;
	bool haveTicket;
	bool readyToWatch;
	bool ifTicketCheck;

	Movie *movieToWatch;
	std::chrono::milliseconds activityTime;
	ViewerState state;
	TicketBooth *ticketBooth;
	Toilet *toilet;
	FoodStation *foodStation;
	SodaStation *sodaStation;
	CheckTickets *checkTicket;
};