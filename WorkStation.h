#pragma once
#include <iostream>
#include "Manager.h"

class Manager;


class WorkStation
{
	int id;
	std::string name;
	Manager* manager;
	int manager_id;
	int worker_id1;
	int worker_id2;


public:
	WorkStation();

	WorkStation(int id, std::string name, Manager* manager);


	
};