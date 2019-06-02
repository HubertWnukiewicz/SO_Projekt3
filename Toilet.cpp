#include "Toilet.h"
#include "Viewer.h"

void Toilet::startToilet(Viewer *viewer)
{
	if (this->visitors.size() + 1 < 4)
		this->toiletMutex.lock();

	for (int i = 0; i < 4; i++)
	{
		if (this->visitors[i] == nullptr)
		{
			if (i == 0)
			{
				this->cabine0Mutex.lock();
				viewer->setState(viewer->IN_TOILET);
				this->visitors.insert(this->visitors.begin() + i, viewer);
				return;
			}
			else if (i == 1)
			{
				this->cabine1Mutex.lock();
				viewer->setState(viewer->IN_TOILET);
				this->visitors.insert(this->visitors.begin() + i, viewer);
				return;
			}
			else if (i == 2)
			{
				this->cabine2Mutex.lock();
				viewer->setState(viewer->IN_TOILET);
				this->visitors.insert(this->visitors.begin() + i, viewer);
				return;
			}
			else if (i == 3)
			{
				this->cabine3Mutex.lock();
				viewer->setState(viewer->IN_TOILET);
				this->visitors.insert(this->visitors.begin() + i, viewer);
				return;
			}
		}
	}

	//	std::cout << "2. Toilet" << std::endl;
	//else
	//add to Queue
}

void Toilet::stopToilet(Viewer *viewer)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->visitors[i] == viewer)
		{
			viewer->setWantToUseToilet(false);

			if (i == 0)
			{
				this->visitors.erase(this->visitors.begin() + i);
				this->cabine0Mutex.unlock();
				this->toiletMutex.unlock();
				return;
			}
			else if (i == 1)
			{
				this->visitors.erase(this->visitors.begin() + i);
				this->cabine1Mutex.unlock();
				this->toiletMutex.unlock();
				return;
			}
			else if (i == 2)
			{
				this->visitors.erase(this->visitors.begin() + i);
				this->cabine2Mutex.unlock();
				this->toiletMutex.unlock();
				return;
			}
			else if (i == 3)
			{
				this->visitors.erase(this->visitors.begin() + i);
				this->cabine3Mutex.unlock();
				this->toiletMutex.unlock();
				return;
			}
		}
	}
	//	std::cout << "3. Toilet" << std::endl;
	//	std::cout << "4. Toilet" << std::endl;
}

Toilet::Toilet(int maxCapacity)
{
	this->maxCapacity = maxCapacity;
	visitors.reserve(4);
	this->state = ToiletState::FREE;
}
