#include "Window.h"

Window::Window(std::vector<ScreeingRoom> screeningRooms)
{
    this->screeningRooms=screeningRooms;
    initscr();
}

void Window::drawScene()
{
    WINDOW *screeningRoomForOldViewers = newwin(9, 40, 4, 0);
    WINDOW *screeningRoomForYoungViewers = newwin(9, 40, 15, 0);

    createScreeningRoom(screeningRoomForOldViewers, 40);
    createScreeningRoom(screeningRoomForYoungViewers, 40);

    wrefresh(screeningRoomForOldViewers);
    wrefresh(screeningRoomForYoungViewers);
}

void Window::createOldViewerWindow(const int oldViewer,const int youngViewer)
{
    int height, width, start_y, start_x;
    height=2*oldViewer-1;
    width=40;
    start_x = 0;
    start_y = 4;
    WINDOW *win = newwin(height, width, start_y, start_x);
    box(win, 0, 0);
    //wattron(win, COLOR_PAIR(1));
    refresh();

    for(int i=0; i<oldViewer-1; i++){
        mvwhline(win,2+2*i,1,0,width-2);
        mvwprintw(win,1+2*i,1,"%d",i);
    }
    mvwvline(win,1,4,0,height-2);
    wrefresh(win);

    //start_color();
    //init_pair(1, COLOR_RED, COLOR_GREEN); /* create foreground / background combination */
    //attron(COLOR_PAIR(1)); /* use the above combination */
    //printw("%d",1);
    //attroff(COLOR_PAIR(1));
}

void Window::createScreeningRoom(WINDOW *win, int width)
{
    std::string a = "asfgd";
    const char * filmeName=a.c_str();

    
    start_color();  
    use_default_colors();
    init_pair(1, COLOR_RED, COLOR_WHITE); /* create foreground / background combination */
    init_pair(2, COLOR_WHITE, COLOR_RED);
    
    box(win, 0, 0);
    refresh();
    
    wmove(win,1,20-strlen(filmeName)/2);
    wattron(win,COLOR_PAIR(1));
    wprintw(win,filmeName);
    wattroff(win,COLOR_PAIR(1));

    for(int i=0; i<4; i++){
        mvwhline(win,2+2*i,1,0,width-2);
    }

    int row=0;
    int col=0;
    for(int i=0; i<35; i++)
    {
        wmove(win,3+row,2+col*3);
        wattron(win,COLOR_PAIR(2)); /* use the above combination */
        wprintw(win,"%d",i);
        wattroff(win,COLOR_PAIR(2));
        col++;

        if((2+col*3)>width-3){
            row= row + 2;
            col=0;
        }
    }
}


Window::~Window()
{
    //dtor
}
