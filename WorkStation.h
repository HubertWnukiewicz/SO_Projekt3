#pragma once
#include <iostream>
#include "Manager.h"

class Manager;


class WorkStation
{
	int id;
	std::string name;
	Manager* manager;

public:
	WorkStation();

	WorkStation(int id, std::string name, Manager* manager);


	
};