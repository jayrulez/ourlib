#include <iostream>
#include "windows.h"
#ifndef _APPLICATION_H
#include "Application.h"
#endif
#ifndef CONSOLE_H
#include "gui/console/console.h"
#endif
#ifndef FRAME_H
#include "gui/console/frame.h"
#endif
#ifndef LINE_H
#include "gui/console/line.h"
#endif
#ifndef ITEM_H
#include "gui/console/item.h"
#endif
#ifndef MEDIA_H
#include "gui/console/media.h"
#endif
#ifndef MENU_H
#include "gui/console/menu.h"
#endif
#ifndef SCROLLER_H
#include "gui/console/scroller.h"
#endif
#ifndef _APPLICATIONEXCEPTION_H
#include "ApplicationException.h"
#endif
#define _MAX 2
#define _MIN 1
#define FORM 1
#define MENU 2

using namespace std;

/*
* Sets @attribute Application::state to true upon instantiation
*/
Application::Application()
{
	this->setState(true);
	this->reRun = false;
}

/*
* Destroys the Application Object
*/
Application::~Application()
{
}

/*
* Sets the state of the application
* @param bool state
*/
void Application::setState(bool state)
{
	this->state = state;
}

/*
* Returns the state of the application
* @Return bool
*/
bool Application::getState()
{
	return this->state;
}

/*
* Terminates the application
* @Return int
*/
int Application::terminate()
{
	return 0;
}

void Application::process()
{
	this->welcome();
	this->main();
}

void Application::welcome()
{
	//cout << "Application Skeleton";
}

