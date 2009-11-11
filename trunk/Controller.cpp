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

MenuBuilder* Controller::menuBuilder()
{
	this->menuObj = new MenuBuilder();
	return this->menuObj;
}

/*
*
*/
Controller::~Controller()
{
}

