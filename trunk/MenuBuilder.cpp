#include <iostream>
#include <string>

#ifndef _MENUBUILDER_H
#include "MenuBuilder.h"
#endif

#ifndef CONSOLE_H
#include "gui/console/console.h"
#endif

#ifndef FRAME_H
#include "gui/console/frame.h"
#endif

#ifndef LINE_H
#include "gui/console/line.h"
#endif

#ifndef ITEM_H
#include "gui/console/item.h"
#endif

#ifndef MEDIA_H
#include "gui/console/media.h"
#endif

#ifndef SCROLLER_H
#include "gui/console/scroller.h"
#endif


#define _MAX 2
#define _MIN 1

#include <string>


#ifndef _TEXTBOOK_H
#include "TextBook.h"
#endif
#ifndef _TEXTBOOKFORM_H
#include "forms/TextBookForm.h"
#endif

#ifndef _MAGAZINE_H
#include "Magazine.h"
#endif

#ifndef _MAGAZINEFORM_H
#include "forms/MagazineForm.h"
#endif

#ifndef _RESEARCHPAPER_H
#include "ResearchPaper.h"
#endif
#ifndef _RESEARCHPAPERFORM_H
#include "forms/ResearchPaperForm.h"
#endif

#ifndef _MEMBERFORM_H
#include "forms/MemberForm.h"
#endif

#ifndef FORMINPUTBUILDER_H
#include "forms/FormInputBuilder.h"
#endif

using namespace std;

/*
*
*/
MenuBuilder::MenuBuilder()
{
}

/*
*
*/
MenuBuilder::~MenuBuilder()
{
}

void MenuBuilder::showReferenceMaterialForm(int referenceMaterialType)
{
	switch(referenceMaterialType)
	{
		case TEXTBOOK:
			TextBook *TextBookPtr = new TextBook;
			TextBookForm *TextBookFormPtr = new TextBookForm;
			TextBookFormPtr->show(TextBookPtr);
		break;
		case RESEARCHPAPER:
			ResearchPaper *ResearchPaperPtr = new ResearchPaper;
			ResearchPaperForm *ResearchPaperFormPtr = new ResearchPaperForm;
			ResearchPaperFormPtr->show(ResearchPaperPtr);
		break;
		case MAGAZINE:
			Magazine *MagazinePtr = new Magazine;
			MagazineForm *MagazineFormPtr = new MagazineForm;
			MagazineFormPtr->show(MagazinePtr);
		break;
	}
}
void MenuBuilder::showLoanForm(int LoanFormType)
{
    switch(LoanFormType)
    {
        case EXISTINGMEMBER:

		break;
        case NEWUSER:
            MemberForm *memberForm = new MemberForm();
            memberForm->show();
        break;
    }
}

