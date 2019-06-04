#include "ScreeingRoom.h"
#include "Viewer.h"

ScreeingRoom::ScreeingRoom(int id, int numberOfSeats, Movie* movie, Boss *boss)
{
	this->id = id;
	this->numberOfSeats = numberOfSeats;
	this->movie = movie;
	this->currentNumberOfViewers = 0;
	this->boss=boss;
}

void ScreeingRoom::startWatchingMovie(Viewer *viewer)
{
	this->mutex.lock();

	viewer->setState(viewer->WATCHING_MOVIE);
	viewer->setReadyToWatch(true);
}

void ScreeingRoom::stopWatchingMovie(Viewer *viewer)
{
	viewer->setState(viewer->LEAVING_CINEMA);
	this->mutex.unlock();
}

void ScreeingRoom::startMovie()
{
	this->state= ScreeingRoomState::IN_PROGRESS;
	//lock mutexa
	//losuj czas i wykonuj sie
	if (this->currentNumberOfViewers > 0)
	{
		this->state = ScreeingRoomState::VIEWERS_LEAVING;
		//this->currentNumberOfViewers-- per 0.01s na przyklad
	}		
}

void ScreeingRoom::callForCleaning()
{
	this->state = ScreeingRoomState::WAITING_FOR_CLEANING;
	//lock
	//losowanie czasu sprzatania
	//zalezy czy pracownik jest przypisany tylko do jednej pracy czy do kilku jak do kilku to czeka na jego przybycie wczesniej
	if (/*przyjdzie pracownik*/true)
	{
		this->state = ScreeingRoomState::CLEANING;
	}

}
