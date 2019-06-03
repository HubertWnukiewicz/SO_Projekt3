#include "Window.h"
#include "Boss.h"
Window::Window()
{

    //this->viewerList=_viewerList;
    //SALA 1 -DOROSLI
    //SALA 2 -WSZYSCY
    //SALA 3 -WSZYSCY

    Boss* boss=new Boss(10,5);
    //Boss* boss=new Boss();
    //TicketBooth *ticketBooth = new TicketBooth(0, 1, 2, boss);
    Toilet *toilet = new Toilet(4);
    //Toilet *toilet2 = new Toilet(4);
    //FoodStation *foodStation = new FoodStation(0,1, 2, boss);
    //SodaStation *sodaStation = new SodaStation(0,1, 2, boss);
    //int id, bool isAdult, bool wantFood, bool wantSoda, bool wantToUseToilet, Movie movieToWatch, TicketBooth *ticketBooth,
    // Toilet *toilet, FoodStation *foodStation, SodaStation *sodaStation) : foodStation(foodStation), sodaStation(sodaStation
    Movie movie(1, "aaa", true);
    for (int i = 0; i < 30; i++)
    {
        viewerList.push_back(new Viewer(i, false, true, true, true, movie, boss->getTicketBooths()[0] , toilet,boss->getFoodStation(), boss->getSodaStation()));
        //viewerList.push_back(new Viewer(i, false, true, true, true, movie, ticketBooth , toilet,foodStation, sodaStation));
    }
    

    initscr();
    start_color();
    use_default_colors();
    init_pair(1, COLOR_RED, COLOR_WHITE);  //tytul filmu
    init_pair(2, COLOR_WHITE, COLOR_RED);  //dorosli widzowie
    init_pair(3, COLOR_RED, COLOR_GREEN);  //mlodzi widzowie  RED, GREEN
    init_pair(4, COLOR_WHITE, COLOR_BLUE); //pracownicy
    init_pair(5, COLOR_RED, COLOR_YELLOW); //kierownicy

    for (Viewer *el : viewerList)
    {
        //    printw("%d\n",el->getId());
    }
}

void Window::start()
{
    this->screenThread = std::thread(&Window::drawScene, this);
    for (auto *viewer : viewerList)
    {
        viewer->viewerThread.join();
    }
    this->screenThread.join();
}

void Window::drawScene()
{
    while (true)
    {
        redrawScene();
        usleep(350000);
        //std::this_thread::sleep_for(1000ms);
        //clear();
    }
}

void Window::redrawScene()
{
    const int TICKETOFFICE_STATION_NUMBER = 4;

    /////////////////WINDOWS INITIALIZATION//////////////////////////
    WINDOW *ticketOfficeStation[TICKETOFFICE_STATION_NUMBER];
    WINDOW *screeningRoomForOldViewers = newwin(9, 40, 4, 0);
    WINDOW *screeningRoomForYoungViewers = newwin(9, 40, 15, 0);
    WINDOW *screeningRoomForEveryoneViewers = newwin(9, 40, 26, 0);
    WINDOW *toiletWindow = newwin(5, 17, 37, 10);
    WINDOW *checkTicketStation = newwin(5, 21, 2, 105);
    WINDOW *popcornStation = newwin(5, 9, 40, 140);
    WINDOW *sodaStation = newwin(5, 9, 40, 160);
    WINDOW *waitingRoom = newwin(11, 70, 17, 80);
    for (int i = 0; i < TICKETOFFICE_STATION_NUMBER; i++)
        ticketOfficeStation[i] = newwin(5, 9, 40, 60 + i * 20);
    ///////////////////////////////////////////////////////////////////
    //
    //
    /////////////////CREATING WINDOWS STRUCTURE////////////////////////
    createScreeningRoom(screeningRoomForOldViewers);
    createScreeningRoom(screeningRoomForYoungViewers);
    createScreeningRoom(screeningRoomForEveryoneViewers);
    createToilet(toiletWindow);
    createTicketOfficeStation(popcornStation, "Popcorn");
    createTicketOfficeStation(sodaStation, "Napoje");
    createTicketOfficeStation(checkTicketStation, "Sprawdzanie biletow");
    createWaitingRoom(waitingRoom);
    createLegend();
    for (int i = 0; i < TICKETOFFICE_STATION_NUMBER; i++)
    {
        std::string str = "Kasa#";
        str += std::to_string(i);
        createTicketOfficeStation(ticketOfficeStation[i], str);
    }
    ////////////////////////////////////////////////////////////////////

    /////////////REFRESHING WINDOWS//////////////////////
    wrefresh(screeningRoomForOldViewers);
    wrefresh(screeningRoomForYoungViewers);
    wrefresh(screeningRoomForEveryoneViewers);
    wrefresh(toiletWindow);
    wrefresh(popcornStation);
    wrefresh(sodaStation);
    wrefresh(waitingRoom);
    wrefresh(checkTicketStation);
    for (int i = 0; i < TICKETOFFICE_STATION_NUMBER; i++)
        wrefresh(ticketOfficeStation[i]);
    //////////////////////////////////////////////////////
}

