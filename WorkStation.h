#pragma once
#include <iostream>
#include "Manager.h"

class WorkStation
{
	int id;
	std::string name;
	Manager* manager;

public:
	WorkStation();

	WorkStation(int id, std::string name, Manager* manager);


	
};