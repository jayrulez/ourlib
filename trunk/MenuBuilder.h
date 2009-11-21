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

/*
* Menu Type
*/
#define NORMALMENU 100
#define FORMMENU 101

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
* Add Research Paper
*/
#define RESEARCHSUBMIT 10
#define RESEARCHCLEARFIELD 11
#define ADDRESAERCHPAPERFORMMENU_SIZ 4
/*
* Add Magazine
*/
#define MAGAZINESUBMIT 12
#define MAGAZINECLEARFIELD 13
#define ADDMAGAZINEFORMMENU_SIZ 4
/*
* Add TextBook
*/
#define TEXTBOOKSUBMIT 14
#define TEXTBOOKCLEARFIELD 15
#define ADDTEXTBOOKFORMMENU_SIZ 4
/*
* Add Member
*/
#define MEMBERSUBMIT 16
#define MEMBERCLEARFIELD 17
#define ADDMEMBERFORMMENU_SIZ 4
/*
* Edit Menu
*/
#define EDITMENU_SIZ 1
/*
* Edit Form Menu
*/
#define EDITSUBMIT 18
#define EDITCLEARFIELD 19
#define EDITFORMMENU_SIZ 4
/*
* Edit Confirmation Menu
*/
#define EDITSAVE 20
#define EDITCANCEL 21
#define EDITCONFIRMMENU_SIZ 2
/*
* Add Confirmation Menu
*/
#define ADDSAVE 22
#define ADDCANCEL 23
#define ADDCONFIRMMENU_SIZ 2
/*
* Loan Menu
*/
#define EXISTINGMEMBER 24
#define NEWUSER 25
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
	item* AddResearchPaperFormMenu();
	item* AddMagazineFormMenu();
	item* AddTextBookFormMenu();
	item* AddMemberFormMenu();
	item* EditMenu();
	item* EditFormMenu();
	item* EditConfirmMenu();
	item* AddConfirmMenu();
	int EditMenuDriver();
	int EditInput(string *);
	int menuBrowserOperator(item*,int,int);
	int MenuProcessing( int,item*,int*,scroller*,int,int);
	void MenuShow(item*,int);
	int MenuRangeY(item*,int,int);
	int MenuRangeX(item*,int,int);
	void BasicRunlevel(string,int=680,int=800);
	void callMenu(int);
	void showReferenceMaterialForm(int);
	void showLoanForm(int);
};
#endif
