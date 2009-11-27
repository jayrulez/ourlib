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
#include <iostream>
#include <string>
#ifndef _FILEMODEL_H
#include "./FileModel.h"
#endif
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
#include "./gui/console/scroller.h"
#endif
#ifndef _DATE_H
#include "Date.h"
#endif

#define _MAX 2
#define _MIN 1
#include <string>
#ifndef FORM_H
#include "./forms/Form.h"
#endif
#ifndef _TEXTBOOK_H
#include "./TextBook.h"
#endif
#ifndef _TEXTBOOKFORM_H
#include "forms/TextBookForm.h"
#endif
#ifndef _MAGAZINE_H
#include "./Magazine.h"
#endif
#ifndef _MAGAZINEFORM_H
#include "./forms/MagazineForm.h"
#endif
#ifndef _RESEARCHPAPER_H
#include "./ResearchPaper.h"
#endif
#ifndef _RESEARCHPAPERFORM_H
#include "forms/ResearchPaperForm.h"
#endif
#ifndef _MEMBERFORM_H
#include "forms/MemberForm.h"
#endif
#ifndef LOANFORM_H
#include "forms/LoanForm.h"
#endif
#ifndef RETURNFORM_H
#include "forms/ReturnForm.h"
#endif
#ifndef FORMINPUTBUILDER_H
#include "forms/FormInputBuilder.h"
#endif
using namespace std;
#ifndef DATABASE_FILE
#define DATABASE_FILE "database.sqlite"
#endif
#include "./sqlite3.h"
#include "./Glob_Defs.h"
#include "./RJM_SQLite_Resultset.h"
/*
*
*/
MenuBuilder::MenuBuilder()
{
	this->formPtr = new Form();
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
            this->formPtr = new TextBookForm;
			this->formPtr->show();
		break;
		case RESEARCHPAPER:
            this->formPtr = new ResearchPaperForm;
			this->formPtr->show();
		break;
		case MAGAZINE:
            this->formPtr = new MagazineForm;
			this->formPtr->show();
		break;
	}
}

