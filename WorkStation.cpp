#include "WorkStation.h"

WorkStation::WorkStation()
{
	id = 0;
	name = "WorkStation";
	manager = nullptr;
}
WorkStation::WorkStation(int id, std::string name, Manager* manager)
{
	this->id = id;
	this->name = name;
	this->manager = manager;
}