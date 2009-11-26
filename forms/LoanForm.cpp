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
#ifndef LOANFORM_H
#include "LoanForm.h"
#endif

#ifndef DATABASE_FILE
#define DATABASE_FILE "database.sqlite"
#endif
#include "../sqlite3.h"
#include "../Glob_Defs.h"
#include "../RJM_SQLite_Resultset.h"
#include <string>
#include <iostream>
#include <cctype>
using namespace std;

LoanForm::LoanForm()
{
	this->loanPtr = new Loan();
    FieldPosition=0;
    InputPtr=&input;
    LoanCoord[0][0]=25;
    LoanCoord[0][1]=13;
    LoanCoord[0][2]=18;

    LoanCoord[1][0]=25;
    LoanCoord[1][1]=16;
    LoanCoord[1][2]=11;

    LoanCoord[2][0]=25;
    LoanCoord[2][1]=19;
    LoanCoord[2][2]=6;

    LoanCoord[3][0]=25;
    LoanCoord[3][1]=22;
    LoanCoord[3][2]=11;
}
LoanForm::~LoanForm()
{
}

void LoanForm::browseForm()
{
	bool read=false;
	int KeyType;
	string s;

	consoleObj.xyCoord(LoanCoord[FieldPosition][0]+LoanCoord[FieldPosition][2]+AllInput[FieldPosition].length(),LoanCoord[FieldPosition][1]);
	while(!read)
	{

	    switch(FieldPosition)
	    {
            case 0:
                *InputPtr =  this->loanPtr->getReferenceNumber();
                KeyType=FormInputBuilderObj.FormInput(ALPHANUMERIC,NOSPACING,InputPtr,6,LoanCoord,FieldPosition,false);
				this->loanPtr->setReferenceNumber(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 1:
                *InputPtr= this->loanPtr->getMemberId();
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,NOSPACING,InputPtr,7,LoanCoord,FieldPosition,false);
				this->loanPtr->setMemberId(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 2:
				*InputPtr = this->loanPtr->getRequestDate();
                KeyType=FormInputBuilderObj.FormInput(DATE,SPACING,InputPtr,8,LoanCoord,FieldPosition,false);
				this->loanPtr->setRequestDate(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;

            case 3:
                *InputPtr = this->loanPtr->getLoanType();
                KeyType=FormInputBuilderObj.FormInput(ALPHABETICAL,SPACING,InputPtr,3,LoanCoord,FieldPosition,false);
                this->loanPtr->setLoanType(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;

	    }
        switch(KeyType)
        {
            case VK_UP:
                if(FieldPosition<=0)
                {
                    FieldPosition=0;
                    break;
                }else{
                    FieldPosition-=1;
                }
            break;
            case VK_RETURN:
                FieldPosition+=1;
            break;
            case VK_TAB:
                FieldPosition+=1;
            break;
            case VK_DOWN:
                FieldPosition+=1;
            break;
        }
        if(FieldPosition>3)
        {
            FieldPosition = 3;
            read=true;
        }
        consoleObj.xyCoord(LoanCoord[FieldPosition][0]+
        LoanCoord[FieldPosition][2]+AllInput[FieldPosition].length(),
        LoanCoord[FieldPosition][1]);
    }
	consoleObj.setCursor(false,3);
}

void LoanForm::show()
{
    consoleObj.xyCoord(LoanCoord[0][0],LoanCoord[0][1]);
	cout<<"Reference Number: ";
	consoleObj.xyCoord(LoanCoord[1][0],LoanCoord[1][1]);
	cout<<"Id Number: ";
	consoleObj.xyCoord(LoanCoord[2][0]-13,LoanCoord[2][1]);
	cout<<"<dd/mm/yy>";
	consoleObj.xyCoord(LoanCoord[2][0],LoanCoord[2][1]);
	cout<<"Date: ";
    consoleObj.xyCoord(LoanCoord[3][0]-11,LoanCoord[3][1]);
    cout<<"<IN/OUT>";
    consoleObj.xyCoord(LoanCoord[3][0],LoanCoord[3][1]);
    cout<<"Loan Type: ";

}
void LoanForm::save()
{
	//this->loanPtr->showLoan(10,5);
	string l_filename = DATABASE_FILE;
	ostringstream message;
	ostringstream l_query;
	sqlite3* l_sql_db = NULL;
	
	int rc = sqlite3_open(l_filename.c_str(), &l_sql_db);
	if( rc ){
		sqlite3_close(l_sql_db);
		this->setState(STATE_FAILURE);
		this->setError("Error couldn't open SQLite database");
	}else{
		RJM_SQLite_Resultset *pRS = NULL;
		l_query.str("");
		l_query << "SELECT * FROM loan WHERE referencenumber='" << this->loanPtr->getReferenceNumber() << "';";
		pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);
		if (!pRS->Valid())
		{
			this->setState(STATE_FAILURE);
			message.str("");
			message << "Invalid result set returned " << pRS->GetLastError();
			this->setError(message.str());
			SAFE_DELETE(pRS);
			sqlite3_close(l_sql_db);
		}else{
			rc = pRS->GetRowCount();
			SAFE_DELETE(pRS);
			if(rc>0)
			{
				this->setState(STATE_FAILURE);
				message.str("");
				message << "Requested research material is already on loan.";
				this->setError(message.str());
				sqlite3_close(l_sql_db);
			}else{
				l_query.str("");
				l_query << "SELECT * FROM member WHERE id='" << this->loanPtr->getMemberId() << "';";
				pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);
				if (!pRS->Valid())
				{
					this->setState(STATE_FAILURE);
					message.str("");
					message << "Invalid result set returned " << pRS->GetLastError();
					this->setError(message.str());
					SAFE_DELETE(pRS);
					sqlite3_close(l_sql_db);
				}else{
					rc = pRS->GetRowCount();
					SAFE_DELETE(pRS);
					if(rc<1)
					{
						this->setState(STATE_FAILURE);
						message.str("");
						message << "No user exists with the specified id.";
						this->setError(message.str());
						sqlite3_close(l_sql_db);
					}else{
						l_query.str("");
						l_query << "SELECT * FROM loan WHERE memberid='" << this->loanPtr->getMemberId() << "';";
						pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);
						if (!pRS->Valid())
						{
							this->setState(STATE_FAILURE);
							message.str("");
							message << "Invalid result set returned " << pRS->GetLastError();
							this->setError(message.str());
							SAFE_DELETE(pRS);
							sqlite3_close(l_sql_db);
						}else{
							rc = pRS->GetRowCount();
							SAFE_DELETE(pRS);
							if(rc>=3)
							{
								this->setState(STATE_FAILURE);
								message.str("");
								message << "The member with the id specified already has 3 loans.";
								this->setError(message.str());
								sqlite3_close(l_sql_db);
							}else{
								if(this->loanPtr->getLoanType().compare("IN")==0||this->loanPtr->getLoanType().compare("OUT")==0)
								{
									l_query.str("");
									l_query << "SELECT * FROM loan WHERE memberid='" << this->loanPtr->getMemberId() << "' AND loantype='"<<this->loanPtr->getLoanType()<<"';";
									pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);
									if (!pRS->Valid())
									{
										this->setState(STATE_FAILURE);
										message.str("");
										message << "Invalid result set returned " << pRS->GetLastError();
										this->setError(message.str());
										SAFE_DELETE(pRS);
										sqlite3_close(l_sql_db);
									}else{
										rc = pRS->GetRowCount();
										SAFE_DELETE(pRS);
										int limit;
										if(this->loanPtr->getLoanType().compare("IN")==0)
											limit=3;
										else
											limit=1;
										if(rc>=limit)
										{
											this->setState(STATE_FAILURE);
											message.str("");
											message << "The user already has "<< rc <<" loan of type " << this->loanPtr->getLoanType()<<".";
											this->setError(message.str());
											sqlite3_close(l_sql_db);
										}else{
											ReferenceMaterial * refObj = new ReferenceMaterial();
											int materialType = refObj->getMaterialTypeFromReferenceNumber(this->loanPtr->getReferenceNumber());
											switch(materialType)
											{
												case TYPE_TEXTBOOK:
												{
													l_query.str("");
													l_query << "SELECT * FROM textbook WHERE referencenumber='" << this->loanPtr->getReferenceNumber() << "';";
													pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);
													if (!pRS->Valid())
													{
														this->setState(STATE_FAILURE);
														message.str("");
														message << "Invalid result set returned " << pRS->GetLastError();
														this->setError(message.str());
														SAFE_DELETE(pRS);
														sqlite3_close(l_sql_db);
													}else{
														rc = pRS->GetRowCount();
														SAFE_DELETE(pRS);
														if(rc<1)
														{
															this->setState(STATE_FAILURE);
															message.str("");
															message << "No textbook exists with the reference number specified.";
															this->setError(message.str());
															sqlite3_close(l_sql_db);
														}else{
															l_query.str("");
															l_query << "insert into loan (memberid,referencenumber, requestdate, loantype)";
															l_query << " values ('"<<this->loanPtr->getMemberId()<<"','"<<this->loanPtr->getReferenceNumber()<<"','"<<this->loanPtr->getRequestDate()<<"','"<<this->loanPtr->getLoanType()<<"')";
															pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);	
															if (!pRS->Valid())
															{
																this->setState(STATE_FAILURE);
																message.str("");
																message << "Invalid result set returned " << pRS->GetLastError();
																this->setError(message.str());
																SAFE_DELETE(pRS);
																sqlite3_close(l_sql_db);
															}else{
																rc = pRS->GetRowCount();
																SAFE_DELETE(pRS);
																this->setState(STATE_SUCCESS);
																sqlite3_close(l_sql_db);
															}
														}
													}
												}
												break;
												case TYPE_MAGAZINE:
												{
													l_query.str("");
													l_query << "SELECT * FROM magazine WHERE referencenumber='" << this->loanPtr->getReferenceNumber() << "';";
													pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);
													if (!pRS->Valid())
													{
														this->setState(STATE_FAILURE);
														message.str("");
														message << "Invalid result set returned " << pRS->GetLastError();
														this->setError(message.str());
														SAFE_DELETE(pRS);
														sqlite3_close(l_sql_db);
													}else{
														rc = pRS->GetRowCount();
														SAFE_DELETE(pRS);
														if(rc<1)
														{
															this->setState(STATE_FAILURE);
															message.str("");
															message << "No magazine exists with the reference number specified.";
															this->setError(message.str());
															sqlite3_close(l_sql_db);
														}else{
															l_query.str("");
															l_query << "insert into loan (memberid,referencenumber, requestdate, loantype)";
															l_query << " values ('"<<this->loanPtr->getMemberId()<<"','"<<this->loanPtr->getReferenceNumber()<<"','"<<this->loanPtr->getRequestDate()<<"','"<<this->loanPtr->getLoanType()<<"')";
															pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);	
															if (!pRS->Valid())
															{
																this->setState(STATE_FAILURE);
																message.str("");
																message << "Invalid result set returned " << pRS->GetLastError();
																this->setError(message.str());
																SAFE_DELETE(pRS);
																sqlite3_close(l_sql_db);
															}else{
																rc = pRS->GetRowCount();
																SAFE_DELETE(pRS);
																this->setState(STATE_SUCCESS);
																sqlite3_close(l_sql_db);
															}
														}
													}
												}
												break;
												case TYPE_RESEARCHPAPER:
												{
													l_query.str("");
													l_query << "SELECT * FROM researchpaper WHERE referencenumber='" << this->loanPtr->getReferenceNumber() << "';";
													pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);
													if (!pRS->Valid())
													{
														this->setState(STATE_FAILURE);
														message.str("");
														message << "Invalid result set returned " << pRS->GetLastError();
														this->setError(message.str());
														SAFE_DELETE(pRS);
														sqlite3_close(l_sql_db);
													}else{
														rc = pRS->GetRowCount();
														SAFE_DELETE(pRS);
														if(rc<1)
														{
															this->setState(STATE_FAILURE);
															message.str("");
															message << "No research paper exists with the reference number specified.";
															this->setError(message.str());
															sqlite3_close(l_sql_db);
														}else{
															l_query.str("");
															l_query << "insert into loan (memberid,referencenumber, requestdate, loantype)";
															l_query << " values ('"<<this->loanPtr->getMemberId()<<"','"<<this->loanPtr->getReferenceNumber()<<"','"<<this->loanPtr->getRequestDate()<<"','"<<this->loanPtr->getLoanType()<<"')";
															pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);	
															if (!pRS->Valid())
															{
																this->setState(STATE_FAILURE);
																message.str("");
																message << "Invalid result set returned " << pRS->GetLastError();
																this->setError(message.str());
																SAFE_DELETE(pRS);
																sqlite3_close(l_sql_db);
															}else{
																rc = pRS->GetRowCount();
																SAFE_DELETE(pRS);
																this->setState(STATE_SUCCESS);
																sqlite3_close(l_sql_db);
															}
														}
													}
												}
												break;
												case TYPE_NONEXISTENT:
												default:
												{
													this->setState(STATE_FAILURE);
													message.str("");
													message << "The reference number you entered is invalid";
													this->setError(message.str());
													sqlite3_close(l_sql_db);
												}
												break;
											}
										}
									}
								}else{
									this->setState(STATE_FAILURE);
									message.str("");
									message << "Loan type must be 'IN' or 'OUT' (case-sensative).";
									this->setError(message.str());
									sqlite3_close(l_sql_db);
								}								
							}
						}
					}
				}
			}
		}
	}
	if(this->getState()==STATE_SUCCESS)
	{
		this->setLoan(this->loanPtr);
	}
}
