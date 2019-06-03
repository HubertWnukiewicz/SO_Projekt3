#include "CleanRoom.h"

CleanRoom::CleanRoom(int manager1_id, int worker_id, int worker2_id,Boss* boss) //:boss(boss)
{
	this->manager_id = manager1_id;
	this->worker1_id = worker_id;
	this->worker2_id = worker2_id;
    this->boss=boss;
}
