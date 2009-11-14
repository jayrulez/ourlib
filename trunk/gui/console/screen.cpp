#include <iostream>
#include "screen.h"
#include "console.h"

#include <string>
using namespace std;


screen::screen(string nm):name(nm)
{
}
screen::~screen()
{
}
void screen::setScreenName(string nm)
{
	name=nm;
}
string screen::getScreenName()
{
	return name;
}
