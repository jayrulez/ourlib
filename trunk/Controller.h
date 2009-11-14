#ifndef _CONTROLLER_H
#define _CONTROLLER_H
#ifndef _MENUBUILDER_H
#include "MenuBuilder.h"
#endif

class Controller
{
private:
    MenuBuilder *menuBuilderObj;
public:

	Controller();
	~Controller();
	MenuBuilder* init();
};
#endif
