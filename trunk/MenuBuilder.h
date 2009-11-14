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
/*
* Main Menu
*/
#define MAINMENU 0
#define ADD 1
#define EDIT 2
#define DEL 3
#define LOAN 4
#define RETURN 5
#define EXIT 6
#define MAIN_SIZ 6

/*
* Add Menu
*/
#define RESEARCHPAPER 7
#define TEXTBOOK 8
#define MAGAZINE 9
#define ADDMENU_SIZ 4

/*
* Loan Menu
*/
#define EXISTINGMEMBER 10
#define NEWUSER 11
#define LOANMENU_SIZ 3

#include <string>
using namespace std;

class MenuBuilder
{
public:
	MenuBuilder();
	~MenuBuilder();
	item* MainMenu();
	item* AddReferenceMaterial();
	item* LoanMenu();
	int menuBrowserOperator(item*,int);
	int MenuProcessing( int,item*,int*,scroller*,int);
	void MenuShow(item*,int);
	int MenuRangeY(item*,int,int);
	int MenuRangeX(item*,int,int);
	void BasicRunlevel(string,int=680,int=800);
	void callMenu(int);
};
#endif
