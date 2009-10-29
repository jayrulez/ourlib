#ifndef ITEM_H
#define ITEM_H
#include "console.h"
class item
{
    private:
	char* name;
    int x;
	int y;
	int code;
	console console_item;
public:
	item(char* nm="default",int x1=0,int y1=1,int c=0);
	~item();
	bool setItem(int,int,int,char*);
	int getCode();
	int getItemX();
	int getItemY();
	int getItemLenght();
	void born();
};
#endif
