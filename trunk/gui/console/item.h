#ifndef ITEM_H
#define ITEM_H
#include "console.h"
class item
{
    private:
    /*name for the menu item*/
	char* name;
    /*x coordinate for the menu item*/
    int x;
    /*y coordinate for the menu item*/
	int y;
	/*code for the menu item being used*/
	int code;
	console console_item;
public:
    item();
	item(char*,int,int ,int);
	~item();
	bool setItem(int,int,int,char*);
	int getCode();
	int getItemX();
	int getItemY();
	/*gets the lenght of each item so as
	to set the frame around it*/
	int getItemLenght();
	/*gives the item life, that is, displays it on the screen*/
	void born();
};
#endif
