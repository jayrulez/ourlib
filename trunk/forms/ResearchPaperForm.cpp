#ifndef _RESEARCHPAPERFORM_H
#include "ResearchpaperForm.h"
#endif
#ifndef _RESEARCHPAPER_H
#include "../ResearchPaper.h"
#endif
#ifndef DATABASE_FILE
#define DATABASE_FILE "database.sqlite"
#endif
#include "../sqlite3.h"
#include "../Glob_Defs.h"
#include "../RJM_SQLite_Resultset.h"
#include <iostream>
using namespace std;

ResearchPaperForm::ResearchPaperForm()
{
    this->researchPaperPtr = new ResearchPaper;
    FieldPosition=0;
    InputPtr=&input;
    ResearchPaperCoord[0][0]=25;
    ResearchPaperCoord[0][1]=12;
    ResearchPaperCoord[0][2]=21;

    ResearchPaperCoord[1][0]=25;
    ResearchPaperCoord[1][1]=15;
    ResearchPaperCoord[1][2]=7;

    ResearchPaperCoord[2][0]=25;
    ResearchPaperCoord[2][1]=18;
    ResearchPaperCoord[2][2]=8;

    ResearchPaperCoord[3][0]=25;
    ResearchPaperCoord[3][1]=21;
    ResearchPaperCoord[3][2]=16;

    ResearchPaperCoord[4][0]=25;
    ResearchPaperCoord[4][1]=24;
    ResearchPaperCoord[4][2]=12;

    ResearchPaperCoord[5][0]=25;
    ResearchPaperCoord[5][1]=27;
    ResearchPaperCoord[5][2]=9;

}

ResearchPaperForm::~ResearchPaperForm()
{

}

