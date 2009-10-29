#include <iostream>
#include "item.h"
#include "scroller.h"
#include "windows.h"
#include "console.h"
#include "media.h"
#include "menu.h"
#define _MAX 1
#define _MIN 2

using namespace std;

item* main_menu();
void menu_browser_op(item*,media);
void main_menu_show(item*);
int menu_y_range(item*,int,int);
int menu_x_range(item*,int,int);
int main()
{
    media sound;
    console con;
    con.setCursor(false,50);
    main_menu_show(main_menu());
    menu_browser_op(main_menu(),sound);
    return 0;
}
item* main_menu()
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
void main_menu_show(item *iptr)
{
    int x;
    for (x=0;x<6;x++)
    {
        (iptr+x)->born();
    }
}

int menu_y_range(item *iptr,int size,int type)
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
int menu_x_range(item *iptr,int size,int type)
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
void menu_browser_op(item *iptr,media sound)
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
                            sound.play("sound/button-15");
                        break;
                        case VK_RIGHT:
                            sound.play("sound/button-15");
                        break;
                        case VK_UP:
                            pos=pos-1;
                            if(pos<0)
                            {
                                pos=MAIN_SIZ-1;
                            }
                            sound.play("sound/button-15");
                        break;
                        case VK_DOWN:
                            pos=pos+1;
                            if(pos>MAIN_SIZ-1)
                            {
                                pos=0;
                            }
                            sound.play("sound/button-15");
                        break;
                    }
                    scr.killScroll();
                    scr.setScroller((iptr+pos)->getItemX(),(iptr+pos)->getItemY(),(iptr+pos)->getItemLenght());
                    scr.scroll();
                }
            break;
        }
    }
}

