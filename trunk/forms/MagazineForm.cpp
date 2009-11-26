#ifndef _MAGAZINEFORM_H
#include "MagazineForm.h"
#endif
#ifndef _MAGAZINE_H
#include "../Magazine.h"
#endif
#include <iostream>
#include <string>
#include <windows.h>
#include "../gui/console/console.h"
#ifndef DATABASE_FILE
#define DATABASE_FILE "database.sqlite"
#endif
#include "../sqlite3.h"
#include "../Glob_Defs.h"
#include "../RJM_SQLite_Resultset.h"

using namespace std;

MagazineForm::MagazineForm()
{
    this->magazinePtr = new Magazine;
    FieldPosition=0;
    InputPtr=&input;
    MagazineCoord[0][0]=25;
    MagazineCoord[0][1]=11;
    MagazineCoord[0][2]=21;

    MagazineCoord[1][0]=25;
    MagazineCoord[1][1]=14;
    MagazineCoord[1][2]=7;

    MagazineCoord[2][0]=25;
    MagazineCoord[2][1]=17;
    MagazineCoord[2][2]=8;

    MagazineCoord[3][0]=25;
    MagazineCoord[3][1]=20;
    MagazineCoord[3][2]=8;

    MagazineCoord[4][0]=25;
    MagazineCoord[4][1]=23;
    MagazineCoord[4][2]=12;

    MagazineCoord[5][0]=25;
    MagazineCoord[5][1]=26;
    MagazineCoord[5][2]=13;
}

