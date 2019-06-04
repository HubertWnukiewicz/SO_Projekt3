#pragma once
#include "Movie.h"
#include "Boss.h"
#include <vector>
class Movie;
class Viewer;

class ScreeingRoom
{
	enum ScreeingRoomState {
		WAITING_FOR_VIEWERS,
		WAITING_FOR_CLEANING,
		IN_PROGRESS,
		CLEANING,
		VIEWERS_LEAVING
	};
	int id;
	int currentNumberOfViewers;
	int numberOfSeats;
	Movie *movie;
	std::vector<class Viewer*> viewers;
	ScreeingRoomState state;
	Boss *boss;

	int manager1_id;
	int manager2_id;
	int worker1_id;
	int worker2_id;

	std::mutex mutex;


public:

	ScreeingRoom(int id, int numberOfSeats, Movie* movie, Boss *boss);

	//boss mowi kiedy film sie zaczyna?
	void startMovie();

	void callForCleaning();

	void startWatchingMovie(Viewer* viewer);

	void stopWatchingMovie(Viewer* viewer);

	//--------------------------------------------------------------------------------------//
	int getId() { return this->id; }

	void setId(int id) { this->id = id; }

	int getCurrentNumberOfViewers() { return this->currentNumberOfViewers; }

	void setCurrentNumberOfViewers(int currentNumberOfViewers) { this->currentNumberOfViewers = currentNumberOfViewers; }

	int getNumberOfSeats() { return this->numberOfSeats; }

	void setNumberOfSeats(int numberOfSeats) { this->numberOfSeats = numberOfSeats; }

	Movie* getMovie() { return this->movie; }

	void setMovie(Movie* movie) { this->movie = movie; }

	ScreeingRoomState getState() { return this->state; }

	void setState(ScreeingRoomState state) { this->state = state; }

	void setBoss(Boss* boss) { this->boss=boss; }

	Boss* getBoss() { return this->boss; }

};