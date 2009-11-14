#include <iostream>
#include "item.h"
#include "console.h"

#include <string>
using namespace std;

item::item()
{
    x=0;
    y=0;
    code=0;
}
item::item(string nm,int x1, int y1,int c)
{

	if(x1>=0 && y1>=0){

		name=nm;
		x=x1;
		y=y1;
		code=c;
	}
	else{
		cout<<"Item construction failed!"<<endl;
	}
}
item::~item()
{
}
bool item::setItem(int x1,int y1,int c,string nm)
{
	if(x1>=0 && y1>=0){     //check criteria
		x=x1;
		y=y1;
		name=nm;
		code =c;
		return true;
	}
	cout<<"setItem Failed!"<<endl;
	return false;
}
int item::getItemX()
{
    return x;
}
int item::getItemY()
{
    return y;
}
int item::getItemLenght()
{
    string str (name);
    return str.length();
}
int item::getCode()
{
    return code;
}
void item::born()
{
    console_item.xyCoord(x,y);
    cout<<name;
}