void MenuBuilder::callMenu(int menuId)
{
    console con;
    int TypeCheck;
    static MagazineForm *MagazineFormPtr=new MagazineForm;
    static MemberForm *MemberPtr=new MemberForm;
    static TextBookForm *TextBookFormPtr=new TextBookForm;
    static ResearchPaperForm *ResearchPaperPtr=new ResearchPaperForm;
    con.setCursor(false,50);

	switch(menuId)
	{
		case ADD:
            this->BasicRunlevel("ADD MENU");
            this->MenuShow(this->AddReferenceMaterial(),ADDMENU_SIZ);
			this->menuBrowserOperator(this->AddReferenceMaterial(),ADDMENU_SIZ,NORMALMENU);
		break;
		case EDIT:
            this->BasicRunlevel("EDIT MENU");
            this->MenuShow(EditMenu(),EDITMENU_SIZ);
			do
			{
                this->EditMenuDriver();
                TypeCheck=this->menuBrowserOperator(this->EditMenu(),EDITMENU_SIZ,FORMMENU);
			}while(TypeCheck==0);
            break;
        case EDITSUBMIT:
            this->BasicRunlevel("EDIT MENU");
            this->MenuShow(this->EditConfirmMenu(),EDITCONFIRMMENU_SIZ);
            this->menuBrowserOperator(this->EditConfirmMenu(),EDITCONFIRMMENU_SIZ,NORMALMENU);
        break;
        case EDITCLEARFIELD:
        break;

        case EDITSAVE:
            this->BasicRunlevel("EDIT MENU");
            switch(ReferenceType)
            {
                case TEXTBOOK:
                    break;
                case RESEARCHPAPER:
                    break;
                case MAGAZINE:
                    break;
            }
        break;
        case EDITCANCEL:
            this->BasicRunlevel("EDIT MENU");
            switch(ReferenceType)
            {
                case TEXTBOOK:
                    break;
                case RESEARCHPAPER:
                    break;
                case MAGAZINE:
                    break;
            }
        break;

        case ADDSAVE:
            this->BasicRunlevel("EDIT MENU");
            switch(ReferenceType)
            {
                case TEXTBOOK:
                    break;
                case RESEARCHPAPER:
                    break;
                case MAGAZINE:
                    break;
            }
        break;

        case ADDCANCEL:
            this->BasicRunlevel("ADD MENU");
            switch(ReferenceType)
            {
                case TEXTBOOK:
                    break;
                case RESEARCHPAPER:
                    break;
                case MAGAZINE:
                    break;
            }
        break;
		case RESEARCHPAPER:
			this->BasicRunlevel("ADD RESEARCH PAPER");
			this->showReferenceMaterialForm(RESEARCHPAPER);
			this->MenuShow(this->AddResearchPaperFormMenu(),ADDRESAERCHPAPERFORMMENU_SIZ);
			do
			{
                ResearchPaperPtr->BrowseResearchPaperForm();
                TypeCheck=this->menuBrowserOperator(this->AddResearchPaperFormMenu(),ADDRESAERCHPAPERFORMMENU_SIZ,FORMMENU);
            }while(TypeCheck==0);
		break;
		case TEXTBOOK:
			this->BasicRunlevel("ADD TEXTBOOK");
			this->showReferenceMaterialForm(TEXTBOOK);
			this->MenuShow(this->AddTextBookFormMenu(),ADDTEXTBOOKFORMMENU_SIZ);
			do
			{
                TextBookFormPtr->BrowseTextBookForm();
                TypeCheck=this->menuBrowserOperator(this->AddTextBookFormMenu(),ADDTEXTBOOKFORMMENU_SIZ,FORMMENU);
			}while(TypeCheck==0);

		case TEXTBOOKSUBMIT:
			this->BasicRunlevel("Show Data");
            TextBookFormPtr->save();
		break;
		break;
		case MAGAZINE:
			this->BasicRunlevel("ADD MAGAZINE");
			this->showReferenceMaterialForm(MAGAZINE);
			this->MenuShow(this->AddMagazineFormMenu(),ADDMAGAZINEFORMMENU_SIZ);
			do
			{
                MagazineFormPtr->BrowseMagazineForm();
                TypeCheck=this->menuBrowserOperator(this->AddMagazineFormMenu(),ADDMAGAZINEFORMMENU_SIZ,FORMMENU);
			}while(TypeCheck==0);
		break;
        case MAGAZINESUBMIT:
			this->BasicRunlevel("Show Data");
            MagazineFormPtr->showTest();
        break;
		case LOAN:
            this->BasicRunlevel("LOAN MENU");
			this->MenuShow(this->LoanMenu(),LOANMENU_SIZ);
			this->menuBrowserOperator(this->LoanMenu(),LOANMENU_SIZ,NORMALMENU);
		break;
		case EXISTINGMEMBER:
		break;
        case NEWUSER:
            this->BasicRunlevel("NEW USER REGISTRATION");
            this->showLoanForm(NEWUSER);
            this->MenuShow(this->AddMemberFormMenu(),ADDMEMBERFORMMENU_SIZ);
			do
			{
                MemberPtr->BrowseMemberForm();
                TypeCheck=this->menuBrowserOperator(this->AddMemberFormMenu(),ADDMEMBERFORMMENU_SIZ,FORMMENU);
			}while(TypeCheck==0);
        break;
		default:
            this->BasicRunlevel("MAIN MENU");
			this->MenuShow(this->MainMenu(),MAIN_SIZ);
			this->menuBrowserOperator(this->MainMenu(),MAIN_SIZ,NORMALMENU);
		break;
	}
}

