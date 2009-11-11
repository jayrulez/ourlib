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

/* Menu Codes */
#define _mainMenu_ 0
#define _addMenu_ 1
#define _editMenu_ 2
#define _delMenu_ 4
#define _loanMenu_ 8

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
	void callMenu(int);
};
#endif
