#pragma once
#include "WorkStation.h"
#include "Worker.h"

class FoodStation : WorkStation
{
public:
	enum FoodStationState
	{
		IN_USE,
		FREE
	};
private:
	Manager* manager;
	Worker* worker;
};