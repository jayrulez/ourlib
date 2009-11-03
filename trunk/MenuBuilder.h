#ifndef _MENUBUILDER_H
#define _MENUBUILDER_H
#ifndef ITEM_H
#include "gui/console/item.h"
#endif

class MenuBuilder
{
public:
	MenuBuilder();
	item* buildMenu();
	void showMenu(item*);
	~MenuBuilder();
};
#endif
