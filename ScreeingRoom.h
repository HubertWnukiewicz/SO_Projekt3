#pragma once
#include "Movie.h"
class Movie;

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
	Movie movie;
	ScreeingRoomState state;
	//Boss& boss

public:

	ScreeingRoom(int id, int numberOfSeats, Movie movie);

	//boss mowi kiedy film sie zaczyna?
	void startMovie();

	void callForCleaning();

	//--------------------------------------------------------------------------------------//
	int getId() { return this->id; }

	void setId(int id) { this->id = id; }

	int getCurrentNumberOfViewers() { return this->currentNumberOfViewers; }

	void setCurrentNumberOfViewers(int currentNumberOfViewers) { this->currentNumberOfViewers = currentNumberOfViewers; }

	int getNumberOfSeats() { return this->numberOfSeats; }

	void setNumberOfSeats(int numberOfSeats) { this->numberOfSeats = numberOfSeats; }

	Movie getMovie() { return this->movie; }

	void setNumberOfSeats(Movie movie) { this->movie = movie; }

	ScreeingRoomState getState() { return this->state; }

	void setState(ScreeingRoomState state) { this->state = state; }

};