MagazineForm::~MagazineForm()
{

}
void MagazineForm::browseForm()
{
	// 5 pointers needed for 5 inputs
	//cout << this->getFormType();system("sleep");
	bool read=false;
	int KeyType;
	consoleObj.xyCoord(MagazineCoord[0][0]+18,MagazineCoord[0][1]);
	cout<<this->magazinePtr->getReferenceNumberPrefix();
	consoleObj.xyCoord(MagazineCoord[FieldPosition][0]+MagazineCoord[FieldPosition][2]+AllInput[FieldPosition].length(),MagazineCoord[FieldPosition][1]);
	while(!read)
	{
	    switch(FieldPosition)
	    {
            case 0:
                *InputPtr = this->magazinePtr->getReferenceNumber();
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,NOSPACING,InputPtr,3,MagazineCoord,FieldPosition,false);
                this->magazinePtr->setReferenceNumber(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 1:
                *InputPtr = this->magazinePtr->getTitle();
                KeyType=FormInputBuilderObj.FormInput(ALPHANUMERIC,SPACING,InputPtr,15,MagazineCoord,FieldPosition,false);
                this->magazinePtr->setTitle(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 2:
                *InputPtr = this->magazinePtr->getAuthor();
                KeyType=FormInputBuilderObj.FormInput(ALPHABETICAL,SPACING,InputPtr,15,MagazineCoord,FieldPosition,false);
                this->magazinePtr->setAuthor(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 3:
                *InputPtr = this->magazinePtr->getVolume();
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,NOSPACING,InputPtr,3,MagazineCoord,FieldPosition,false);
                this->magazinePtr->setVolume(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;

            case 4:
                *InputPtr = this->magazinePtr->getIssueDate();
                KeyType=FormInputBuilderObj.FormInput(DATE,NOSPACING,InputPtr,8,MagazineCoord,FieldPosition,false);
                this->magazinePtr->setIssueDate(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;

            case 5:
                *InputPtr = this->magazinePtr->getIssueTopic();
                KeyType=FormInputBuilderObj.FormInput(ALPHANUMERIC,SPACING,InputPtr,15,MagazineCoord,FieldPosition,false);
                this->magazinePtr->setIssueTopic(*InputPtr);
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
        if(FieldPosition>5)
        {
            FieldPosition=5;
            read=true;
        }
        //*InputPtr = "";
        consoleObj.xyCoord(60,3);
        cout<< FieldPosition;
        consoleObj.xyCoord(MagazineCoord[FieldPosition][0]+MagazineCoord[FieldPosition][2]+AllInput[FieldPosition].length(),MagazineCoord[FieldPosition][1]);
    }
	consoleObj.setCursor(false,3);
}

void MagazineForm::browseEditForm(string referenceNumber)
{
	this->setReferenceNumber(referenceNumber);
	// 5 pointers needed for 5 inputs
	//cout << this->getFormType();system("sleep");
	bool read=false;
	int KeyType;
	consoleObj.xyCoord(MagazineCoord[0][0]+18,MagazineCoord[0][1]);
	cout<<referenceNumber;
	consoleObj.xyCoord(MagazineCoord[FieldPosition][0]+MagazineCoord[FieldPosition][2]+AllInput[FieldPosition].length(),MagazineCoord[FieldPosition][1]);
	while(!read)
	{
	    switch(FieldPosition)
	    {
            case 0:
                *InputPtr = this->magazinePtr->getReferenceNumber();
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,NOSPACING,InputPtr,0,MagazineCoord,FieldPosition,false);
                this->magazinePtr->setReferenceNumber(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 1:
                *InputPtr = this->magazinePtr->getTitle();
                KeyType=FormInputBuilderObj.FormInput(ALPHANUMERIC,SPACING,InputPtr,15,MagazineCoord,FieldPosition,false);
                this->magazinePtr->setTitle(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 2:
                *InputPtr = this->magazinePtr->getAuthor();
                KeyType=FormInputBuilderObj.FormInput(ALPHABETICAL,SPACING,InputPtr,15,MagazineCoord,FieldPosition,false);
                this->magazinePtr->setAuthor(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 3:
                *InputPtr = this->magazinePtr->getVolume();
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,NOSPACING,InputPtr,3,MagazineCoord,FieldPosition,false);
                this->magazinePtr->setVolume(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;

            case 4:
                *InputPtr = this->magazinePtr->getIssueDate();
                KeyType=FormInputBuilderObj.FormInput(DATE,NOSPACING,InputPtr,8,MagazineCoord,FieldPosition,false);
                this->magazinePtr->setIssueDate(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;

            case 5:
                *InputPtr = this->magazinePtr->getIssueTopic();
                KeyType=FormInputBuilderObj.FormInput(ALPHANUMERIC,SPACING,InputPtr,15,MagazineCoord,FieldPosition,false);
                this->magazinePtr->setIssueTopic(*InputPtr);
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
        if(FieldPosition>5)
        {
            FieldPosition=5;
            read=true;
        }
        //*InputPtr = "";
        consoleObj.xyCoord(60,3);
        cout<< FieldPosition;
        consoleObj.xyCoord(MagazineCoord[FieldPosition][0]+MagazineCoord[FieldPosition][2]+AllInput[FieldPosition].length(),MagazineCoord[FieldPosition][1]);
    }
	consoleObj.setCursor(false,3);
}

void MagazineForm::show()
{
	consoleObj.xyCoord(MagazineCoord[0][0],MagazineCoord[0][1]);
	cout<<"Reference Number: ";
	consoleObj.xyCoord(MagazineCoord[1][0],MagazineCoord[1][1]);
	cout<<"Title: ";
	consoleObj.xyCoord(MagazineCoord[2][0],MagazineCoord[2][1]);
	cout<<"Author: ";
	consoleObj.xyCoord(MagazineCoord[3][0],MagazineCoord[3][1]);
	cout<<"Volume: ";
    consoleObj.xyCoord(13,23);
	cout<<"<mm/dd/yy>";
	consoleObj.xyCoord(MagazineCoord[4][0],MagazineCoord[4][1]);
	cout<<"Issue Date: ";
	consoleObj.xyCoord(MagazineCoord[5][0],MagazineCoord[5][1]);
	cout<<"Issue Topic: ";
}

void MagazineForm::save()
{
    this->magazinePtr->insertReferenceNumberPrefix(this->magazinePtr->getReferenceNumber());
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
	l_query << "SELECT * FROM magazine WHERE referencenumber='" << this->magazinePtr->getReferenceNumber() << "';";
	pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);	
	if (!pRS->Valid()) {
		this->setState(STATE_FAILURE);
		message << "Invalid result set returned " << pRS->GetLastError();
		this->setError(message.str());
		SAFE_DELETE(pRS);
		sqlite3_close(l_sql_db);
	};
	rc = pRS->GetRowCount();
	SAFE_DELETE(pRS);
	if(rc>0)
	{
		this->setState(STATE_FAILURE);
		this->setError("A Magazine with the reference number already exists.");
	}else{
		l_query.str("");
		l_query << "insert into magazine (referencenumber, title, author, volume, issuedate, issuetopic)";
		//l_query << " values ("<<  <<", "<< <<", " <<", "<<", "<< <<", "<< <<", "<< <<")";
		l_query << " values ('"<<this->magazinePtr->getReferenceNumber()<<"','"<<this->magazinePtr->getTitle()<<"','"<<this->magazinePtr->getAuthor()<<"','"<< this->magazinePtr->getVolume()<<"','"<<this->magazinePtr->getIssueDate()<<"','"<<this->magazinePtr->getIssueTopic()<<"')";
		pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);	
		if (!pRS->Valid())
		{
			this->setState(STATE_FAILURE);
			message << "Invalid result set returned " << pRS->GetLastError();
			this->setError(message.str());
			SAFE_DELETE(pRS);
			sqlite3_close(l_sql_db);
		}else{
			SAFE_DELETE(pRS);
			l_query.str("");
			l_query << "select * FROM magazine WHERE referencenumber='"<<this->magazinePtr->getReferenceNumber()<<"'";
			pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);
			if (!pRS->Valid()) {
				//cout << "Invalid result set returned " << pRS->GetLastError() << endl;
				SAFE_DELETE(pRS);
				sqlite3_close(l_sql_db);
			};
			rc = pRS->GetRowCount();
			
			DB_DT_VARCHAR refNo;
			DB_DT_VARCHAR title;
			DB_DT_VARCHAR author;
			DB_DT_VARCHAR volume;
			DB_DT_VARCHAR topic;
			DB_DT_VARCHAR issuedate;

			pRS->GetColValueVARCHAR(0,0,&refNo);
			pRS->GetColValueVARCHAR(0,1,&title);
			pRS->GetColValueVARCHAR(0,2,&author);
			pRS->GetColValueVARCHAR(0,3,&volume);
			pRS->GetColValueVARCHAR(0,4,&topic);
			pRS->GetColValueVARCHAR(0,5,&issuedate);
			sqlite3_close(l_sql_db);
			SAFE_DELETE(pRS);
			
			Magazine* magazineObj = new Magazine(refNo,title,author,volume,topic,issuedate);
			this->setModel(magazineObj);
			this->setState(STATE_SUCCESS);
		};
	}
}

void MagazineForm::editSave()
{
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
		l_query << "UPDATE magazine SET title='"<<this->magazinePtr->getTitle()<<"', author='"<<this->magazinePtr->getAuthor()<<"', volume='"<<this->magazinePtr->getVolume()<<"', issuedate='"<<this->magazinePtr->getIssueDate()<<"', issueTopic='"<<this->magazinePtr->getIssueTopic()<<"' WHERE referencenumber='" << this->getReferenceNumber() << "';";
		pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);
		if (!pRS->Valid()) {
			message.str("");
			message << "Error occured while trying to edit reference material";
			SAFE_DELETE(pRS);
			this->setState(STATE_FAILURE);
			sqlite3_close(l_sql_db);
		}else{
			this->setState(STATE_SUCCESS);
			Magazine *magazineObj = new Magazine(this->getReferenceNumber(),this->magazinePtr->getTitle(),this->magazinePtr->getAuthor(),this->magazinePtr->getVolume(),this->magazinePtr->getIssueDate(),this->magazinePtr->getIssueTopic());
			this->setModel(magazineObj);
		}
	}
}