/*
* This function creates the items for the main menu
* and returns the address of its 1st element;
*/
item* MenuBuilder::MainMenu()
{
    static item MainItem[MAIN_SIZ];
    MainItem[0].setItem(38,13,ADD,"ADD");
    MainItem[1].setItem(37,17,EDIT,"EDIT");
    MainItem[2].setItem(36,21,DEL,"DELETE");
    MainItem[3].setItem(37,25,LOAN,"LOAN");
    MainItem[4].setItem(36,29,RETURN,"RETURN");
    MainItem[5].setItem(37,33,EXIT,"EXIT");
    return &MainItem[0];
}
/*
* This function creates the items for the Add Menu
* and return the address of its 1st element
*/
item* MenuBuilder::AddReferenceMaterial()
{
    static item AddReferenceItem[ADDMENU_SIZ];
    AddReferenceItem[0].setItem(15,21,RESEARCHPAPER,"RESEARCH PAPER");
    AddReferenceItem[1].setItem(35,21,TEXTBOOK,"TEXT BOOK");
    AddReferenceItem[2].setItem(55,21,MAGAZINE,"MAGAZINE");
    AddReferenceItem[3].setItem(35,25,MAINMENU,"MAIN MENU");
    return & AddReferenceItem[0];
}
/*
*   This function creates menu items for the Add Research Paper Form
*/
item* MenuBuilder::AddResearchPaperFormMenu()
{
    static item AddResearchPaperFormItem[ADDRESAERCHPAPERFORMMENU_SIZ];
    AddResearchPaperFormItem[0].setItem(15,35,RESEARCHSUBMIT,"SUBMIT");
    AddResearchPaperFormItem[1].setItem(35,35,RESEARCHCLEARFIELD,"CLEAR FIELDS");
    AddResearchPaperFormItem[2].setItem(55,35,ADD,"<-- ADD MENU");
    AddResearchPaperFormItem[3].setItem(35,39,MAINMENU,"MAIN MENU");
    return &AddResearchPaperFormItem[0];
}
/*
*   This function creates menu items for the Add Magazine Form
*/
item* MenuBuilder::AddMagazineFormMenu()
{
    static item AddMagazineFormMenuItem[ADDMAGAZINEFORMMENU_SIZ];
    AddMagazineFormMenuItem[0].setItem(15,35,MAGAZINESUBMIT,"SUBMIT");
    AddMagazineFormMenuItem[1].setItem(35,35,MAGAZINECLEARFIELD,"CLEAR FIELDS");
    AddMagazineFormMenuItem[2].setItem(55,35,ADD,"<-- ADD MENU");
    AddMagazineFormMenuItem[3].setItem(35,39,MAINMENU,"MAIN MENU");
    return & AddMagazineFormMenuItem[0];
}
/*
*   This function creates menu items for the Add TextBook Form
*/
item* MenuBuilder::AddTextBookFormMenu()
{
    static item AddTextBookFormMenuItem[ADDTEXTBOOKFORMMENU_SIZ];
    AddTextBookFormMenuItem[0].setItem(15,35,TEXTBOOKSUBMIT,"SUBMIT");
    AddTextBookFormMenuItem[1].setItem(35,35,TEXTBOOKCLEARFIELD,"CLEAR FIELDS");
    AddTextBookFormMenuItem[2].setItem(55,35,ADD,"<-- ADD MENU");
    AddTextBookFormMenuItem[3].setItem(35,39,MAINMENU,"MAIN MENU");
    return &AddTextBookFormMenuItem[0];
}

