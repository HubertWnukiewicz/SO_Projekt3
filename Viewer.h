#pragma once
#include <thread>
#include <random>
#include <memory>
#include <cstdio>
#include <atomic>
#include <functional>
#include <condition_variable>
#include "Movie.h"

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

	bool setWantFood(bool wantFood) { this->wantFood=wantFood; }

	bool getWantSoda() { return this->wantSoda; }

	bool setWantSoda(bool wantSoda) { this->wantSoda = wantSoda; }

	Movie getMovieToWatch() { return this->movieToWatch; }

	void setMovieToWatch(Movie movieToWatch) {this->movieToWatch=movieToWatch; }

	Viewer(int id, bool isAdult, bool wantFood, bool wantSoda, bool wantToUseToilet, Movie movieToWatch);

	void cycleOfiLife();

	
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

};