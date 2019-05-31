#include "Toilet.h"
#include "Viewer.h"

void Toilet::startToilet(Viewer * viewer)
{
	this->toiletMutex.lock();
	visitors.push_back(viewer);
	//else
	//add to Queue
}

void Toilet::stopToilet(Viewer * viewer)
{
	viewer->setSantToUseToilet(false);
	visitors.pop_back();
	this->toiletMutex.unlock();
}

Toilet::Toilet(int maxCapacity)
{
	this->maxCapacity = maxCapacity;
	this->state = ToiletState::FREE;
}