/*
*   This function creates menu items for the Add Member Form
*/
item* MenuBuilder::AddMemberFormMenu()
{
    static item AddMemberFormMenuItem[ADDMEMBERFORMMENU_SIZ];
    AddMemberFormMenuItem[0].setItem(15,35,MEMBERSUBMIT,"SUBMIT");
    AddMemberFormMenuItem[1].setItem(35,35,MEMBERCLEARFIELD,"CLEAR FIELDS");
    AddMemberFormMenuItem[2].setItem(55,35,ADD,"<-- LOAN MENU");
    AddMemberFormMenuItem[3].setItem(35,39,MAINMENU,"MAIN MENU");
    return &AddMemberFormMenuItem[0];
}
/*
*   This function creates menu items for the Edit Menu
*/
item* MenuBuilder::EditMenu()
{
    static item EditMenuItem[EDITMENU_SIZ];
    EditMenuItem[0].setItem(35,32,MAINMENU,"MAINMENU");
    return &EditMenuItem[0];
}
item* MenuBuilder::EditFormMenu()
{
    static item EditFormMenuItem[EDITFORMMENU_SIZ];
    EditFormMenuItem[0].setItem(15,35,EDITSUBMIT,"SUBMIT");
    EditFormMenuItem[1].setItem(35,35,EDITCLEARFIELD,"CLEAR FIELDS");
    EditFormMenuItem[2].setItem(55,35,EDIT,"<-- EDIT MENU");
    EditFormMenuItem[3].setItem(35,39,MAINMENU,"MAIN MENU");
    return &EditFormMenuItem[0];
}
item* MenuBuilder::EditConfirmMenu()
{
    static item EditConfirmMenuItem[EDITCONFIRMMENU_SIZ];
    EditConfirmMenuItem[0].setItem(20,50,EDITSAVE,"SAVE CHANGES");
    EditConfirmMenuItem[1].setItem(40,50,EDITCANCEL,"CANCEL");
    return &EditConfirmMenuItem[0];
}
item* MenuBuilder::SaveConfirmMenu()
{
    static item AddConfirmMenuItem[ADDCONFIRMMENU_SIZ];
    AddConfirmMenuItem[0].setItem(20,50,ADDSAVE,"SAVE MATERIAL");
    AddConfirmMenuItem[1].setItem(40,50,ADDCANCEL,"CANCEL");
    return &AddConfirmMenuItem[0];
}
/*
* This function creates the items for the Loan Menu
* and return the address of its 1st element
*/
item* MenuBuilder::LoanMenu()
{
    static item LoanMenuItem[LOANMENU_SIZ];
    LoanMenuItem[0].setItem(15,21,EXISTINGMEMBER,"EXISTING MEMBER");
    LoanMenuItem[1].setItem(55,21,NEWUSER,"NEW USER");
    LoanMenuItem[2].setItem(35,25,MAINMENU,"MAIN MENU");
    return &LoanMenuItem[0];
}
/*
* This function displays the contents for the menus
*/
void MenuBuilder::MenuShow(item *iptr,int size)
{
    int x;
    for (x=0;x<size;x++)
    {
        (iptr+x)->born();
    }
}
/*
* This function is used to return the vertical range of any menu
*/
int MenuBuilder::MenuRangeY(item *iptr,int size,int type)
{
	int max;
	int min;
	int x=0;
	switch(type)
	{
		case _MAX:
			max=(iptr+x)->getItemY();
			for(x=0;x<size;x++)
			{
				if (max<(iptr+x)->getItemY())
				{
					max=(iptr+x)->getItemY();
				}
			}
			return max;
		case _MIN:
			min=(iptr+x)->getItemY();
			for(x=0;x<size;x++)
			{
				if (min>(iptr+x)->getItemY())
				{
					min=(iptr+x)->getItemY();
				}
			}
			return min;
	}
	cout<<"Incorrect Type recieved"<<endl;
	return 0;
}
/*
* This function is used to return the horizontal range of any menu
*/
int MenuBuilder::MenuRangeX(item *iptr,int size,int type)
{
	int max;
	int min;
	int x=0;
	switch(type)
	{
		case _MAX:
			max=(iptr+x)->getItemX();
			for(x=0;x<size;x++)
			{
				if (max<(iptr+x)->getItemX())
				{
					max=(iptr+x)->getItemX();
				}
			}
			return max;
		case _MIN:
			min=(iptr+x)->getItemX();
			for(x=0;x<size;x++)
			{
				if (min>(iptr+x)->getItemX())
				{
					min=(iptr+x)->getItemX();
				}
			}
			return min;
	}
	cout<<"Incorrect Type recieved"<<endl;
	return 0;
}
/*
* This is the heart of the menu operations. This function controls
* the scrolling and selection of different menu items
*/
int MenuBuilder::menuBrowserOperator(item *iptr,int size,int MenuType)
{

    int position=0;
    int *posptr;
    int check=1;
    posptr=&position;
    bool read=false;

    /*
    * instantiating an handle data type
    * that will be able to store input handles
    */
    HANDLE hIn;
    /*
    * structure that stores information on the various
    * types of console inputs
    */
    INPUT_RECORD InRec;
    /*
    * will be used to store the amount of event read
    */
    DWORD AmtRead;
    scroller scr;
    scroller *scrptr;
    scrptr=&scr;
    /*
    * gets the console input handle and stores it
    */
    hIn=GetStdHandle(STD_INPUT_HANDLE);
    /*
    * initialises the scroller's position(top of the menu)
    */
    scrptr->setScroller((iptr+position)->getItemX(),(iptr+position)->getItemY(),
    (iptr+position)->getItemLenght());
    scrptr->scroll();

    while(!read && check!=0)
    {
        /*
        * This funtion reads the console input, both
        * keyboard and mouse
        */
        ReadConsoleInput(hIn,&InRec,1,&AmtRead);
        /*
        * case used to render the type of input,
        * wether KEY or MOUSE
        */
        switch(InRec.EventType)
        {
            case KEY_EVENT:
                /*
                * checks for a key being pressed
                * (going down)
                */
                if(InRec.Event.KeyEvent.bKeyDown)
                {
                    /*
                    * filters the type of key being pressed
                    */
                    switch(InRec.Event.KeyEvent.wVirtualKeyCode)
                    {
                        /*
                        * Tab key
                        */
                        case VK_TAB:
                            check=MenuProcessing(VK_TAB,iptr,posptr,scrptr,size,MenuType);
                        break;
                        /*
                        * Left arrow key
                        */
                        case VK_LEFT:
                            check=MenuProcessing(VK_LEFT,iptr,posptr,scrptr,size,MenuType);
                        break;
                        /*
                        * Right arrow key
                        */
                        case VK_RIGHT:
                            check=MenuProcessing(VK_RIGHT,iptr,posptr,scrptr,size,MenuType);
                        break;
                        /*
                        * Up arrow key
                        */
                        case VK_UP:
                            check=MenuProcessing(VK_UP,iptr,posptr,scrptr,size,MenuType);
                        break;
                        /*
                        * Down arrow key
                        */
                        case VK_DOWN:
                            check=MenuProcessing(VK_DOWN,iptr,posptr,scrptr,size,MenuType);
                        break;
                        /*
                        * Enter key
                        */
                        case VK_RETURN:
                            return MenuProcessing(VK_RETURN,iptr,posptr,scrptr,size,MenuType);
                        break;
                    }
                }
            break;
        }
    }
    return 0;
}
int MenuBuilder::MenuProcessing( int vKeyCode,item *iptr,int *pos,scroller *scr,int size,int MenuType)
{
    switch(vKeyCode)
    {
        /*
        * Left arrow key
        */
        case VK_LEFT:
            *pos=*pos-1;
            if(*pos<0)
            {
                if(MenuType==FORMMENU)
                {
                    scr->killScroll();
                    return 0;
                }
                *pos=size-1;
            }
            scr->killScroll();
            scr->setScroller((iptr+*pos)->getItemX(),(iptr+*pos)->getItemY(),
            (iptr+*pos)->getItemLenght());
            scr->scroll();
        break;
        /*
        * Tab Key
        */
        case VK_TAB:
        /*
        * Right arrow key
        */
        case VK_RIGHT:
            *pos=*pos+1;
            if(*pos>size-1)
            {
                if(MenuType==FORMMENU)
                {
                    scr->killScroll();
                    return 0;
                }
                *pos=0;
            }
            scr->killScroll();
            scr->setScroller((iptr+*pos)->getItemX(),(iptr+*pos)->getItemY(),
            (iptr+*pos)->getItemLenght());
            scr->scroll();
        break;
        /*
        * Up arrow key
        */
        case VK_UP:
            *pos=*pos-1;
            if(*pos<0)
            {
                if(MenuType==FORMMENU)
                {
                    scr->killScroll();
                    return 0;
                }
                *pos=size-1;
            }
            scr->killScroll();
            scr->setScroller((iptr+*pos)->getItemX(),(iptr+*pos)->getItemY(),
            (iptr+*pos)->getItemLenght());
            scr->scroll();
            break;
        /*
        * Down arrow key
        */
        case VK_DOWN:
            *pos=*pos+1;
            if(*pos>size-1)
            {
                if(MenuType==FORMMENU)
                {
                    scr->killScroll();
                    return 0;
                }
                *pos=0;
            }
            scr->killScroll();
            scr->setScroller((iptr+*pos)->getItemX(),(iptr+*pos)->getItemY(),
            (iptr+*pos)->getItemLenght());
            scr->scroll();
            break;
        /*
        * Enter key
        */
        case VK_RETURN:
			this->callMenu((iptr+*pos)->getCode());
            //return (iptr+*pos)->getCode();
        break;
    }
    return 1;
}