void ResearchPaperForm::browseForm()
{
	bool read=false;
	int KeyType;
    consoleObj.xyCoord(ResearchPaperCoord[0][0]+18,ResearchPaperCoord[0][1]);
	cout<<this->researchPaperPtr->getReferenceNumberPrefix();
	consoleObj.xyCoord(ResearchPaperCoord[FieldPosition][0]+ResearchPaperCoord[FieldPosition][2]+AllInput[FieldPosition].length(),ResearchPaperCoord[FieldPosition][1]);
	while(!read)
	{
	    switch(FieldPosition)
	    {
            case 0:
                *InputPtr = this->researchPaperPtr->getReferenceNumber();
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,NOSPACING,InputPtr,3,ResearchPaperCoord,FieldPosition,false);
                this->researchPaperPtr->setReferenceNumber(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 1:
                *InputPtr = this->researchPaperPtr->getTitle();
                KeyType=FormInputBuilderObj.FormInput(ALPHABETICAL,SPACING,InputPtr,15,ResearchPaperCoord,FieldPosition,false);
                this->researchPaperPtr->setTitle(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 2:
                *InputPtr = this->researchPaperPtr->getAuthor();
                KeyType=FormInputBuilderObj.FormInput(ALPHABETICAL,SPACING,InputPtr,20,ResearchPaperCoord,FieldPosition,false);
                this->researchPaperPtr->setAuthor(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 3:
                *InputPtr = this->researchPaperPtr->getResearchTopic();
                KeyType=FormInputBuilderObj.FormInput(ALPHANUMERIC,SPACING,InputPtr,15,ResearchPaperCoord,FieldPosition,false);
                this->researchPaperPtr->setResearchTopic(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;

            case 4:
                *InputPtr = this->researchPaperPtr->getSupervisor();
                KeyType=FormInputBuilderObj.FormInput(ALPHABETICAL,SPACING,InputPtr,15,ResearchPaperCoord,FieldPosition,false);
                this->researchPaperPtr->setSupervisor(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 5:
                *InputPtr = this->researchPaperPtr->getSponsor();
                KeyType=FormInputBuilderObj.FormInput(ALPHABETICAL,SPACING,InputPtr,15,ResearchPaperCoord,FieldPosition,false);
                this->researchPaperPtr->setSponsor(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
	    }
        switch(KeyType)
        {
            case VK_UP:
                if(FieldPosition<0)
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
        consoleObj.xyCoord(ResearchPaperCoord[FieldPosition][0]+ResearchPaperCoord[FieldPosition][2]+AllInput[FieldPosition].length(),ResearchPaperCoord[FieldPosition][1]);
    }
	consoleObj.setCursor(false,3);
}

void ResearchPaperForm::browseEditForm(string referenceNumber)
{
	this->setReferenceNumber(referenceNumber);
	bool read=false;
	int KeyType;
    consoleObj.xyCoord(ResearchPaperCoord[0][0]+18,ResearchPaperCoord[0][1]);
	cout<<referenceNumber;
	consoleObj.xyCoord(ResearchPaperCoord[FieldPosition][0]+ResearchPaperCoord[FieldPosition][2]+AllInput[FieldPosition].length(),ResearchPaperCoord[FieldPosition][1]);
	while(!read)
	{
	    switch(FieldPosition)
	    {
            case 0:
                *InputPtr = this->researchPaperPtr->getReferenceNumber();
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,NOSPACING,InputPtr,0,ResearchPaperCoord,FieldPosition,false);
                this->researchPaperPtr->setReferenceNumber(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 1:
                *InputPtr = this->researchPaperPtr->getTitle();
                KeyType=FormInputBuilderObj.FormInput(ALPHABETICAL,SPACING,InputPtr,15,ResearchPaperCoord,FieldPosition,false);
                this->researchPaperPtr->setTitle(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 2:
                *InputPtr = this->researchPaperPtr->getAuthor();
                KeyType=FormInputBuilderObj.FormInput(ALPHABETICAL,SPACING,InputPtr,20,ResearchPaperCoord,FieldPosition,false);
                this->researchPaperPtr->setAuthor(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 3:
                *InputPtr = this->researchPaperPtr->getResearchTopic();
                KeyType=FormInputBuilderObj.FormInput(ALPHANUMERIC,SPACING,InputPtr,15,ResearchPaperCoord,FieldPosition,false);
                this->researchPaperPtr->setResearchTopic(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;

            case 4:
                *InputPtr = this->researchPaperPtr->getSupervisor();
                KeyType=FormInputBuilderObj.FormInput(ALPHABETICAL,SPACING,InputPtr,15,ResearchPaperCoord,FieldPosition,false);
                this->researchPaperPtr->setSupervisor(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 5:
                *InputPtr = this->researchPaperPtr->getSponsor();
                KeyType=FormInputBuilderObj.FormInput(ALPHABETICAL,SPACING,InputPtr,15,ResearchPaperCoord,FieldPosition,false);
                this->researchPaperPtr->setSponsor(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
	    }
        switch(KeyType)
        {
            case VK_UP:
                if(FieldPosition<0)
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
        consoleObj.xyCoord(ResearchPaperCoord[FieldPosition][0]+ResearchPaperCoord[FieldPosition][2]+AllInput[FieldPosition].length(),ResearchPaperCoord[FieldPosition][1]);
    }
	consoleObj.setCursor(false,3);
}

void ResearchPaperForm::show()
{
	consoleObj.xyCoord(ResearchPaperCoord[0][0],ResearchPaperCoord[0][1]);
	cout<<"Reference Number: ";
	consoleObj.xyCoord(ResearchPaperCoord[1][0],ResearchPaperCoord[1][1]);
	cout<<"Title: ";
	consoleObj.xyCoord(ResearchPaperCoord[2][0],ResearchPaperCoord[2][1]);
	cout<<"Author: ";
    consoleObj.xyCoord(ResearchPaperCoord[3][0],ResearchPaperCoord[3][1]);
	cout<<"Research Topic: ";
	consoleObj.xyCoord(ResearchPaperCoord[4][0],ResearchPaperCoord[4][1]);
	cout<<"Supervisor: ";
	consoleObj.xyCoord(ResearchPaperCoord[5][0],ResearchPaperCoord[5][1]);
	cout<<"Sponsor: ";
}

void ResearchPaperForm::save()
{
    this->researchPaperPtr->insertReferenceNumberPrefix(this->researchPaperPtr->getReferenceNumber());
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
	l_query << "SELECT * FROM researchpaper WHERE referencenumber='" << this->researchPaperPtr->getReferenceNumber() << "';";
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
		this->setError("A Research Paper with the reference number already exists.");
	}else{
		l_query.str("");
		l_query << "insert into researchpaper (referencenumber, title, author, researchtopic, supervisor, sponsor)";
		//l_query << " values ("<<  <<", "<< <<", " <<", "<<", "<< <<", "<< <<", "<< <<")";
		l_query << " values ('"<<this->researchPaperPtr->getReferenceNumber()<<"','"<<this->researchPaperPtr->getTitle()<<"','"<<this->researchPaperPtr->getAuthor()<<"','"<< this->researchPaperPtr->getResearchTopic()<<"','"<<this->researchPaperPtr->getSupervisor()<<"','"<<this->researchPaperPtr->getSponsor()<<"')";
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
			l_query << "select * FROM researchpaper WHERE referencenumber='"<<this->researchPaperPtr->getReferenceNumber()<<"'";
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
			DB_DT_VARCHAR topic;
			DB_DT_VARCHAR supervisor;
			DB_DT_VARCHAR sponsor;

			pRS->GetColValueVARCHAR(0,0,&refNo);
			pRS->GetColValueVARCHAR(0,1,&title);
			pRS->GetColValueVARCHAR(0,2,&author);
			pRS->GetColValueVARCHAR(0,3,&topic);
			pRS->GetColValueVARCHAR(0,4,&supervisor);
			pRS->GetColValueVARCHAR(0,5,&sponsor);
			sqlite3_close(l_sql_db);
			SAFE_DELETE(pRS);
			ResearchPaper * researchPaperObj = new ResearchPaper(refNo,title,author,topic,supervisor,sponsor);
			this->setModel(researchPaperObj);
			this->setState(STATE_SUCCESS);
		};
	}
}

void ResearchPaperForm::editSave()
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
		l_query << "UPDATE researchpaper SET title='"<<this->researchPaperPtr->getTitle()<<"', author='"<<this->researchPaperPtr->getAuthor()<<"', researchtopic='"<<this->researchPaperPtr->getResearchTopic()<<"', supervisor='"<<this->researchPaperPtr->getSupervisor()<<"', sponsor='"<<this->researchPaperPtr->getSponsor()<<"' WHERE referencenumber='" << this->getReferenceNumber() << "';";
		pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);
		if (!pRS->Valid()) {
			message.str("");
			message << "Error occured while trying to edit reference material";
			SAFE_DELETE(pRS);
			this->setState(STATE_FAILURE);
			sqlite3_close(l_sql_db);
		}else{
			this->setState(STATE_SUCCESS);
			ResearchPaper *researchPaperObj = new ResearchPaper(this->getReferenceNumber(),this->researchPaperPtr->getTitle(),this->researchPaperPtr->getAuthor(),this->researchPaperPtr->getResearchTopic(),this->researchPaperPtr->getSupervisor(),this->researchPaperPtr->getSponsor());
			this->setModel(researchPaperObj);
		}
	}
}