void MenuBuilder::callMenu(int menuId)
{
    console con;
    int TypeCheck;
    static int ReferenceType;
    static int MenuType;
    con.setCursor(false,50);

	switch(menuId)
	{
		case ADD:
            MenuType=ADDTYPE;
            this->BasicRunlevel("ADD MENU");
            this->MenuShow(this->AddReferenceMaterial(),ADDMENU_SIZ);
			this->menuBrowserOperator(this->AddReferenceMaterial(),ADDMENU_SIZ,NORMALMENU,true);
		break;
        case DEL:
            MenuType=DELETETYPE;
            this->BasicRunlevel("DELETE MENU");
            this->MenuShow(DeleteMenu(),DELETEMENU_SIZ);
            do
            {
                this->queryString = this->DeleteMenuDriver();
                TypeCheck=this->menuBrowserOperator(DeleteMenu(),DELETEMENU_SIZ,FORMMENU,true);
			}while(TypeCheck==0);
        break;
		case EDIT:
            MenuType=EDITTYPE;
            this->BasicRunlevel("EDIT MENU");
            this->MenuShow(EditMenu(),EDITMENU_SIZ);
			do
			{
                this->queryString = this->EditMenuDriver();
                TypeCheck=this->menuBrowserOperator(this->EditMenu(),EDITMENU_SIZ,FORMMENU,true);
			}while(TypeCheck==0);
        break;

        case SUBMIT:
            switch(MenuType)
            {
                 case ADDTYPE:
                    switch(ReferenceType)
                    {
                        case MAGAZINETYPE:
                            this->BasicRunlevel("ADD MAGAZINE");
                            break;
                        case RESEARCHPAPERTYPE:
                            this->BasicRunlevel("ADD RESEARCH PAPER");
                            break;
                        case TEXTBOOKTYPE:
                            this->BasicRunlevel("ADD TEXTBOOK");
                            break;
                    }
                    this->MenuShow(AddConfirmMenu(),ADDCONFIRMMENU_SIZ);
                    this->menuBrowserOperator(AddConfirmMenu(),ADDCONFIRMMENU_SIZ,NORMALMENU,true);
                    break;

                case EDITTYPE:
                    switch(ReferenceType)
                    {
                        case MAGAZINETYPE:
                            this->BasicRunlevel("EDIT MAGAZINE");
                            break;
                        case RESEARCHPAPERTYPE:
                            this->BasicRunlevel("EDIT RESEARCH PAPER");
                            break;
                        case TEXTBOOKTYPE:
                            this->BasicRunlevel("EDIT TEXTBOOK");
                            break;
					}
					this->MenuShow(EditConfirmMenu(),EDITCONFIRMMENU_SIZ);
                    this->menuBrowserOperator(EditConfirmMenu(),EDITCONFIRMMENU_SIZ,NORMALMENU,true);
                    break;

                case MEMBERTYPE:
                    this->BasicRunlevel("NEW USER CONFIRMATION");
                    this->MenuShow(MemberConfirmMenu(),ADDCONFIRMMENU_SIZ);
                    this->menuBrowserOperator(MemberConfirmMenu(),ADDCONFIRMMENU_SIZ,NORMALMENU,true);
                    break;
                case LOANTYPE:
                    this->BasicRunlevel("LOAN CONFIRMATION");
                    this->MenuShow(LoanConfirmMenu(),LOANCONFIRMMENU_SIZ);
                    this->menuBrowserOperator(LoanConfirmMenu(),LOANCONFIRMMENU_SIZ,NORMALMENU,true);
                    break;
                case RETURNTYPE:
                    this->BasicRunlevel("RETURN CONFIRMATION");
                    this->MenuShow(MemberConfirmMenu(),RETURNCONFIRMMENU_SIZ);
                    this->menuBrowserOperator(MemberConfirmMenu(),RETURNCONFIRMMENU_SIZ,NORMALMENU,true);
                    break;
                case DELETETYPE:
                    this->BasicRunlevel("DELETE CONFIRMATION");
                    this->MenuShow(DeleteConfirmMenu(),DELETECONFIRMMENU_SIZ);
                    this->menuBrowserOperator(DeleteConfirmMenu(),DELETECONFIRMMENU_SIZ,NORMALMENU,true);
                    break;
            }
        break;

        case CLEARFIELD:
            switch(MenuType)
            {
                case ADDTYPE:
                    switch(ReferenceType)
                    {
                        case TEXTBOOKTYPE:
                            callMenu(TEXTBOOK);
                            break;
                        case RESEARCHPAPERTYPE:
                            callMenu(RESEARCHPAPER);
                            break;
                        case MAGAZINETYPE:
                            callMenu(MAGAZINE);
                            break;
                    }
                    break;
                case EDITTYPE:
                    switch(ReferenceType)
                    {
                        case TEXTBOOKTYPE:
                            callMenu(TEXTBOOK);
                            break;
                        case RESEARCHPAPERTYPE:
                            callMenu(RESEARCHPAPER);
                            break;
                        case MAGAZINETYPE:
                            callMenu(MAGAZINE);
                            break;
                    }
                    break;
                case MEMBERTYPE:
                    callMenu(NEWUSER);
                    break;
                case LOANTYPE:
                    callMenu(EXISTINGMEMBER);
                    break;
                case RETURNTYPE:
                    callMenu(RETURN);
                    break;
            }
        break;

        case CANCEL:
            switch(MenuType)
            {
                case ADDTYPE:
                    switch(ReferenceType)
                    {

                        case TEXTBOOKTYPE:
                            callMenu(TEXTBOOK);
                            break;
                        case RESEARCHPAPERTYPE:
                            callMenu(RESEARCHPAPER);
                            break;
                        case MAGAZINETYPE:
                            callMenu(MAGAZINE);
                            break;
                    }
                    break;
                case EDITTYPE:
                    switch(ReferenceType)
                    {
                        case TEXTBOOKTYPE:
                            callMenu(TEXTBOOK);
                            break;
                        case RESEARCHPAPERTYPE:
                            callMenu(RESEARCHPAPER);
                            break;
                        case MAGAZINETYPE:
                            callMenu(MAGAZINE);
                            break;
                    }
                    break;
                case MEMBERTYPE:
                    callMenu(LOAN);
                    break;
                case LOANTYPE:
                    callMenu(LOAN);
                    break;
                case RETURNTYPE:
                    callMenu(RETURN);
                    break;
                case DELETETYPE:
                    callMenu(DEL);
                    break;
            }
        break;

        case SAVE:

            this->BasicRunlevel("ADD MENU");
            switch(MenuType)
            {
                case ADDTYPE:
                    switch(ReferenceType)
                    {
                        case MAGAZINETYPE:
                            this->BasicRunlevel("ADD MAGAZINE");
                            this->formPtr->save();
							switch(this->formPtr->getState())
							{
								case STATE_ERROR:
								case STATE_FAILURE:
									con.xyCoord(5,25);
									con.setColour(12);
									cout<<"Error: "<< this->formPtr->getError();
									con.setColour(15);
								break;
								case STATE_SUCCESS:
									this->formPtr->getModel()->showReferenceMaterial(20,15);
								break;
							}
                            break;
                        case RESEARCHPAPERTYPE:
                            this->BasicRunlevel("ADD RESEARCH PAPER");
                            this->formPtr->save();
							switch(this->formPtr->getState())
							{
								case STATE_ERROR:
								case STATE_FAILURE:
									con.xyCoord(5,15);
									con.setColour(12);
									cout<<"Error: " << this->formPtr->getError();
									con.setColour(15);
								break;
								case STATE_SUCCESS:
									this->formPtr->getModel()->showReferenceMaterial(20,15);
								break;
							}
                            break;
                        case TEXTBOOKTYPE:
                            this->BasicRunlevel("ADD TEXTBOOK");
                            this->formPtr->save();
							switch(this->formPtr->getState())
							{
								case STATE_ERROR:
								case STATE_FAILURE:
									con.xyCoord(5,15);
									con.setColour(12);
									cout<<"Error: " << this->formPtr->getError();
									con.setColour(15);
								break;
								case STATE_SUCCESS:
									this->formPtr->getModel()->showReferenceMaterial(20,15);
								break;
							}
                            break;
                    }
                    this->MenuShow(AddAfterSaveMenu(),AFTERSAVEMENU_SIZ);
                    this->menuBrowserOperator(AddAfterSaveMenu(),AFTERSAVEMENU_SIZ,NORMALMENU,true);
                break;
                case EDITTYPE:
				{
                    switch(ReferenceType)
                    {
                        case MAGAZINETYPE:
                            this->BasicRunlevel("EDIT MAGAZINE");
							this->formPtr->editSave();
							switch(this->formPtr->getState())
							{
								case STATE_ERROR:
								case STATE_FAILURE:
									con.xyCoord(5,15);
									con.setColour(12);
									cout<<"Error: " << this->formPtr->getError();
									con.setColour(15);
								break;
								case STATE_SUCCESS:
									this->formPtr->getModel()->showReferenceMaterial(17,15);
								break;
							}
                            break;
                        case RESEARCHPAPERTYPE:
                            this->BasicRunlevel("EDIT RESEARCH PAPER");
							this->formPtr->editSave();
							switch(this->formPtr->getState())
							{
								case STATE_ERROR:
								case STATE_FAILURE:
									con.xyCoord(5,15);
									con.setColour(12);
									cout<<"Error: " << this->formPtr->getError();
									con.setColour(15);
								break;
								case STATE_SUCCESS:
									this->formPtr->getModel()->showReferenceMaterial(17,15);
								break;
							}
                            break;
                        case TEXTBOOKTYPE:
                            this->BasicRunlevel("EDIT TEXTBOOK");
							this->formPtr->editSave();
							switch(this->formPtr->getState())
							{
								case STATE_ERROR:
								case STATE_FAILURE:
									con.xyCoord(5,15);
									con.setColour(12);
									cout<<"Error: " << this->formPtr->getError();
									con.setColour(15);
								break;
								case STATE_SUCCESS:
								con.xyCoord(25,10);
								cout << "Textbook changes saved.";
									this->formPtr->getModel()->showReferenceMaterial(17,10);
								break;
							}
                            break;
                    }
                    this->MenuShow(EditAfterSaveMenu(),AFTERSAVEMENU_SIZ);
                    this->menuBrowserOperator(EditAfterSaveMenu(),AFTERSAVEMENU_SIZ,NORMALMENU,true);
				}
                break;
                case MEMBERTYPE:
                    this->formPtr->save();
					switch(this->formPtr->getState())
					{
						case STATE_ERROR:
						case STATE_FAILURE:
							con.xyCoord(5,15);
							con.setColour(12);
							cout<<"Error: "<< this->formPtr->getError();
							con.setColour(15);
						break;
						case STATE_SUCCESS:
							this->formPtr->getMember()->showMember(17,5);
							con.xyCoord(20,15);
							cout << "Registration Completed Successfully.";
						break;
					}
					this->MenuShow(LoanAfterSaveMenu(),AFTERSAVEMENU_SIZ);
                    this->menuBrowserOperator(LoanAfterSaveMenu(),AFTERSAVEMENU_SIZ,NORMALMENU,true);
                    break;
                case LOANTYPE:
                    this->formPtr->save();
					switch(this->formPtr->getState())
					{
						case STATE_ERROR:
						case STATE_FAILURE:
							con.xyCoord(5,15);
							con.setColour(12);
							cout<<"Error: "<< this->formPtr->getError();
							con.setColour(15);
						break;
						case STATE_SUCCESS:
							this->formPtr->getLoan()->showLoan(17,15);
							con.xyCoord(20,15);
							cout << "Loan completed successfully.";
						break;
					}
					this->MenuShow(LoanAfterSaveMenu(),AFTERSAVEMENU_SIZ);
                    this->menuBrowserOperator(LoanAfterSaveMenu(),AFTERSAVEMENU_SIZ,NORMALMENU,true);
                    break;
                case RETURNTYPE:
                    this->formPtr->save();
					switch(this->formPtr->getState())
					{
						case STATE_ERROR:
						case STATE_FAILURE:
							con.xyCoord(5,20);
							con.setColour(12);
							cout<<"Error: " << this->formPtr->getError();
							con.setColour(15);
						break;
						case STATE_SUCCESS:
							con.xyCoord(25,15);
							cout << "Reference Material returned.";
						break;
					}
					this->MenuShow(ReturnAfterSaveMenu(),AFTERSAVEMENU_SIZ);
                    this->menuBrowserOperator(ReturnAfterSaveMenu(),AFTERSAVEMENU_SIZ,NORMALMENU,true);
                    break;
            }
        break;
		case SEARCH:
            switch(MenuType)
            {
                case DELETETYPE:
				{
					string l_filename = DATABASE_FILE;
					ostringstream message;
					message.str("");
					ostringstream l_query;
					sqlite3* l_sql_db = NULL;

					int rc = sqlite3_open(l_filename.c_str(), &l_sql_db);
					if( rc ){
						sqlite3_close(l_sql_db);
					};

					RJM_SQLite_Resultset *pRS = NULL;
					l_query.str("");

					ReferenceMaterial * refObj = new ReferenceMaterial();
					//if(this->queryString.empty())this->queryString="";
					int materialType = refObj->getMaterialTypeFromReferenceNumber(this->queryString);
					l_query << "select * FROM loan WHERE referencenumber='"<<this->queryString<<"'";
					pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);	
					if (!pRS->Valid())
					{
						this->BasicRunlevel("ERROR");
						con.xyCoord(5,15);
						con.setColour(12);
						cout << "Error: " << pRS->GetLastError();
						con.setColour(15);
						SAFE_DELETE(pRS);
						sqlite3_close(l_sql_db);
						this->MenuShow(AfterDeleteMenu(),AFTERSAVEMENU_SIZ);
						this->menuBrowserOperator(AfterDeleteMenu(),AFTERSAVEMENU_SIZ,NORMALMENU,true);

					}else{
						rc = pRS->GetRowCount();
						SAFE_DELETE(pRS);
						if(rc>0)
						{
							this->BasicRunlevel("ERROR");
							con.xyCoord(7,15);
							con.setColour(12);
							cout << "Error: You cannot delete a reference material that is on loan.";
							con.setColour(15);
							this->MenuShow(AfterDeleteMenu(),AFTERSAVEMENU_SIZ);
							this->menuBrowserOperator(AfterDeleteMenu(),AFTERSAVEMENU_SIZ,NORMALMENU,true);
						}else{
							switch(materialType)
							{
								case TYPE_TEXTBOOK:
								{
									l_query.str("");
									l_query << "select * FROM textbook WHERE referencenumber='"<<this->queryString<<"'";
									pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);	
									if (!pRS->Valid()) {
										this->BasicRunlevel("ERROR");
										con.xyCoord(5,15);
										con.setColour(12);
										cout << "Error: " << pRS->GetLastError();
										con.setColour(15);
										SAFE_DELETE(pRS);
										sqlite3_close(l_sql_db);
										this->MenuShow(AfterDeleteMenu(),AFTERSAVEMENU_SIZ);
										this->menuBrowserOperator(AfterDeleteMenu(),AFTERSAVEMENU_SIZ,NORMALMENU,true);
									}else{
										rc = pRS->GetRowCount();
										SAFE_DELETE(pRS);
										if(rc>0)
										{
											l_query.str("");
											l_query << "delete FROM textbook WHERE referencenumber='" << this->queryString << "'";
											pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);	
											if (!pRS->Valid()) {
												this->BasicRunlevel("ERROR");
												con.xyCoord(5,15);
												con.setColour(12);
												cout << "Error: " << pRS->GetLastError();
												con.setColour(15);
												SAFE_DELETE(pRS);
												sqlite3_close(l_sql_db);
												this->MenuShow(AfterDeleteMenu(),AFTERSAVEMENU_SIZ);
												this->menuBrowserOperator(AfterDeleteMenu(),AFTERSAVEMENU_SIZ,NORMALMENU,true);
											}else{
												if(pRS!=NULL)
												{
													this->BasicRunlevel("OPERATION SUCCESSFUL");
													con.xyCoord(20,15);
													cout << "Textbook deleted successfully.";
													SAFE_DELETE(pRS);
													this->MenuShow(AfterDeleteMenu(),AFTERSAVEMENU_SIZ);
													this->menuBrowserOperator(AfterDeleteMenu(),AFTERSAVEMENU_SIZ,NORMALMENU,true);
												}else{
													this->BasicRunlevel("ERROR");
													con.xyCoord(5,15);
													con.setColour(12);
													cout << "Error: Could not delete textbook.";
													con.setColour(15);
													this->MenuShow(AfterDeleteMenu(),AFTERSAVEMENU_SIZ);
													this->menuBrowserOperator(AfterDeleteMenu(),AFTERSAVEMENU_SIZ,NORMALMENU,true);
												}
											}
										}else{
											this->BasicRunlevel("ERROR");
											con.xyCoord(5,15);
											con.setColour(12);
											cout << "Error: No textbook was found with the reference number provided.";
											con.setColour(15);
											this->MenuShow(AfterDeleteMenu(),AFTERSAVEMENU_SIZ);
											this->menuBrowserOperator(AfterDeleteMenu(),AFTERSAVEMENU_SIZ,NORMALMENU,true);
										}
										sqlite3_close(l_sql_db);
									}
								}
								break;
								case TYPE_MAGAZINE:
																{
									l_query.str("");
									l_query << "select * FROM magazine WHERE referencenumber='"<<this->queryString<<"'";
									pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);	
									if (!pRS->Valid()) {
										this->BasicRunlevel("ERROR");
										con.xyCoord(5,15);
										con.setColour(12);
										cout << "Error: " << pRS->GetLastError();
										con.setColour(15);
										SAFE_DELETE(pRS);
										sqlite3_close(l_sql_db);
										this->MenuShow(AfterDeleteMenu(),AFTERSAVEMENU_SIZ);
										this->menuBrowserOperator(AfterDeleteMenu(),AFTERSAVEMENU_SIZ,NORMALMENU,true);
									}else{
										rc = pRS->GetRowCount();
										SAFE_DELETE(pRS);
										if(rc>0)
										{
											l_query.str("");
											l_query << "delete FROM magazine WHERE referencenumber='" << this->queryString << "'";
											pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);	
											if (!pRS->Valid()) {
												this->BasicRunlevel("ERROR");
												con.xyCoord(5,15);
												con.setColour(12);
												cout << "Error: " << pRS->GetLastError();
												con.setColour(15);
												SAFE_DELETE(pRS);
												sqlite3_close(l_sql_db);
												this->MenuShow(AfterDeleteMenu(),AFTERSAVEMENU_SIZ);
												this->menuBrowserOperator(AfterDeleteMenu(),AFTERSAVEMENU_SIZ,NORMALMENU,true);
											}else{
												if(pRS!=NULL)
												{
													this->BasicRunlevel("OPERATION SUCCESSFUL");
													con.xyCoord(20,15);
													cout << "Magazine deleted successfully.";
													SAFE_DELETE(pRS);
													this->MenuShow(AfterDeleteMenu(),AFTERSAVEMENU_SIZ);
													this->menuBrowserOperator(AfterDeleteMenu(),AFTERSAVEMENU_SIZ,NORMALMENU,true);
												}else{
													this->BasicRunlevel("ERROR");
													con.xyCoord(20,15);
													con.setColour(12);
													cout << "Error: Could not delete magazine.";
													con.setColour(15);
													this->MenuShow(AfterDeleteMenu(),AFTERSAVEMENU_SIZ);
													this->menuBrowserOperator(AfterDeleteMenu(),AFTERSAVEMENU_SIZ,NORMALMENU,true);
												}
											}
										}else{
											this->BasicRunlevel("ERROR");
											con.xyCoord(5,15);
											con.setColour(12);
											cout << "Error: No magazine was found with the reference number provided.";
											con.setColour(15);
											this->MenuShow(AfterDeleteMenu(),AFTERSAVEMENU_SIZ);
											this->menuBrowserOperator(AfterDeleteMenu(),AFTERSAVEMENU_SIZ,NORMALMENU,true);
										}
										sqlite3_close(l_sql_db);
									}
								}
								break;
								case TYPE_RESEARCHPAPER:
																{
									l_query.str("");
									l_query << "select * FROM researchpaper WHERE referencenumber='"<<this->queryString<<"'";
									pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);	
									if (!pRS->Valid()) {
										this->BasicRunlevel("ERROR");
										con.xyCoord(5,15);
										con.setColour(12);
										cout << "Error: " << pRS->GetLastError();
										con.setColour(15);
										SAFE_DELETE(pRS);
										sqlite3_close(l_sql_db);
										this->MenuShow(AfterDeleteMenu(),AFTERSAVEMENU_SIZ);
										this->menuBrowserOperator(AfterDeleteMenu(),AFTERSAVEMENU_SIZ,NORMALMENU,true);
									}else{
										rc = pRS->GetRowCount();
										SAFE_DELETE(pRS);
										if(rc>0)
										{
											l_query.str("");
											l_query << "delete FROM researchpaper WHERE referencenumber='" << this->queryString << "'";
											pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);	
											if (!pRS->Valid()) {
												this->BasicRunlevel("ERROR");
												con.xyCoord(5,15);
												con.setColour(12);
												cout << "Error: " << pRS->GetLastError();
												con.setColour(15);
												SAFE_DELETE(pRS);
												sqlite3_close(l_sql_db);
												this->MenuShow(AfterDeleteMenu(),AFTERSAVEMENU_SIZ);
												this->menuBrowserOperator(AfterDeleteMenu(),AFTERSAVEMENU_SIZ,NORMALMENU,true);
											}else{
												if(pRS!=NULL)
												{
													this->BasicRunlevel("OPERATION SUCCESSFUL");
													con.xyCoord(20,15);
													cout << "Research Paper deleted successfully.";
													SAFE_DELETE(pRS);
													this->MenuShow(AfterDeleteMenu(),AFTERSAVEMENU_SIZ);
													this->menuBrowserOperator(AfterDeleteMenu(),AFTERSAVEMENU_SIZ,NORMALMENU,true);
												}else{
													this->BasicRunlevel("ERROR");
													con.xyCoord(15,15);
													con.setColour(12);
													cout << "Error: Could not delete Research Paper.";
													con.setColour(15);
													this->MenuShow(AfterDeleteMenu(),AFTERSAVEMENU_SIZ);
													this->menuBrowserOperator(AfterDeleteMenu(),AFTERSAVEMENU_SIZ,NORMALMENU,true);
												}
											}
										}else{
											this->BasicRunlevel("ERROR");
											con.xyCoord(5,15);
											con.setColour(12);
											cout << "Error: No Research Paper was found with the reference number provided.";
											con.setColour(15);
											this->MenuShow(AfterDeleteMenu(),AFTERSAVEMENU_SIZ);
											this->menuBrowserOperator(AfterDeleteMenu(),AFTERSAVEMENU_SIZ,NORMALMENU,true);
										}
										sqlite3_close(l_sql_db);
									}
								}
								break;
								case TYPE_NONEXISTENT:
								default:
									this->BasicRunlevel("ERROR");
									con.xyCoord(5,15);
									con.setColour(12);
									cout << "Error: No Research Paper was found with the reference number provided.";
									con.setColour(15);
									this->MenuShow(AfterDeleteMenu(),AFTERSAVEMENU_SIZ);
									this->menuBrowserOperator(AfterDeleteMenu(),AFTERSAVEMENU_SIZ,NORMALMENU,true);
								break;
							}
						}
					}
				}
                break;
                case EDITTYPE:
				{
					string l_filename = DATABASE_FILE;
					ostringstream message;
					message.str("");
					ostringstream l_query;
					sqlite3* l_sql_db = NULL;

					int rc = sqlite3_open(l_filename.c_str(), &l_sql_db);
					if( rc ){
						sqlite3_close(l_sql_db);
					};

					RJM_SQLite_Resultset *pRS = NULL;

					ReferenceMaterial* refObj = new ReferenceMaterial();
					int materialType = refObj->getMaterialTypeFromReferenceNumber(this->queryString);
					switch(materialType)
					{
						case TYPE_TEXTBOOK:
						{
							ReferenceType=TEXTBOOKTYPE;
							l_query.str("");
							l_query << "select * FROM textbook WHERE referencenumber='"<<this->queryString<<"'";
							pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);	
							if (!pRS->Valid()) {
								this->BasicRunlevel("ERROR");
								con.xyCoord(5,15);
								con.setColour(12);
								cout << "Error: " << pRS->GetLastError();
								con.setColour(15);
								SAFE_DELETE(pRS);
								sqlite3_close(l_sql_db);
								this->callMenu(EDIT);
							}else{
								rc = pRS->GetRowCount();
								SAFE_DELETE(pRS);
								sqlite3_close(l_sql_db);
							
								if(rc>0)
								{
									this->formPtr = new TextBookForm;
									ReferenceType=TEXTBOOKTYPE;
									this->BasicRunlevel("EDIT TEXTBOOK");
									this->showReferenceMaterialForm(TEXTBOOK);
									this->MenuShow(this->EditFormMenu(),EDITFORMMENU_SIZ);
									do
									{
										this->formPtr->browseEditForm(this->queryString);
										TypeCheck=this->menuBrowserOperator(this->EditFormMenu(),EDITFORMMENU_SIZ,FORMMENU,true);
									}while(TypeCheck==0);
								}else{
									this->BasicRunlevel("ERROR");
									con.xyCoord(5,15);
									con.setColour(12);
									cout << "Error: No Textbook record exitst with the reference number provided.";
									con.setColour(15);
									this->MenuShow(EditAfterSaveMenu(),AFTERSAVEMENU_SIZ);
									this->menuBrowserOperator(EditAfterSaveMenu(),AFTERSAVEMENU_SIZ,NORMALMENU,true);
								}
							}
						}
						break;
						case TYPE_MAGAZINE:
						{
							ReferenceType=MAGAZINETYPE;
							l_query.str("");
							l_query << "select * FROM magazine WHERE referencenumber='"<<this->queryString<<"'";
							pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);	
							if (!pRS->Valid()) {
								this->BasicRunlevel("ERROR");
								con.xyCoord(5,15);
								con.setColour(12);
								cout << "Error: " << pRS->GetLastError();
								con.setColour(15);
								SAFE_DELETE(pRS);
								sqlite3_close(l_sql_db);
								this->callMenu(EDIT);
							}else{
								rc = pRS->GetRowCount();
								SAFE_DELETE(pRS);
								
								sqlite3_close(l_sql_db);
								
								if(rc>0)
								{
									this->formPtr = new MagazineForm;
									ReferenceType=MAGAZINETYPE;
									this->BasicRunlevel("EDIT MAGAZINE");
									this->showReferenceMaterialForm(MAGAZINE);
									this->MenuShow(this->EditFormMenu(),EDITFORMMENU_SIZ);
									do
									{
										this->formPtr->browseEditForm(this->queryString);
										TypeCheck=this->menuBrowserOperator(this->EditFormMenu(),EDITFORMMENU_SIZ,FORMMENU,true);
									}while(TypeCheck==0);
								}else{
									this->BasicRunlevel("ERROR");
									con.xyCoord(5,15);
									con.setColour(12);
									cout << "Error: No magazine record exists with the reference number provided";
									con.setColour(15);
									this->MenuShow(EditAfterSaveMenu(),AFTERSAVEMENU_SIZ);
									this->menuBrowserOperator(EditAfterSaveMenu(),AFTERSAVEMENU_SIZ,NORMALMENU,true);
								}
							}
						}
						break;
						case TYPE_RESEARCHPAPER:
						{
							ReferenceType=RESEARCHPAPERTYPE;
							l_query.str("");
							l_query << "select * FROM researchpaper WHERE referencenumber='"<<this->queryString<<"'";
							pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);	
							if (!pRS->Valid()) {
								SAFE_DELETE(pRS);
								sqlite3_close(l_sql_db);
								con.xyCoord(5,15);
								con.setColour(12);
								cout << "Error: " <<pRS->GetLastError();
								con.setColour(15);
							}else{
								rc = pRS->GetRowCount();
								SAFE_DELETE(pRS);
								
								sqlite3_close(l_sql_db);
								
								if(rc>0)
								{
									this->formPtr = new ResearchPaperForm;
									this->formPtr->setFormType(TYPE_EDIT);
									ReferenceType=RESEARCHPAPERTYPE;
									this->BasicRunlevel("EDIT RESEARCH PAPER");
									this->showReferenceMaterialForm(RESEARCHPAPER);
									this->MenuShow(this->EditFormMenu(),EDITFORMMENU_SIZ);
									do
									{
										this->formPtr->browseEditForm(this->queryString);
										TypeCheck=this->menuBrowserOperator(this->EditFormMenu(),EDITFORMMENU_SIZ,FORMMENU,true);
									}while(TypeCheck==0);
								}else{
									this->BasicRunlevel("ERROR");
									con.xyCoord(18,15);
									con.setColour(12);
									cout << "Error: No such research paper exists.";
									con.setColour(15);
									this->MenuShow(EditAfterSaveMenu(),AFTERSAVEMENU_SIZ);
									this->menuBrowserOperator(EditAfterSaveMenu(),AFTERSAVEMENU_SIZ,NORMALMENU,true);
								}
							}
						}
						break;
						case TYPE_NONEXISTENT:
						default:
						{
							this->BasicRunlevel("ERROR");
							con.xyCoord(20,15);
							con.setColour(12);
							cout << "Error: Invalid reference Number provided.";
							con.setColour(15);
							this->MenuShow(EditAfterSaveMenu(),AFTERSAVEMENU_SIZ);
							this->menuBrowserOperator(EditAfterSaveMenu(),AFTERSAVEMENU_SIZ,NORMALMENU,true);
						}
						break;
					}
				}
                break;
            }
        break;
		case RESEARCHPAPER:
            this->formPtr = new ResearchPaperForm;
			this->formPtr->setFormType(TYPE_ADD);
            ReferenceType=RESEARCHPAPERTYPE;
			this->BasicRunlevel("ADD RESEARCH PAPER");
			this->showReferenceMaterialForm(RESEARCHPAPER);
			this->MenuShow(this->AddFormMenu(),ADDFORMMENU_SIZ);
			do
			{
                this->formPtr->browseForm();
				if(this->formPtr->validate())
				{
					TypeCheck=this->menuBrowserOperator(this->AddFormMenu(),ADDFORMMENU_SIZ,FORMMENU,false);
					continue;
				}
				TypeCheck=this->menuBrowserOperator(this->AddFormMenu(),ADDFORMMENU_SIZ,FORMMENU,true);
            }while(TypeCheck==0);
		break;

		case TEXTBOOK:
            this->formPtr = new TextBookForm;
			this->formPtr->setFormType(TYPE_ADD);
            ReferenceType=TEXTBOOKTYPE;
			this->BasicRunlevel("ADD TEXTBOOK");
			this->showReferenceMaterialForm(TEXTBOOK);
			this->MenuShow(this->AddFormMenu(),ADDFORMMENU_SIZ);
			do
			{
                this->formPtr->browseForm();
				if(this->formPtr->validate())
				{
					TypeCheck=this->menuBrowserOperator(this->AddFormMenu(),ADDFORMMENU_SIZ,FORMMENU,false);
					continue;
				}
				TypeCheck=this->menuBrowserOperator(this->AddFormMenu(),ADDFORMMENU_SIZ,FORMMENU,true);
			}while(TypeCheck==0);
        break;

		case MAGAZINE:
            this->formPtr = new MagazineForm;
			this->formPtr->setFormType(TYPE_ADD);
            ReferenceType=MAGAZINETYPE;
			this->BasicRunlevel("ADD MAGAZINE");
			this->showReferenceMaterialForm(MAGAZINE);
			this->MenuShow(this->AddFormMenu(),ADDFORMMENU_SIZ);
			do
			{
                this->formPtr->browseForm();
				if(this->formPtr->validate())
				{
					TypeCheck=this->menuBrowserOperator(this->AddFormMenu(),ADDFORMMENU_SIZ,FORMMENU,false);
					continue;
				}
				TypeCheck=this->menuBrowserOperator(this->AddFormMenu(),ADDFORMMENU_SIZ,FORMMENU,true);
			}while(TypeCheck==0);
		break;

		case LOAN:
            this->BasicRunlevel("LOAN MENU");
			this->MenuShow(this->LoanMenu(),LOANMENU_SIZ);
			this->menuBrowserOperator(this->LoanMenu(),LOANMENU_SIZ,NORMALMENU,true);
		break;

		case EXISTINGMEMBER:
            formPtr = new LoanForm;
            MenuType=LOANTYPE;
            this->BasicRunlevel("LOAN MENU");
            this->formPtr->show();
            this->MenuShow(this->LoanFormMenu(),EXISTINGUSERMENU_SIZ);
			do
			{
                this->formPtr->browseForm();
				if(this->formPtr->validate())
				{
					TypeCheck=this->menuBrowserOperator(this->LoanFormMenu(),EXISTINGUSERMENU_SIZ,FORMMENU,false);
					continue;
				}
				TypeCheck=this->menuBrowserOperator(this->LoanFormMenu(),EXISTINGUSERMENU_SIZ,FORMMENU,true);
			}while(TypeCheck==0);

		break;

        case NEWUSER:
            this->formPtr = new MemberForm;
            MenuType=MEMBERTYPE;
            this->BasicRunlevel("NEW USER REGISTRATION");
            this->formPtr->show();
            this->MenuShow(this->AddMemberFormMenu(),ADDMEMBERFORMMENU_SIZ);
			do
			{
                this->formPtr->browseForm();
				if(this->formPtr->validate())
				{
					TypeCheck=this->menuBrowserOperator(this->AddMemberFormMenu(),ADDMEMBERFORMMENU_SIZ,FORMMENU,false);
					continue;
				}
				TypeCheck=this->menuBrowserOperator(this->AddMemberFormMenu(),ADDMEMBERFORMMENU_SIZ,FORMMENU,true);
			}while(TypeCheck==0);
        break;

        case RETURN:
            formPtr = new ReturnForm;
            MenuType=RETURNTYPE;
            this->BasicRunlevel("RETURN MENU");
            formPtr->show();
            this->MenuShow(this->ReturnFormMenu(),RETURNMENU_SIZ);
			do
			{
                formPtr->browseForm();
				if(this->formPtr->validate())
				{
					TypeCheck=this->menuBrowserOperator(this->ReturnFormMenu(),RETURNMENU_SIZ,FORMMENU,false);
					continue;
				}
				TypeCheck=this->menuBrowserOperator(this->ReturnFormMenu(),RETURNMENU_SIZ,FORMMENU,true);
			}while(TypeCheck==0);
        break;

		default:
            this->BasicRunlevel("MAIN MENU");
			this->MenuShow(this->MainMenu(),MAIN_SIZ);
			this->menuBrowserOperator(this->MainMenu(),MAIN_SIZ,NORMALMENU,true);
		break;

		case EXIT:
            formPtr = new ReturnForm;
            MenuType=EXITTYPE;
            this->BasicRunlevel("EXIT CONFIRMATION");
            this->MenuShow(this->ExitConfirmMenu(),2);
            TypeCheck=this->menuBrowserOperator(this->ExitConfirmMenu(),2,NORMALMENU,true);
        break;
		case TERMINATE:
			exit(0);
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
item* MenuBuilder::AddFormMenu()
{
    static item AddFormMenuItem[ADDFORMMENU_SIZ];
    AddFormMenuItem[0].setItem(15,35,SUBMIT,"SUBMIT");
    AddFormMenuItem[1].setItem(35,35,CLEARFIELD,"CLEAR FIELDS");
    AddFormMenuItem[2].setItem(55,35,ADD,"<-- ADD MENU");
    AddFormMenuItem[3].setItem(35,39,MAINMENU,"MAIN MENU");
    return &AddFormMenuItem[0];
}

