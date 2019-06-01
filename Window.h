#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <ncurses.h>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <thread>
#include <list>
#include <unistd.h>
#include "Viewer.h"
#include "ScreeingRoom.h"
//class Viewer;

class Window
{
    public:
        Window(std::list<Viewer> _viewerList);

        void drawScene();
        void redrawScene();
        void createOldViewerWindow(const int oldViewer,const int youngViewer);
        void createScreeningRoom(WINDOW *win, int width);
        void createToilet(WINDOW *win);
        void createTicketOfficeStation(WINDOW *win,std::string stationName);
        void createWaitingRoom(WINDOW *win);
        void createLegend();

        virtual ~Window();

        std::thread screenThread;
    protected:
    private:
        std::list<Viewer> viewerList;
};

#endif // WINDOW_H
