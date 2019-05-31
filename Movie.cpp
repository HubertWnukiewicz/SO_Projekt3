#include "Movie.h"

Movie::Movie()
{
	
}

Movie::Movie(int id, std::string name, bool isForKids)
{
	this->id = id;
	this->name = name;
	this->isForKids = isForKids;
}
