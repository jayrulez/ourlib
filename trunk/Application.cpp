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
#define _MAX 1
#define _MIN 2

using namespace std;

/*
* Sets @attribute Application::state to true upon instantiation
*/
Application::Application()
{
	this->error=new ApplicationException;
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
    media *sound = new media;
    console con;
    con.setCursor(false,50);
    this->mainMenuShow(this->mainMenu());
    this->menuBrowserOperator(this->mainMenu(),sound);
}

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

void Application::mainMenuShow(item *iptr)
{
    int x;
    for (x=0;x<6;x++)
    {
        (iptr+x)->born();
    }
}

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

void Application::menuBrowserOperator(item *iptr,media *sound)
{
    static int pos=0;
    HANDLE hIn;
    INPUT_RECORD InRec;
    DWORD AmtRead;
    scroller scr;
    console con;
    hIn=GetStdHandle(STD_INPUT_HANDLE);
    scr.setScroller((iptr+pos)->getItemX(),(iptr+pos)->getItemY(),(iptr+pos)->getItemLenght());
    scr.scroll();
    bool read=false;
    while(!read)
    {
        ReadConsoleInput(hIn,&InRec,1,&AmtRead);
        switch(InRec.EventType)
        {
            case KEY_EVENT:
                if(InRec.Event.KeyEvent.bKeyDown)
                {
                    switch(InRec.Event.KeyEvent.wVirtualKeyCode)
                    {
                        case VK_LEFT:
                            //sound->play("./gui/console/sound/button-15");
                        break;
                        case VK_RIGHT:
                            //sound->play("./gui/console/sound/button-15");
                        break;
                        case VK_UP:
                            pos=pos-1;
                            if(pos<0)
                            {
                                pos=MAIN_SIZ-1;
                            }
                            scr.killScroll();
                            scr.setScroller((iptr+pos)->getItemX(),(iptr+pos)->getItemY(),(iptr+pos)->getItemLenght());
                            scr.scroll();
                            //sound->play("./gui/console/sound/button-15");
                        break;
                        case VK_DOWN:
                            pos=pos+1;
                            if(pos>MAIN_SIZ-1)
                            {
                                pos=0;
                            }
                            scr.killScroll();
                            scr.setScroller((iptr+pos)->getItemX(),(iptr+pos)->getItemY(),(iptr+pos)->getItemLenght());
                            scr.scroll();
                            //sound->play("./gui/console/sound/button-15");
                        break;
                    }
                }
            break;
        }
    }
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
