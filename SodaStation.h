#pragma once
#include "WorkStation.h"
#include "Worker.h"

class SodaStation : WorkStation
{
public:
	enum SodaStationState
	{
		IN_USE,
		FREE
	};
private:
	Manager* manager;
	Worker* worker;

};