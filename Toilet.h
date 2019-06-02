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

	void startToilet(Viewer *viewer);

	void stopToilet(Viewer *viewer);

	Toilet(int maxCapacity);

	std::vector<class Viewer *> visitors;

private:
	ToiletState state;
	std::mutex toiletMutex;
	std::mutex cabine0Mutex;
	std::mutex cabine1Mutex;
	std::mutex cabine2Mutex;
	std::mutex cabine3Mutex;
	int maxCapacity;
};