/*
*   This function creates menu items for the Add Member Form
*/
item* MenuBuilder::AddMemberFormMenu()
{
    static item AddMemberFormMenuItem[ADDMEMBERFORMMENU_SIZ];
    AddMemberFormMenuItem[0].setItem(15,35,SUBMIT,"SUBMIT");
    AddMemberFormMenuItem[1].setItem(35,35,CLEARFIELD,"CLEAR FIELDS");
    AddMemberFormMenuItem[2].setItem(55,35,LOAN,"<-- LOAN MENU");
    AddMemberFormMenuItem[3].setItem(35,39,MAINMENU,"MAIN MENU");
    return &AddMemberFormMenuItem[0];
}
/*
*   This function creates menu items for the Edit Menu
*/
item* MenuBuilder::EditMenu()
{
    static item EditMenuItem[EDITMENU_SIZ];
    EditMenuItem[0].setItem(25,32,SEARCH,"SEARCH");
    EditMenuItem[1].setItem(45,32,MAINMENU,"MAINMENU");
    return &EditMenuItem[0];
}
item* MenuBuilder::EditFormMenu()
{
    static item EditFormMenuItem[EDITFORMMENU_SIZ];
    EditFormMenuItem[0].setItem(15,45,SUBMIT,"SUBMIT");
    EditFormMenuItem[1].setItem(35,45,CLEARFIELD,"CLEAR FIELDS");
    EditFormMenuItem[2].setItem(55,45,EDIT,"<-- EDIT MENU");
    EditFormMenuItem[3].setItem(35,49,MAINMENU,"MAIN MENU");
    return &EditFormMenuItem[0];
}
item* MenuBuilder::EditConfirmMenu()
{
    static item EditConfirmMenuItem[EDITCONFIRMMENU_SIZ];
    EditConfirmMenuItem[0].setItem(20,25,SAVE,"SAVE CHANGES");
    EditConfirmMenuItem[1].setItem(50,25,CANCEL,"CANCEL");
    return &EditConfirmMenuItem[0];
}
item* MenuBuilder::AddConfirmMenu()
{
    static item AddConfirmMenuItem[ADDCONFIRMMENU_SIZ];
    AddConfirmMenuItem[0].setItem(20,20,SAVE,"SAVE MATERIAL");
    AddConfirmMenuItem[1].setItem(50,20,CANCEL,"CANCEL");
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
*   This function creates menu items for the Loan Form
*/
item* MenuBuilder::LoanFormMenu()
{
    static item LoanFormMenuItem[EXISTINGUSERMENU_SIZ];
    LoanFormMenuItem[0].setItem(15,35,SUBMIT,"SUBMIT");
    LoanFormMenuItem[1].setItem(35,35,CLEARFIELD,"CLEAR FIELDS");
    LoanFormMenuItem[2].setItem(55,35,LOAN,"<-- LOAN MENU");
    LoanFormMenuItem[3].setItem(35,39,MAINMENU,"MAIN MENU");
    return &LoanFormMenuItem[0];
}
/*
*   This function creates menu items for the Loan Confirmation Menu
*/
item* MenuBuilder::LoanConfirmMenu()
{
    static item LoanConfirmMenuItem[LOANCONFIRMMENU_SIZ];
    LoanConfirmMenuItem[0].setItem(20,20,SAVE,"SAVE LOAN DATA");
    LoanConfirmMenuItem[1].setItem(50,20,CANCEL,"CANCEL");
    return &LoanConfirmMenuItem[0];
}
/*
*   This function creates menu items for the Return Form
*/
item* MenuBuilder::ReturnFormMenu()
{
    static item ReturnFormMenuItem[RETURNMENU_SIZ];
    ReturnFormMenuItem[0].setItem(15,35,SUBMIT,"SUBMIT");
    ReturnFormMenuItem[1].setItem(35,35,CLEARFIELD,"CLEAR FIELDS");
    ReturnFormMenuItem[2].setItem(55,35,MAINMENU,"MAIN MENU");
    return &ReturnFormMenuItem[0];
}
/*
*   This function creates menu items for the Return Confoirmation Menu
*/
item* MenuBuilder::ReturnConfirmMenu()
{
    static item ReturnConfirmMenuItem[RETURNCONFIRMMENU_SIZ];
    ReturnConfirmMenuItem[0].setItem(20,20,SAVE,"SAVE RETURN DATA");
    ReturnConfirmMenuItem[1].setItem(50,20,CANCEL,"CANCEL");
    return &ReturnConfirmMenuItem[0];
}
item* MenuBuilder::MemberConfirmMenu()
{
    static item MemberConfirmMenuItem[MEMBERCONFIRMMENU_SIZ];
    MemberConfirmMenuItem[0].setItem(20,20,SAVE,"SAVE MEMBER DATA");
    MemberConfirmMenuItem[1].setItem(50,20,CANCEL,"CANCEL");
    return &MemberConfirmMenuItem[0];
}
/*
*   This function creates menu items for the Delete Menu
*/
item* MenuBuilder::DeleteMenu()
{
    static item DeleteMenuItem[DELETEMENU_SIZ];
    DeleteMenuItem[0].setItem(25,32,SEARCH,"SEARCH");
    DeleteMenuItem[1].setItem(45,32,MAINMENU,"MAINMENU");
    return &DeleteMenuItem[0];
}
/*
*   This function creates menu items for the Delete Menu
*/
item* MenuBuilder::DeleteConfirmMenu()
{
    static item DeleteConfirmMenuItem[DELETECONFIRMMENU_SIZ];
    DeleteConfirmMenuItem[0].setItem(20,20,SAVE,"DELETE MATERIAL");
    DeleteConfirmMenuItem[1].setItem(50,20,CANCEL,"CANCEL");
    return &DeleteConfirmMenuItem[0];
}
/*
*   This function creates menu items for after save
*/
item* MenuBuilder::AddAfterSaveMenu()
{
    static item AddAfterSaveMenuItem[AFTERSAVEMENU_SIZ];
    AddAfterSaveMenuItem[0].setItem(20,35,ADD,"<--ADD MENU");
    AddAfterSaveMenuItem[1].setItem(50,35,MAINMENU,"MAIN MENU");
    return &AddAfterSaveMenuItem[0];
}
/*
*   This function creates menu items for after save
*/
item* MenuBuilder::EditAfterSaveMenu()
{
    static item EditAfterSaveMenuItem[AFTERSAVEMENU_SIZ];
    EditAfterSaveMenuItem[0].setItem(20,35,EDIT,"<--EDIT MENU");
    EditAfterSaveMenuItem[1].setItem(50,35,MAINMENU,"MAIN MENU");
    return &EditAfterSaveMenuItem[0];
}
/*
* This function displays menu items after the loan is executed.
*/
item* MenuBuilder::LoanAfterSaveMenu()
{
    static item LoanAfterSaveMenuItem[AFTERSAVEMENU_SIZ];
    LoanAfterSaveMenuItem[0].setItem(20,35,LOAN,"<--LOAN MENU");
    LoanAfterSaveMenuItem[1].setItem(50,35,MAINMENU,"MAIN MENU");
    return &LoanAfterSaveMenuItem[0];
}
/*
* This function displays menu items after returning a material
*/
item* MenuBuilder::ReturnAfterSaveMenu()
{
    static item ReturnAfterSaveMenuItem[AFTERSAVEMENU_SIZ];
    ReturnAfterSaveMenuItem[0].setItem(20,35,RETURN,"<--RETURN MENU");
    ReturnAfterSaveMenuItem[1].setItem(50,35,MAINMENU,"MAIN MENU");
    return &ReturnAfterSaveMenuItem[0];
}
item* MenuBuilder::AfterDeleteMenu()
{
    static item AfterDeleteMenuItem[AFTERSAVEMENU_SIZ];
    AfterDeleteMenuItem[0].setItem(20,35,DEL,"<--DELETE MENU");
    AfterDeleteMenuItem[1].setItem(50,35,MAINMENU,"MAIN MENU");
    return &AfterDeleteMenuItem[0];
}
item* MenuBuilder::ExitConfirmMenu()
{
	 static item ExitConfirmMenuItem[2];
    ExitConfirmMenuItem[0].setItem(20,20,TERMINATE,"EXIT PROGRAM");
    ExitConfirmMenuItem[1].setItem(50,20,MAINMENU,"<--MAIN MENU");
    return &ExitConfirmMenuItem[0];
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
int MenuBuilder::menuBrowserOperator(item *iptr,int size,int MenuType,bool validate)
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
                            check=MenuProcessing(VK_TAB,iptr,posptr,scrptr,size,MenuType,validate);
                        break;
                        /*
                        * Left arrow key
                        */
                        case VK_LEFT:
                            check=MenuProcessing(VK_LEFT,iptr,posptr,scrptr,size,MenuType,validate);
                        break;
                        /*
                        * Right arrow key
                        */
                        case VK_RIGHT:
                            check=MenuProcessing(VK_RIGHT,iptr,posptr,scrptr,size,MenuType,validate);
                        break;
                        /*
                        * Up arrow key
                        */
                        case VK_UP:
                            check=MenuProcessing(VK_UP,iptr,posptr,scrptr,size,MenuType,validate);
                        break;
                        /*
                        * Down arrow key
                        */
                        case VK_DOWN:
                            check=MenuProcessing(VK_DOWN,iptr,posptr,scrptr,size,MenuType,validate);
                        break;
                        /*
                        * Enter key
                        */
                        case VK_RETURN:
                            return MenuProcessing(VK_RETURN,iptr,posptr,scrptr,size,MenuType,validate);
                        break;
                    }
                }
            break;
        }
    }
    return 0;
}
int MenuBuilder::MenuProcessing( int vKeyCode,item *iptr,int *pos,scroller *scr,int size,int MenuType, bool validate)
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
			if(MenuType=FORMMENU && (iptr+*pos)->getCode()==SUBMIT && !validate)
			{
				return 0;
			}
			this->callMenu((iptr+*pos)->getCode());
            //return (iptr+*pos)->getCode();
        break;
    }
    return 1;
}

