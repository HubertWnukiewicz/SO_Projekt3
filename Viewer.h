#pragma once
#include <thread>
#include <random>
#include <memory>
#include <cstdio>
#include <atomic>
#include <functional>
#include "Movie.h"
//#include "TicketBooth.h"

class TicketBooth;
class Toilet;
class FoodStation;
class SodaStation;

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
		IN_TOILET,
		WATCHING_MOVIE,
		LEAVING_CINEMA
	};

	int getId() { return this->id; }

	void setId(int id) { this->id = id; }

	bool getIsAdult() { return this->isAdult; }

	void setIsAdult(bool isAdult) { this->isAdult=isAdult; }

	bool getWantFood() { return this->wantFood; }

	void setWantFood(bool wantFood) { this->wantFood=wantFood; }

	bool getWantSoda() { return this->wantSoda; }

	void setWantSoda(bool wantSoda) { this->wantSoda = wantSoda; }

	bool getSantToUseToilet() { return this->wantToUseToilet; }

	void setSantToUseToilet(bool wantToUseToilet) { this->wantToUseToilet = wantToUseToilet; }

	Movie getMovieToWatch() { return this->movieToWatch; }

	void setMovieToWatch(Movie movieToWatch) {this->movieToWatch=movieToWatch; }

	Viewer(int id, bool isAdult, bool wantFood, bool wantSoda, bool wantToUseToilet, Movie movieToWatch,
		TicketBooth* ticketBooth, Toilet* toilet, FoodStation* foodStation, SodaStation* sodaStation);

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

	Movie movieToWatch;
	std::chrono::milliseconds activityTime;
	ViewerState state;

	TicketBooth* ticketBooth;
	Toilet* toilet;
	FoodStation* foodStation;
	SodaStation* sodaStation;

	
};