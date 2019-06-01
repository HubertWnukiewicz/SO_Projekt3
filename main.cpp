#include <iostream>
#include"stdio.h"
#include"Window.h"
#include "Viewer.h"
#include "Boss.h"
#include "TicketBooth.h"
#include "FoodStation.h"
#include "SodaStation.h"
#include "Toilet.h"
#include <list>
using namespace std;
class TicketBooth;

int main()
{
    const int NUM_OF_OLD_VIEWERS = 22;
    const int NUM_OF_YOUNG_VIEWERS = 20;
	list<Viewer> viewers;
	Boss boss;
	//vector<thread> philosopherThreads;
	TicketBooth* ticketBooth=new TicketBooth(0,1,2,boss);
	Toilet* toilet=new Toilet(10);
	FoodStation* foodStation=new FoodStation(0, 1, 2, boss);
	SodaStation* sodaStation=new SodaStation(0, 1, 2, boss);
	Movie movie(1, "aaa", true);
	for (int i = 0; i < 2; i++)
	{
		viewers.emplace_back(i, false, true, true, true, movie, ticketBooth, toilet, foodStation, sodaStation);
	}

	Window *window = new Window(viewers);

	for (auto &viewer : viewers)
	{
		viewer.viewerThread.join();
	}

	window->screenThread.join();

	cout << "Ilosc elementow: " << viewers.size() << endl;
    //Window window = Window();
   // window.drawScene();
	//Viewer(int id, bool isAdult, bool wantFood, bool wantSoda, bool wantToUseToilet, Movie movieToWatch,
	//TicketBooth* ticketBooth, Toilet* toilet, FoodStation* foodStation, SodaStation* sodaStation);
    //while(getch()!='k');
	cin.ignore(2);

    return 0;
}
