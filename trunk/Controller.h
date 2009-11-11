#ifndef _CONTROLLER_H
#define _CONTROLLER_H
#ifndef _MENUBUILDER_H
#include "MenuBuilder.h"
#endif

class Controller
{
public:
	MenuBuilder* menuObj;
	MenuBuilder* menuBuilder();
	Controller();
	~Controller();
};
#endif
