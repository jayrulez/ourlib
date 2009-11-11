#ifndef _MENUBUILDER_H
#define _MENUBUILDER_H
#ifndef ITEM_H
#include "gui/console/item.h"
#endif
#ifndef MEDIA_H
#include "gui/console/media.h"
#endif
#ifndef SCROLLER_H
#include "gui/console/scroller.h"
#endif

class MenuBuilder
{
public:
	MenuBuilder();
	~MenuBuilder();
	item* mainMenu();
	int menuBrowserOperator(item*);
	int MenuProcessing( int,item*,int*,scroller*);
	void mainMenuShow(item*);
	int mainMenuRangeY(item*,int,int);
	int mainMenuRangeX(item*,int,int);
	void run();
};
#endif