void Window::createOldViewerWindow(const int oldViewer, const int youngViewer)
{
    int height, width, start_y, start_x;
    height = 2 * oldViewer - 1;
    width = 40;
    start_x = 0;
    start_y = 4;
    WINDOW *win = newwin(height, width, start_y, start_x);
    box(win, 0, 0);
    //wattron(win, COLOR_PAIR(1));
    refresh();

    for (int i = 0; i < oldViewer - 1; i++)
    {
        mvwhline(win, 2 + 2 * i, 1, 0, width - 2);
        mvwprintw(win, 1 + 2 * i, 1, "%d", i);
    }
    mvwvline(win, 1, 4, 0, height - 2);
    wrefresh(win);
}

void Window::createScreeningRoom(WINDOW *win)
{
    std::string a = "Cygan w wielkim miescie";
    const char *filmeName = a.c_str();

    box(win, 0, 0);
    refresh();

    wmove(win, 1, 20 - strlen(filmeName) / 2);
    wattron(win, COLOR_PAIR(1));
    wprintw(win, filmeName);
    wattroff(win, COLOR_PAIR(1));

    for (int i = 0; i < 4; i++)
    {
        mvwhline(win, 2 + 2 * i, 1, 0, win->_maxx - 1);
    }

    int row = 0;
    int col = 0;
    for (Viewer *el : viewerList)
    {
        if (el->getState() == 6)
        {
            wmove(win, 3 + row, 2 + col * 3);
            wattron(win, COLOR_PAIR(2));
            wprintw(win, "%d", el->getId());
            wattroff(win, COLOR_PAIR(2));
            col++;

            if ((2 + col * 3) > win->_maxx - 2)
            {
                row = row + 2;
                col = 0;
            }
        }
    }
}

void Window::createToilet(WINDOW *win)
{
    box(win, 0, 0);
    mvwhline(win, 2, 1, 0, 15);
    wmove(win, 1, 5);
    wattron(win, COLOR_PAIR(1));
    wprintw(win, "Toaleta");
    wattroff(win, COLOR_PAIR(1));

    for (int i = 1; i <= 3; i++)
        mvwvline(win, 3, 4 * i, 0, 1);

    int col = 0;
    for (Viewer *el : viewerList)
    {
        if (el->getState() == el->IN_TOILET)
        {
            wmove(win, 3, 2 + col * 3);
            wattron(win, COLOR_PAIR(2));
            wprintw(win, "%d", el->getId());
            wattroff(win, COLOR_PAIR(2)); //}
            col++;
        }
    }

    refresh();
}

void Window::createTicketOfficeStation(WINDOW *win, std::string stationName)
{
    const char *charStationName = stationName.c_str();
    box(win, 0, 0);
    mvwhline(win, 2, 1, 0, win->_maxx - 1);
    wmove(win, 1, 1);
    wattron(win, COLOR_PAIR(1));
    wprintw(win, charStationName);
    wattroff(win, COLOR_PAIR(1));
    mvwvline(win, 3, (win->_maxx) / 2, 0, ((win->_maxy) / 2) - 1);
    refresh();
}

void Window::createWaitingRoom(WINDOW *win)
{

    box(win, 0, 0);
    mvwhline(win, 2, 1, 0, win->_maxx - 1);
    mvwhline(win, 8, 1, 0, win->_maxx - 1);
    wmove(win, 1, win->_maxx / 3 + 5);
    wattron(win, COLOR_PAIR(1));
    wprintw(win, "Poczekalnia");
    wattroff(win, COLOR_PAIR(1));
    wmove(win, 9, win->_maxx / 3 + 5);
    wattron(win, COLOR_PAIR(1));
    wprintw(win, "Poczekalnia");
    wattroff(win, COLOR_PAIR(1));

    int row = 0;
    int col = 0;
    for (Viewer *el : viewerList)
    {
        if (el->getState() == 0)
        {
            wmove(win, 3 + row, 2 + col * 3);
            wattron(win, COLOR_PAIR(2));
            wprintw(win, "%d", el->getId());
            wattroff(win, COLOR_PAIR(2)); //}
            col++;

            if ((2 + col * 3) > win->_maxx - 2)
            {
                row = row + 2;
                col = 0;
            }
        }
    }
    refresh();
}

void Window::createLegend()
{
    move(46, 2);
    printw("Legenda:");
    move(48, 2);
    printw("Dorosly widz -> ");
    attron(COLOR_PAIR(2));
    printw("N");
    attroff(COLOR_PAIR(2));
    move(49, 2);
    printw("Mlody widz   -> ");
    attron(COLOR_PAIR(3));
    printw("N");
    attroff(COLOR_PAIR(3));
    move(50, 2);
    printw("Pracownik    -> ");
    attron(COLOR_PAIR(4));
    printw("N");
    attroff(COLOR_PAIR(4));
    move(51, 2);
    printw("Kierownik    -> ");
    attron(COLOR_PAIR(5));
    printw("N");
    attroff(COLOR_PAIR(5));
    refresh();
}

Window::~Window()
{
    //dtor
}
