#ifndef _CONTROLLER_H
#include "Controller.h"
#endif


using namespace std;

/*
*
*/
Controller::Controller()
{
}

MenuBuilder* Controller::init()
{
	this->menuBuilderObj = new MenuBuilder();
	return this->menuBuilderObj;
}

/*
*
*/
Controller::~Controller()
{
}

