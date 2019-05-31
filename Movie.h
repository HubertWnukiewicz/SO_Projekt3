#pragma once
#include <iostream>

class Movie {
	int id;
	std::string name;
	bool isForKids;

public:

	Movie();
	Movie(int id, std::string name, bool isForKids);

	int getId() { return this->id; }

	void setId(int id) { this->id = id; }

	std::string getName() { return this->name; }

	void setName(std::string name) { this->name = name; }

	bool getIsForKids() { return this->isForKids; }

	void setIsForKids(bool isForKids) { this->isForKids = isForKids; }
};