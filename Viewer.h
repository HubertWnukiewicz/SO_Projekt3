#pragma once
#include <thread>
#include <random>
#include <memory>
#include <cstdio>
#include <atomic>
#include <functional>
#include <condition_variable>

class Viewer
{
public:
	enum ViewerState
	{
		activity1,
		activity2,
		activity3,
		activity4,
		activity5
	};
private:
	int id;
	bool isAdult;
	bool wantFood;
	bool wantSoda;
	std::thread thread;
	std::chrono::milliseconds activityTime;
	ViewerState nextState;

};