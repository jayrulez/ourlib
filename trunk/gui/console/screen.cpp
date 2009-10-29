#include <iostream>
#include "screen.h"
#include "console.h"
using namespace std;

screen::screen(char* nm):name(nm)
{
}
screen::~screen()
{
}
void screen::setScreenName(char* nm)
{
	name=nm;
}
char* screen::getScreenName()
{
	return name;
}
