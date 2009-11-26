#include"ReturnForm.h"

#include <iostream>
#include <string>
#ifndef DATABASE_FILE
#define DATABASE_FILE "database.sqlite"
#endif
#include "../sqlite3.h"
#include "../Glob_Defs.h"
#include "../RJM_SQLite_Resultset.h"
using namespace std;



ReturnForm::ReturnForm()
{
	this->loanPtr = new Loan();
    FieldPosition=0;
    InputPtr=&input;
    ReturnCoord[0][0]=25;
    ReturnCoord[0][1]=13;
    ReturnCoord[0][2]=18;

    ReturnCoord[1][0]=25;
    ReturnCoord[1][1]=16;
    ReturnCoord[1][2]=11;

    ReturnCoord[2][0]=25;
    ReturnCoord[2][1]=19;
    ReturnCoord[2][2]=6;
}

ReturnForm::~ReturnForm()
{
}

void ReturnForm::browseForm()
{
    //char* tempId;
	bool read=false;
	int KeyType;

	consoleObj.xyCoord(ReturnCoord[FieldPosition][0]+ReturnCoord[FieldPosition][2]+
	AllInput[FieldPosition].length(),ReturnCoord[FieldPosition][1]);

	while(!read)
	{

	    switch(FieldPosition)
	    {
            case 0:
				*InputPtr =  this->loanPtr->getReferenceNumber();
                KeyType=FormInputBuilderObj.FormInput(ALPHANUMERIC,NOSPACING,InputPtr,6,ReturnCoord,FieldPosition,false);
				this->loanPtr->setReferenceNumber(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 1:
                *InputPtr =  this->loanPtr->getMemberId();
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,NOSPACING,InputPtr,7,ReturnCoord,FieldPosition,false);
                this->loanPtr->setMemberId(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 2:
                *InputPtr =  this->loanPtr->getRequestDate();
                KeyType=FormInputBuilderObj.FormInput(DATE,SPACING,InputPtr,8,ReturnCoord,FieldPosition,false);
				this->loanPtr->setRequestDate(*InputPtr);
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
        if(FieldPosition>2)
        {
            FieldPosition = 2;
            read=true;
        }
        consoleObj.xyCoord(ReturnCoord[FieldPosition][0]+
        ReturnCoord[FieldPosition][2]+AllInput[FieldPosition].length(),
        ReturnCoord[FieldPosition][1]);
    }
	consoleObj.setCursor(false,3);
}

void ReturnForm::show()
{
    consoleObj.xyCoord(ReturnCoord[0][0],ReturnCoord[0][1]);
	cout<<"Reference Number: ";
	consoleObj.xyCoord(ReturnCoord[1][0],ReturnCoord[1][1]);
	cout<<"Id Number: ";
	consoleObj.xyCoord(ReturnCoord[2][0]-13,ReturnCoord[2][1]);
	cout<<"<dd/mm/yy>";
	consoleObj.xyCoord(ReturnCoord[2][0],ReturnCoord[2][1]);
	cout<<"Date: ";
}

void ReturnForm::save()
{
	string l_filename = DATABASE_FILE;
	ostringstream message;
	message.str("");
	ostringstream l_query;
	sqlite3* l_sql_db = NULL;
	
	int rc = sqlite3_open(l_filename.c_str(), &l_sql_db);
	if( rc ){
		sqlite3_close(l_sql_db);
		this->setState(STATE_FAILURE);
		this->setError("Error couldn't open SQLite database");
	};

	RJM_SQLite_Resultset *pRS = NULL;
	l_query.str("");
	l_query << "SELECT * FROM loan WHERE referencenumber='" << this->loanPtr->getReferenceNumber() << "' AND memberid='" <<this->loanPtr->getMemberId() <<"';";
	pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);	
	if (!pRS->Valid()) {
		this->setState(STATE_FAILURE);
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
			this->setError("No loan record exists with the details specified.");
		}else{
			l_query.str("");
			l_query << "DELETE FROM loan WHERE referencenumber='" << this->loanPtr->getReferenceNumber() << "' AND memberid='" <<this->loanPtr->getMemberId() <<"';";
			pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);	
			if (!pRS->Valid()) {
				this->setState(STATE_FAILURE);
				message << "Invalid result set returned " << pRS->GetLastError();
				this->setError(message.str());
				SAFE_DELETE(pRS);
				sqlite3_close(l_sql_db);
			}else{
				//SAFE_DELETE(pRS);
				//rc = pRS->getRowCount(); 
				if(pRS==NULL)
				{
					this->setState(STATE_FAILURE);
					message << "Error trying to complete the RETURN LOAN operation.";
					this->setError(message.str());
				}else{
					this->setState(STATE_SUCCESS);
					SAFE_DELETE(pRS);
				}
				sqlite3_close(l_sql_db);
			}
		}
	}
}
