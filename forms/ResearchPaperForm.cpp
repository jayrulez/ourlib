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
                KeyType=FormInputBuilderObj.FormInput(ALPHABETICAL,SPACING,InputPtr,45,ResearchPaperCoord,FieldPosition,false);
                this->researchPaperPtr->setTitle(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 2:
                *InputPtr = this->researchPaperPtr->getAuthor();
                KeyType=FormInputBuilderObj.FormInput(ALPHABETICAL,SPACING,InputPtr,40,ResearchPaperCoord,FieldPosition,false);
                this->researchPaperPtr->setAuthor(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 3:
                *InputPtr = this->researchPaperPtr->getResearchTopic();
                KeyType=FormInputBuilderObj.FormInput(ALPHANUMERIC,SPACING,InputPtr,35,ResearchPaperCoord,FieldPosition,false);
                this->researchPaperPtr->setResearchTopic(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;

            case 4:
                *InputPtr = this->researchPaperPtr->getSupervisor();
                KeyType=FormInputBuilderObj.FormInput(ALPHABETICAL,SPACING,InputPtr,30,ResearchPaperCoord,FieldPosition,false);
                this->researchPaperPtr->setSupervisor(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 5:
                *InputPtr = this->researchPaperPtr->getSponsor();
                KeyType=FormInputBuilderObj.FormInput(ALPHABETICAL,SPACING,InputPtr,30,ResearchPaperCoord,FieldPosition,false);
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
	consoleObj.xyCoord(ResearchPaperCoord[0][0],ResearchPaperCoord[0][1]-3);
	consoleObj.setColour(12);
	cout << "Only fill in the fields you wish to update.";
	consoleObj.setColour(15);
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
                KeyType=FormInputBuilderObj.FormInput(ALPHABETICAL,SPACING,InputPtr,45,ResearchPaperCoord,FieldPosition,false);
                this->researchPaperPtr->setTitle(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 2:
                *InputPtr = this->researchPaperPtr->getAuthor();
                KeyType=FormInputBuilderObj.FormInput(ALPHABETICAL,SPACING,InputPtr,40,ResearchPaperCoord,FieldPosition,false);
                this->researchPaperPtr->setAuthor(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 3:
                *InputPtr = this->researchPaperPtr->getResearchTopic();
                KeyType=FormInputBuilderObj.FormInput(ALPHANUMERIC,SPACING,InputPtr,35,ResearchPaperCoord,FieldPosition,false);
                this->researchPaperPtr->setResearchTopic(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;

            case 4:
                *InputPtr = this->researchPaperPtr->getSupervisor();
                KeyType=FormInputBuilderObj.FormInput(ALPHABETICAL,SPACING,InputPtr,30,ResearchPaperCoord,FieldPosition,false);
                this->researchPaperPtr->setSupervisor(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 5:
                *InputPtr = this->researchPaperPtr->getSponsor();
                KeyType=FormInputBuilderObj.FormInput(ALPHABETICAL,SPACING,InputPtr,30,ResearchPaperCoord,FieldPosition,false);
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
				message.str("");
				message << pRS->GetLastError();
				this->setState(STATE_FAILURE);
				this->setError(message.str());
				SAFE_DELETE(pRS);
				sqlite3_close(l_sql_db);
			}else{
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
				SAFE_DELETE(pRS);
				ResearchPaper * researchPaperObj = new ResearchPaper(refNo,title,author,topic,supervisor,sponsor);
				this->setModel(researchPaperObj);
				this->setState(STATE_SUCCESS);
				sqlite3_close(l_sql_db);
			}
		}
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
		if(this->researchPaperPtr->getTitle().length()<1
		&&this->researchPaperPtr->getAuthor().length()<1
		&&this->researchPaperPtr->getResearchTopic().length()<1
		&&this->researchPaperPtr->getSupervisor().length()<1
		&&this->researchPaperPtr->getSponsor().length()<1)
		{
			this->setState(STATE_FAILURE);
			this->setError("You must fill in atleast one field to update.");
		}else{
			l_query << "UPDATE researchpaper SET referencenumber='"<<this->getReferenceNumber()<<"'";
			if(this->researchPaperPtr->getTitle().length()>1)
			{
				l_query << ", title='"<<this->researchPaperPtr->getTitle()<<"'";
			}
			if(this->researchPaperPtr->getAuthor().length()>1)
			{
				l_query << ", author='"<<this->researchPaperPtr->getAuthor()<<"'";
			}
			if(this->researchPaperPtr->getResearchTopic().length()>1)
			{
				l_query << ", researchtopic='"<<this->researchPaperPtr->getResearchTopic()<<"'";
			}
			if(this->researchPaperPtr->getSupervisor().length()>1)
			{
				l_query << ", supervisor='"<<this->researchPaperPtr->getSupervisor()<<"'";
			}
			if(this->researchPaperPtr->getSponsor().length()>1)
			{
				l_query << ", sponsor='"<<this->researchPaperPtr->getSponsor()<<"'";
			}
			l_query << " WHERE referencenumber='" << this->getReferenceNumber() << "';";
			pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);
			if (!pRS->Valid()) {
				message.str("");
				message << "Error occured while trying to edit reference material";
				SAFE_DELETE(pRS);
				this->setState(STATE_FAILURE);
				sqlite3_close(l_sql_db);
			}else{
				this->setState(STATE_SUCCESS);
				SAFE_DELETE(pRS);
				l_query.str("");
				l_query << "select * FROM researchpaper WHERE referencenumber='"<<this->getReferenceNumber()<<"'";
				pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);
				if (!pRS->Valid()) {\
					SAFE_DELETE(pRS);
					sqlite3_close(l_sql_db);
				}else{
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
					SAFE_DELETE(pRS);
					ResearchPaper * researchPaperObj = new ResearchPaper(refNo,title,author,topic,supervisor,sponsor);
					this->setModel(researchPaperObj);
					sqlite3_close(l_sql_db);
				}
			}
		}
	}
}
bool ResearchPaperForm::validate()
{
	int formSize=7;
	int NullCue[7];
	bool incomplete=false;
	for(int pos=0;pos<formSize;pos++)
	{
		if(AllInput[pos].empty())
			NullCue[pos]=1;
		else
			NullCue[pos]=0;	
		if(NullCue[pos]==1)
		{
			consoleObj.xyCoord(ResearchPaperCoord[pos][0]-15,ResearchPaperCoord[pos][1]); 
			consoleObj.setColour(12);
			cout<<"<Required>";
			consoleObj.setColour(15);
			incomplete=true;
		}
	}
	return incomplete;
}