string MenuBuilder::EditMenuDriver()
{
    string ReferenceNumber;
    string *ReferenceNumberPtr;
    ReferenceNumberPtr = &ReferenceNumber;
    this->EditInput(ReferenceNumberPtr);
    return ReferenceNumber;
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
string MenuBuilder::DeleteMenuDriver()
{
    int result;
    string ReferenceNumber;
    string *ReferenceNumberPtr;
    ReferenceNumberPtr = &ReferenceNumber;
    result = this->DeleteInput(ReferenceNumberPtr);
    return ReferenceNumber;
}

int MenuBuilder::DeleteInput(string *ReferenceNumberPtr)
{
    int DeleteCoord[1][3];
    int position=0;
    DeleteCoord[0][0]=20;
    DeleteCoord[0][1]=20;
    DeleteCoord[0][2]=17;
    FormInputBuilder DeleteEntry;
    console consoleObj;
    consoleObj.xyCoord(DeleteCoord[position][0],DeleteCoord[position][1]);
    cout<<"Reference Number: ";
    return DeleteEntry.FormInput(ALPHANUMERIC,NOSPACING,ReferenceNumberPtr,6,DeleteCoord,position,true);
}

void MenuBuilder::BasicRunlevel(string MenuName,int consoleX, int consoleY)
{
	Date *dateObj = new Date();
	frame BaseFrame;
	console con;
	con.clearScreen();
	con.setConsoleSize(consoleX,consoleY);
	BaseFrame.setFrame(0,79,0,52,true);
	BaseFrame.dFraming();
	con.xyCoord(0,0);
	con.xyCoord(3,1);
	cout<<MenuName;
	con.xyCoord(53,1);
	cout<<dateObj->sysDate();
}

