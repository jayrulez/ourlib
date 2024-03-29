/*
@Group: BSC2D
@Group Members:
	<ul>
		<li>Robert Campbell: 0701334</li>
		<li>Audley Gordon: 0802218</li>
		<li>Dale McFarlane: 0801042</li>
		<li>Dyonne Duberry: 0802189</li>
		<li>Xavier Lowe: 0802488</li>
	</ul>
@
*/
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
* Referce Material Types
*/
#define TEXTBOOKTYPE 1000
#define RESEARCHPAPERTYPE 1001
#define MAGAZINETYPE 1002
#define MEMBERTYPE 1003
#define LOANTYPE 1004
#define RETURNTYPE 1005
#define DELETETYPE 1006
#define EDITTYPE 1007
#define ADDTYPE 1008
#define EXITTYPE 1009
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
#define ADDFORMMENU_SIZ 4
/*
* Add Member Form Menu
*/
#define ADDMEMBERFORMMENU_SIZ 4
/*
* Add Member Confirmation Menu
*/
#define MEMBERCONFIRMMENU_SIZ 2
/*
* Edit Menu
*/
#define SEARCH 16
#define EDITMENU_SIZ 2
/*
* Edit Form Menu
*/
#define EDITFORMMENU_SIZ 4
/*
* Edit Confirmation Menu
*/
#define EDITCONFIRMMENU_SIZ 2
/*
* Add Confirmation Menu
*/
#define ADDCONFIRMMENU_SIZ 2
/*
* Delete Menu
*/
#define DELETEMENU_SIZ 2
/*
* Delete Confirmation Menu
*/
#define DELETECONFIRMMENU_SIZ 2
/*
* Loan Menu
*/
#define EXISTINGMEMBER 10
#define NEWUSER 11
#define LOANMENU_SIZ 3
/*
* Existing User Loan Menu
*/
#define EXISTINGUSERMENU_SIZ 4
/*
* Existing User Loan Confirmation menu
*/
#define LOANCONFIRMMENU_SIZ 2
/*
* Existing User Return Menu
*/
#define RETURNMENU_SIZ 3
/*
* Return User Loan Confirmation menu
*/
#define RETURNCONFIRMMENU_SIZ 2

/*
* Return User Loan Confirmation menu
*/
#define RETURNCONFIRMMENU_SIZ 2

/*
* Form Confirmation Menu Items
*/
#define SAVE 12
#define CANCEL 13
/*
* After Save Menu
*/
#define AFTERSAVEMENU_SIZ 2

/*
* Form Menu Items
*/
#define SUBMIT 14
#define CLEARFIELD 15

/*
* Termatates program
*/
#define TERMINATE 20

#ifndef FORM_H
#include "./forms/Form.h"
#endif

#include <string>
using namespace std;

class MenuBuilder
{
private:
	Form* formPtr;
	string queryString;
public:
	MenuBuilder();
	~MenuBuilder();

	item* MainMenu();

	item* AddReferenceMaterial();
	item* AddFormMenu();
	item* AddConfirmMenu();
    item* AddAfterSaveMenu();

	item* EditMenu();
	item* EditFormMenu();
	item* EditConfirmMenu();
    item* EditAfterSaveMenu();

	item* DeleteMenu();
	item* DeleteConfirmMenu();
	item* AfterDeleteMenu();

	item* LoanMenu();
	item* LoanFormMenu();
	item* LoanConfirmMenu();
	item* LoanAfterSaveMenu();

    item* AddMemberFormMenu();
	item* MemberConfirmMenu();

    item* ReturnFormMenu();
	item* ReturnConfirmMenu();
	item* ReturnAfterSaveMenu();

	item* ExitConfirmMenu();

	string EditMenuDriver();
	int EditInput(string *);
	string DeleteMenuDriver();
	int DeleteInput(string *);
	int menuBrowserOperator(item*,int,int,bool);
	int MenuProcessing( int,item*,int*,scroller*,int,int,bool);
	void MenuShow(item*,int);
	int MenuRangeY(item*,int,int);
	int MenuRangeX(item*,int,int);
	void BasicRunlevel(string,int=680,int=800);
	void callMenu(int);
	void showReferenceMaterialForm(int);
	void showLoanForm(int);
};
#endif
