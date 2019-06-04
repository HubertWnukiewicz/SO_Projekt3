#pragma once
#include "WorkStation.h"
#include "Worker.h"
#include "Boss.h"
//#include "Viewer.h"
class Viewer;

class SodaStation : public WorkStation
{
public:
	enum SodaStationState
	{
		IN_USE,
		FREE
	};
	void startSoda(Viewer* viewer);

	void stopSoda(Viewer* viewer);

	 explicit  SodaStation(int manager1_id, int worker1_id, int worker2_id, Boss* boss);// :WorkStation(manager1_id,worker1_id,worker2_id,boss) {}



	/*Manager* manager;
	Worker* worker;
	std::mutex sodaMutex;

	int manager1_id;
	int worker1_id;
	int worker2_id;
	Boss* boss;*/

};