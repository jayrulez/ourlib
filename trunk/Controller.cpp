#ifndef _CONTROLLER_H
#include "Controller.h"
#endif

#ifndef _MODEL_H
#include "model/Model.h"
#endif

#ifndef _MENUBUILDER_H
#include "MenuBuilder.h"
#endif

/*
*
*/
Controller::Controller()
{
}

MenuBuilder* Controller::init()
{
	this->menuObj = new MenuBuilder();
	this->menuObj->BasicRunlevel("SELECT USER");//added for testing
	this->menuObj->callMenu(_mainMenu_);
}

/*
*
*/
Controller::~Controller()
{
}