void Application::main()
{
    console con;
    con.setCursor(false,50);
    this->mainMenuShow(this->mainMenu());
    this->menuBrowserOperator(this->mainMenu());
}
/*
* This function creates the items for the main menu
* and returns the address of its 1st element;
*/
item* Application::mainMenu()
{
    static item MainItem[6];
    MainItem[0].setItem(36,4,ADD,"ADD");
    MainItem[1].setItem(35,7,EDIT,"EDIT");
    MainItem[2].setItem(34,10,DEL,"DELETE");
    MainItem[3].setItem(35,13,LOAN,"LOAN");
    MainItem[4].setItem(34,16,RETURN,"RETURN");
    MainItem[5].setItem(35,19,EXIT,"EXIT");
    return &MainItem[0];
}
/*
* This functions display the contents for the main menu
*/
void Application::mainMenuShow(item *iptr)
{
    int x;
    for (x=0;x<6;x++)
    {
        (iptr+x)->born();
    }
}
/*
* This function is used to return the vertical range of any menu
*/
int Application::mainMenuRangeY(item *iptr,int size,int type)
{
	int max;
	int min;
	int x=0;
	switch(type)
	{
		case _MAX:
			max=(iptr+x)->getItemY();
			for(x=0;x<size;x++)
			{
				if (max<(iptr+x)->getItemY())
				{
					max=(iptr+x)->getItemY();
				}
			}
			return max;
		case _MIN:
			min=(iptr+x)->getItemY();
			for(x=0;x<size;x++)
			{
				if (min>(iptr+x)->getItemY())
				{
					min=(iptr+x)->getItemY();
				}
			}
			return min;
	}
	cout<<"Incorrect Type recieved"<<endl;
	return 0;
}
/*
* This function is used to return the horizontal range of any menu
*/
int Application::mainMenuRangeX(item *iptr,int size,int type)
{
	int max;
	int min;
	int x=0;
	switch(type)
	{
		case _MAX:
			max=(iptr+x)->getItemX();
			for(x=0;x<size;x++)
			{
				if (max<(iptr+x)->getItemX())
				{
					max=(iptr+x)->getItemX();
				}
			}
			return max;
		case _MIN:
			min=(iptr+x)->getItemX();
			for(x=0;x<size;x++)
			{
				if (min>(iptr+x)->getItemX())
				{
					min=(iptr+x)->getItemX();
				}
			}
			return min;
	}
	cout<<"Incorrect Type recieved"<<endl;
	return 0;
}
/*
* This is the heart of the menu operations. This function controls
* the scrolling and selection of different menu items
*/
int Application::menuBrowserOperator(item *iptr)
{

    static int position=0;
    int *posptr;

    posptr=&position;
    bool read=false;
    /*
    * instantiating an handle data type
    * that will be able to store input handles
    */
    HANDLE hIn;
    /*
    * structure that stores information on the various
    * types of console inputs
    */
    INPUT_RECORD InRec;
    /*
    * will be used to store the amount of event read
    */
    DWORD AmtRead;
    scroller scr;
    scroller *scrptr;
    scrptr=&scr;
    /*
    * gets the console input handle and stores it
    */
    hIn=GetStdHandle(STD_INPUT_HANDLE);
    /*
    * initialises the scroller's position(top of the menu)
    */
    scrptr->setScroller((iptr+position)->getItemX(),(iptr+position)->getItemY(),
    (iptr+position)->getItemLenght());
    scrptr->scroll();

    while(!read)
    {
        /*
        * This funtion reads the console input, both
        * keyboard and mouse
        */
        ReadConsoleInput(hIn,&InRec,1,&AmtRead);
        /*
        * case used to render the type of input,
        * wether KEY or MOUSE
        */
        switch(InRec.EventType)
        {
            case KEY_EVENT:
                /*
                * checks for a key being pressed
                * (going down)
                */
                if(InRec.Event.KeyEvent.bKeyDown)
                {
                    /*
                    * filters the type of key being pressed
                    */
                    switch(InRec.Event.KeyEvent.wVirtualKeyCode)
                    {
                        /*
                        * Left arrow key
                        */
                        case VK_LEFT:
                            MenuProcessing(VK_LEFT,iptr,posptr,scrptr);
                        break;
                        /*
                        * Right arrow key
                        */
                        case VK_RIGHT:
                            MenuProcessing(VK_RIGHT,iptr,posptr,scrptr);
                        break;
                        /*
                        * Up arrow key
                        */
                        case VK_UP:
                            MenuProcessing(VK_UP,iptr,posptr,scrptr);
                        break;
                        /*
                        * Down arrow key
                        */
                        case VK_DOWN:
                            MenuProcessing(VK_DOWN,iptr,posptr,scrptr);
                        break;
                        /*
                        * Enter key
                        */
                        case VK_RETURN:
                            return MenuProcessing(VK_RETURN,iptr,posptr,scrptr);
                        break;
                    }
                }
            break;
        }
    }
    return 0;
}
int Application::MenuProcessing( int vKeyCode,item *iptr,int *pos,scroller *scr  )
{
    switch(vKeyCode)
    {
        /*
        * Left arrow key
        */
        case VK_LEFT:
        break;
        /*
        * Right arrow key
        */
        case VK_RIGHT:

        break;
        /*
        * Up arrow key
        */
        case VK_UP:
            *pos=*pos-1;
            if(*pos<0)
            {
                *pos=MAIN_SIZ-1;
            }
            scr->killScroll();
            scr->setScroller((iptr+*pos)->getItemX(),(iptr+*pos)->getItemY(),
            (iptr+*pos)->getItemLenght());
            scr->scroll();
            break;
        /*
        * Down arrow key
        */
        case VK_DOWN:
            *pos=*pos+1;
            if(*pos>MAIN_SIZ-1)
            {
                *pos=0;
            }
            scr->killScroll();
            scr->setScroller((iptr+*pos)->getItemX(),(iptr+*pos)->getItemY(),
            (iptr+*pos)->getItemLenght());
            scr->scroll();
            break;
        /*
        * Enter key
        */
        case VK_RETURN:
            return (iptr+*pos)->getCode();
        break;
    }
    return 0;
}
/*
* Starts the application
* Application runs while @attribute Application::state is true
* @Return @method Application::terminate
*/
int Application::run()
{
	while(this->getState()==true)
	{
		/*
		* The application process
		*/
		this->process();

		/*
		* If @attribute Application::state is true and
		* @attribute Application::reRun is set to false
		* Sets @attribute Application::state to false
		* Stops the loop from running again in order
		* for method Application::terminate() to be returned
		* after the loop
		*/
		if(this->getState()==true && this->reRun==false)
			this->setState(false);
	}
	return this->terminate();
}
