#include <string>
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
using namespace std;

class MenuBuilder
{
public:
	MenuBuilder();
	~MenuBuilder();
	item* MainMenu();
	item* UserTypeMenu();
	int menuBrowserOperator(item*,int);
	int MenuProcessing( int,item*,int*,scroller*,int);
	void MenuShow(item*,int);
	int MenuRangeY(item*,int,int);
	int MenuRangeX(item*,int,int);
	void BasicRunlevel(string,int=680,int=800);
	void callMenu(int);
};
#endif
