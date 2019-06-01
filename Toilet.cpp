#include "Toilet.h"
#include "Viewer.h"

void Toilet::startToilet(Viewer * viewer)
{
//	std::cout << "1. Toilet" << std::endl;
	this->toiletMutex.lock();
	visitors.push_back(viewer);
//	std::cout << "2. Toilet" << std::endl;
	//else
	//add to Queue
}

void Toilet::stopToilet(Viewer * viewer)
{
//	std::cout << "3. Toilet" << std::endl;
	viewer->setWantToUseToilet(false);
	visitors.pop_back();
	this->toiletMutex.unlock();
//	std::cout << "4. Toilet" << std::endl;
}

Toilet::Toilet(int maxCapacity)
{
	this->maxCapacity = maxCapacity;
	this->state = ToiletState::FREE;
}
