#include <iostream>
#include <string>
#ifndef _MENUBUILDER_H
#include "MenuBuilder.h"
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
#define _MAX 2
#define _MIN 1

#include <string>
using namespace std;

/*
*
*/
MenuBuilder::MenuBuilder()
{
}

/*
*
*/
MenuBuilder::~MenuBuilder()
{
}

void MenuBuilder::callMenu(int menuId)
{
    console con;
    con.setCursor(false,50);
	switch(menuId)
	{
		case ADD:
            this->BasicRunlevel("ADD MENU");
            this->MenuShow(this->AddReferenceMaterial(),ADDMENU_SIZ);
			this->menuBrowserOperator(this->AddReferenceMaterial(),ADDMENU_SIZ);
		break;
		/*
		case _editMenu_:
		break;
		case _delMenu_:
		break;
		*/
		case LOAN:
            this->BasicRunlevel("LOAN MENU");
			this->MenuShow(this->LoanMenu(),LOANMENU_SIZ);
			this->menuBrowserOperator(this->LoanMenu(),LOANMENU_SIZ);
		break;
		default:
            this->BasicRunlevel("MAIN MENU");
			this->MenuShow(this->MainMenu(),MAIN_SIZ);
			this->menuBrowserOperator(this->MainMenu(),MAIN_SIZ);
		break;
	}
}

/*
* This function creates the items for the main menu
* and returns the address of its 1st element;
*/
item* MenuBuilder::MainMenu()
{
    static item MainItem[MAIN_SIZ];
    MainItem[0].setItem(38,13,ADD,"ADD");
    MainItem[1].setItem(37,17,EDIT,"EDIT");
    MainItem[2].setItem(36,21,DEL,"DELETE");
    MainItem[3].setItem(37,25,LOAN,"LOAN");
    MainItem[4].setItem(36,29,RETURN,"RETURN");
    MainItem[5].setItem(37,33,EXIT,"EXIT");
    return &MainItem[0];
}
/*
* This function creates the items for the Add Menu
* and return the address of its 1st element
*/
item* MenuBuilder::AddReferenceMaterial()
{
    static item AddReferenceItem[ADDMENU_SIZ];
    AddReferenceItem[0].setItem(15,21,RESEARCHPAPER,"RESEARCH PAPER");
    AddReferenceItem[1].setItem(35,21,TEXTBOOK,"TEXT BOOK");
    AddReferenceItem[2].setItem(55,21,MAGAZINE,"MAGAZINE");
    AddReferenceItem[3].setItem(35,25,MAINMENU,"MAIN MENU");
    return & AddReferenceItem[0];
}
/*
* This function creates the items for the Loan Menu
* and return the address of its 1st element
*/
item* MenuBuilder::LoanMenu()
{
    static item LoanMenuItem[LOANMENU_SIZ];
    LoanMenuItem[0].setItem(15,21,EXISTINGMEMBER,"EXISTING MEMBER");
    LoanMenuItem[1].setItem(55,21,NEWUSER,"NEW USER");
    LoanMenuItem[2].setItem(35,25,MAINMENU,"MAIN MENU");
    return &LoanMenuItem[0];
}
/*
* This function displays the contents for the menus
*/
void MenuBuilder::MenuShow(item *iptr,int size)
{
    int x;
    for (x=0;x<size;x++)
    {
        (iptr+x)->born();
    }
}
/*
* This function is used to return the vertical range of any menu
*/
int MenuBuilder::MenuRangeY(item *iptr,int size,int type)
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
int MenuBuilder::MenuRangeX(item *iptr,int size,int type)
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
int MenuBuilder::menuBrowserOperator(item *iptr,int size)
{

    int position=0;
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
                        * Tab key
                        */
                        case VK_TAB:
                            MenuProcessing(VK_TAB,iptr,posptr,scrptr,size);
                        break;
                        /*
                        * Left arrow key
                        */
                        case VK_LEFT:
                            MenuProcessing(VK_LEFT,iptr,posptr,scrptr,size);
                        break;
                        /*
                        * Right arrow key
                        */
                        case VK_RIGHT:
                            MenuProcessing(VK_RIGHT,iptr,posptr,scrptr,size);
                        break;
                        /*
                        * Up arrow key
                        */
                        case VK_UP:
                            MenuProcessing(VK_UP,iptr,posptr,scrptr,size);
                        break;
                        /*
                        * Down arrow key
                        */
                        case VK_DOWN:
                            MenuProcessing(VK_DOWN,iptr,posptr,scrptr,size);
                        break;
                        /*
                        * Enter key
                        */
                        case VK_RETURN:
                            return MenuProcessing(VK_RETURN,iptr,posptr,scrptr,size);
                        break;
                    }
                }
            break;
        }
    }
    return 0;
}
int MenuBuilder::MenuProcessing( int vKeyCode,item *iptr,int *pos,scroller *scr,int size)
{
    switch(vKeyCode)
    {
        /*
        * Left arrow key
        */
        case VK_LEFT:
            *pos=*pos-1;
            if(*pos<0)
            {
                *pos=size-1;
            }
            scr->killScroll();
            scr->setScroller((iptr+*pos)->getItemX(),(iptr+*pos)->getItemY(),
            (iptr+*pos)->getItemLenght());
            scr->scroll();
        break;
        /*
        * Tab Key
        */
        case VK_TAB:
        /*
        * Right arrow key
        */
        case VK_RIGHT:
            *pos=*pos+1;
            if(*pos>size-1)
            {
                *pos=0;
            }
            scr->killScroll();
            scr->setScroller((iptr+*pos)->getItemX(),(iptr+*pos)->getItemY(),
            (iptr+*pos)->getItemLenght());
            scr->scroll();

        break;
        /*
        * Up arrow key
        */
        case VK_UP:
            *pos=*pos-1;
            if(*pos<0)
            {
                *pos=size-1;
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
            if(*pos>size-1)
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
			this->callMenu((iptr+*pos)->getCode());
            //return (iptr+*pos)->getCode();
        break;
    }
    return 0;
}

void MenuBuilder::BasicRunlevel(string MenuName,int consoleX, int consoleY)
{
	frame BaseFrame;
	console con;
	con.clearScreen();
	con.setConsoleSize(consoleX,consoleY);
	BaseFrame.setFrame(0,79,0,52,true);
	BaseFrame.dFraming();
	con.xyCoord(0,0);
	con.xyCoord(3,1);
	cout<<MenuName;
}
