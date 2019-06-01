#pragma once
#pragma once
#include "WorkStation.h"
#include "Worker.h"
#include "Boss.h"

class Viewer;
//Viewer*  a;

class Toilet : WorkStation
{
public:
	enum ToiletState
	{
		IN_USE,
		FREE
	};

	void startToilet(Viewer* viewer);

	void stopToilet(Viewer* viewer);

	Toilet(int maxCapacity);

	std::vector<class Viewer*> visitors;
private:

	ToiletState state;
	std::mutex toiletMutex;
	int maxCapacity;
};