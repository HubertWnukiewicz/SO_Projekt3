#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <ncurses.h>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <thread>
#include <functional>
#include <list>
#include <unistd.h>
#include <random>
#include <memory>
#include <cstdio>
#include <atomic>
#include "Viewer.h"
#include "TicketBooth.h"
#include "FoodStation.h"
#include "SodaStation.h"
#include "Toilet.h"
#include "ScreeingRoom.h"
//class Viewer;

class Window
{
    public:
        Window();

        void start();
        void drawScene();
        void redrawScene();
        void createOldViewerWindow(const int oldViewer,const int youngViewer);
        void createScreeningRoom(WINDOW *win);
        void createToilet(WINDOW *win);
        void createTicketOfficeStation(WINDOW *win,std::string stationName);
        void createWaitingRoom(WINDOW *win);
        void createLegend();
        void createTicketBoothQueue(WINDOW *win);

        virtual ~Window();

        std::thread screenThread;
    protected:
    private:
        std::list<Viewer*> viewerList;
};

#endif // WINDOW_H