int MenuBuilder::EditMenuDriver()
{
    int result;
    string ReferenceNumber;
    string *ReferenceNumberPtr;
    ReferenceNumberPtr = &ReferenceNumber;
    result = this->EditInput(ReferenceNumberPtr);
    switch(result)
    {
        case VK_RETURN:
            return 0;
        break;
    }
    return 0;
}

int MenuBuilder::EditInput(string *ReferenceNumberPtr)
{
    int EditCoord[1][3];
    int position=0;
    EditCoord[0][0]=20;
    EditCoord[0][1]=20;
    EditCoord[0][2]=17;
    FormInputBuilder EditEntry;
    console consoleObj;
    consoleObj.xyCoord(EditCoord[position][0],EditCoord[position][1]);
    cout<<"Reference Number: ";
    return EditEntry.FormInput(ALPHANUMERIC,NOSPACING,ReferenceNumberPtr,6,EditCoord,position,true);
}

void MenuBuilder::BasicRunlevel(string MenuName,int consoleX, int consoleY)
{
	frame BaseFrame;
	console con;
	con.clearScreen();
	con.setConsoleSize(consoleX,consoleY);
	BaseFrame.setFrame(0,79,0,52,true);
	BaseFrame.dFraming();
	con.xyCoord(0,0);
	con.xyCoord(3,1);
	cout<<MenuName;
}
