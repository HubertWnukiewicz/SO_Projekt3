#ifndef WINDOW_H
#define WINDOW_H

#include<iostream>
#include <ncurses.h>
#include <string.h>
#include <stdio.h>
#include <vector>
#include "ScreeingRoom.h"


class Window
{
    public:
        Window();

        void drawScene();
        void createOldViewerWindow(const int oldViewer,const int youngViewer);
        void createScreeningRoom(WINDOW *win, int width);
        void createToilet(WINDOW *win);
        void createTicketOfficeStation(WINDOW *win,std::string stationName);
        void createWaitingRoom(WINDOW *win);
        void createLegend();

        virtual ~Window();
    protected:
    private:
        std::vector<ScreeingRoom> screeningRooms;
};

#endif // WINDOW_H
