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
#ifndef _TEXTBOOKFORM_H
#include "TextBookForm.h"
#endif
#ifndef _TEXTBOOK_H
#include "../TextBook.h"
#endif
#ifndef DATABASE_FILE
#define DATABASE_FILE "database.sqlite"
#endif
#include "../sqlite3.h"
#include "../Glob_Defs.h"
#include "../RJM_SQLite_Resultset.h"
#include <iostream>
using namespace std;

TextBookForm::TextBookForm()
{
    this->textBookPtr = new TextBook;
    FieldPosition=0;
    InputPtr=&input;
    TextBookCoord[0][0]=25;
    TextBookCoord[0][1]=9;
    TextBookCoord[0][2]=21;

    TextBookCoord[1][0]=25;
    TextBookCoord[1][1]=12;
    TextBookCoord[1][2]=7;

    TextBookCoord[2][0]=25;
    TextBookCoord[2][1]=15;
    TextBookCoord[2][2]=8;

    TextBookCoord[3][0]=25;
    TextBookCoord[3][1]=18;
    TextBookCoord[3][2]=6;

    TextBookCoord[4][0]=25;
    TextBookCoord[4][1]=21;
    TextBookCoord[4][2]=8;

    TextBookCoord[5][0]=25;
    TextBookCoord[5][1]=24;
    TextBookCoord[5][2]=11;

    TextBookCoord[6][0]=25;
    TextBookCoord[6][1]=27;
    TextBookCoord[6][2]=16;
}

TextBookForm::~TextBookForm()
{

}

void TextBookForm::browseForm()
{
	bool read=false;
	int KeyType;

	consoleObj.xyCoord(TextBookCoord[0][0]+18,TextBookCoord[0][1]);
	cout<<this->textBookPtr->getReferenceNumberPrefix();
	consoleObj.xyCoord(TextBookCoord[FieldPosition][0]+TextBookCoord[FieldPosition][2]+AllInput[FieldPosition].length(),TextBookCoord[FieldPosition][1]);
	while(!read)
	{
	    switch(FieldPosition)
	    {
            case 0:
                *InputPtr = this->textBookPtr->getReferenceNumber();
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,NOSPACING,InputPtr,3,TextBookCoord,FieldPosition,false);
                this->textBookPtr->setReferenceNumber(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 1:
                *InputPtr = this->textBookPtr->getTitle();
                KeyType=FormInputBuilderObj.FormInput(ALPHANUMERIC,SPACING,InputPtr,45,TextBookCoord,FieldPosition,false);
                this->textBookPtr->setTitle(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 2:
                *InputPtr = this->textBookPtr->getAuthor();
                KeyType=FormInputBuilderObj.FormInput(ALPHABETICAL,SPACING,InputPtr,30,TextBookCoord,FieldPosition,false);
                this->textBookPtr->setAuthor(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 3:
                *InputPtr = this->textBookPtr->getISBN();
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,NOSPACING,InputPtr,15,TextBookCoord,FieldPosition,false);
                this->textBookPtr->setISBN(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;

            case 4:
                *InputPtr = this->textBookPtr->getCourse();
                KeyType=FormInputBuilderObj.FormInput(ALPHANUMERIC,SPACING,InputPtr,40,TextBookCoord,FieldPosition,false);
                this->textBookPtr->setCourse(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 5:
                *InputPtr = this->textBookPtr->getPublisher();
                KeyType=FormInputBuilderObj.FormInput(ALPHANUMERIC,SPACING,InputPtr,30,TextBookCoord,FieldPosition,false);
                this->textBookPtr->setPublisher(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 6:
                *InputPtr = this->textBookPtr->getDatePublished();
                KeyType=FormInputBuilderObj.FormInput(DATE,NOSPACING,InputPtr,8,TextBookCoord,FieldPosition,false);
                this->textBookPtr->setDatePublished(*InputPtr);
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
        if(FieldPosition>6)
        {
            FieldPosition=6;
            read=true;
        }
        consoleObj.xyCoord(TextBookCoord[FieldPosition][0]+TextBookCoord[FieldPosition][2]+AllInput[FieldPosition].length(),TextBookCoord[FieldPosition][1]);
    }
	consoleObj.setCursor(false,3);
}

void TextBookForm::show()
{

    consoleObj.xyCoord(TextBookCoord[0][0],TextBookCoord[0][1]);
	cout<<"Reference Number: ";
	consoleObj.xyCoord(TextBookCoord[1][0],TextBookCoord[1][1]);
	cout<<"Title: ";
	consoleObj.xyCoord(TextBookCoord[2][0],TextBookCoord[2][1]);
	cout<<"Author: ";
    consoleObj.xyCoord(TextBookCoord[3][0],TextBookCoord[3][1]);
	cout<<"ISBN: ";
	consoleObj.xyCoord(TextBookCoord[4][0],TextBookCoord[4][1]);
	cout<<"Course: ";
	consoleObj.xyCoord(TextBookCoord[5][0],TextBookCoord[5][1]);
	cout<<"Publisher: ";
    consoleObj.xyCoord(13,27);
	cout<<"<mm/dd/yy>";
	consoleObj.xyCoord(TextBookCoord[6][0],TextBookCoord[6][1]);
	cout<<"Date Published: ";
}

void TextBookForm::browseEditForm(string referenceNumber)
{
	this->setReferenceNumber(referenceNumber);
	bool read=false;
	int KeyType;
	/*consoleObj.xyCoord(TextBookCoord[0][0],TextBookCoord[0][1]-3);
	cout << "Only fill in the fields you wish to update.";*/
	consoleObj.xyCoord(TextBookCoord[0][0]+18,TextBookCoord[0][1]);
	cout<<referenceNumber;
	consoleObj.xyCoord(TextBookCoord[FieldPosition][0]+TextBookCoord[FieldPosition][2]+AllInput[FieldPosition].length(),TextBookCoord[FieldPosition][1]);
	while(!read)
	{
	    switch(FieldPosition)
	    {
            case 0:
                *InputPtr = this->textBookPtr->getReferenceNumber();
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,NOSPACING,InputPtr,0,TextBookCoord,FieldPosition,false);
                this->textBookPtr->setReferenceNumber(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 1:
                *InputPtr = this->textBookPtr->getTitle();
                KeyType=FormInputBuilderObj.FormInput(ALPHANUMERIC,SPACING,InputPtr,15,TextBookCoord,FieldPosition,false);
                this->textBookPtr->setTitle(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 2:
                *InputPtr = this->textBookPtr->getAuthor();
                KeyType=FormInputBuilderObj.FormInput(ALPHABETICAL,SPACING,InputPtr,20,TextBookCoord,FieldPosition,false);
                this->textBookPtr->setAuthor(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 3:
                *InputPtr = this->textBookPtr->getISBN();
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,NOSPACING,InputPtr,10,TextBookCoord,FieldPosition,false);
                this->textBookPtr->setISBN(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;

            case 4:
                *InputPtr = this->textBookPtr->getCourse();
                KeyType=FormInputBuilderObj.FormInput(ALPHANUMERIC,SPACING,InputPtr,15,TextBookCoord,FieldPosition,false);
                this->textBookPtr->setCourse(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 5:
                *InputPtr = this->textBookPtr->getPublisher();
                KeyType=FormInputBuilderObj.FormInput(ALPHANUMERIC,SPACING,InputPtr,15,TextBookCoord,FieldPosition,false);
                this->textBookPtr->setPublisher(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 6:
                *InputPtr = this->textBookPtr->getDatePublished();
                KeyType=FormInputBuilderObj.FormInput(DATE,NOSPACING,InputPtr,8,TextBookCoord,FieldPosition,false);
                this->textBookPtr->setDatePublished(*InputPtr);
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
        if(FieldPosition>6)
        {
            FieldPosition=6;
            read=true;
        }
        consoleObj.xyCoord(TextBookCoord[FieldPosition][0]+TextBookCoord[FieldPosition][2]+AllInput[FieldPosition].length(),TextBookCoord[FieldPosition][1]);
    }
	consoleObj.setCursor(false,3);
}

void TextBookForm::save()
{
    this->textBookPtr->insertReferenceNumberPrefix(this->textBookPtr->getReferenceNumber());
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
	l_query << "SELECT * FROM textbook WHERE referencenumber='" << this->textBookPtr->getReferenceNumber() << "';";
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
		this->setError("A Text Book with the reference number already exists.");
	}else{
		l_query.str("");
		l_query << "insert into textbook (referencenumber, title, author, isbn, course, publisher, datepublished)";
		l_query << " values ('"<<this->textBookPtr->getReferenceNumber()<<"','"<<this->textBookPtr->getTitle()<<"','"<<this->textBookPtr->getAuthor()<<"','"<< this->textBookPtr->getISBN()<<"','"<<this->textBookPtr->getCourse()<<"','"<<this->textBookPtr->getPublisher()<<"','"<<this->textBookPtr->getDatePublished()<<"')";
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
			l_query << "select * FROM textbook WHERE referencenumber='"<<this->textBookPtr->getReferenceNumber()<<"'";
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
			DB_DT_VARCHAR isbn;
			DB_DT_VARCHAR course;
			DB_DT_VARCHAR publisher;
			DB_DT_VARCHAR datepublished;

			pRS->GetColValueVARCHAR(0,0,&refNo);
			pRS->GetColValueVARCHAR(0,1,&title);
			pRS->GetColValueVARCHAR(0,2,&author);
			pRS->GetColValueVARCHAR(0,3,&isbn);
			pRS->GetColValueVARCHAR(0,4,&course);
			pRS->GetColValueVARCHAR(0,5,&publisher);
			pRS->GetColValueVARCHAR(0,6,&datepublished);
			SAFE_DELETE(pRS);
			TextBook * textBookObj = new TextBook(refNo,title,author,isbn,course,publisher,datepublished);
			this->setModel(textBookObj);
			this->setState(STATE_SUCCESS);
			sqlite3_close(l_sql_db);
		};
	}
}

void TextBookForm::editSave()
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
		if(this->textBookPtr->getTitle().length()<1&&this->textBookPtr->getAuthor().length()<1&&this->textBookPtr->getISBN().length()<1&&this->textBookPtr->getCourse().length()<1&&this->textBookPtr->getPublisher().length()<1&&this->textBookPtr->getDatePublished().length()<1)
		{
			this->setState(STATE_FAILURE);
			this->setError("You must fill in atleast one field to update.");
		}else{
			l_query << "UPDATE textbook SET referencenumber='"<<this->getReferenceNumber()<<"'";
			if(this->textBookPtr->getTitle().length()>0)
			{
				l_query << ", title='"<<this->textBookPtr->getTitle()<<"'";
			}
			if(this->textBookPtr->getAuthor().length()>0)
			{
				l_query << ", author='"<<this->textBookPtr->getAuthor()<<"'";
			}
			if(this->textBookPtr->getISBN().length()>0)
			{
				l_query << ", isbn='"<<this->textBookPtr->getISBN()<<"'";
			}
			if(this->textBookPtr->getCourse().length()>0)
			{
				l_query << ", course='"<<this->textBookPtr->getCourse()<<"'";
			}
			if(this->textBookPtr->getPublisher().length()>0)
			{
				l_query << ", publisher='"<<this->textBookPtr->getPublisher()<<"'";
			}
			if(this->textBookPtr->getDatePublished().length()>0)
			{
				l_query << ", datepublished='"<<this->textBookPtr->getDatePublished()<<"'";
			}
			l_query << "WHERE referencenumber='" << this->getReferenceNumber() << "';";
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
				l_query << "select * FROM textbook WHERE referencenumber='"<<this->getReferenceNumber()<<"'";
				pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);
				if (!pRS->Valid()) {\
					SAFE_DELETE(pRS);
					sqlite3_close(l_sql_db);
				}else{
					DB_DT_VARCHAR refNo;
					DB_DT_VARCHAR title;
					DB_DT_VARCHAR author;
					DB_DT_VARCHAR isbn;
					DB_DT_VARCHAR course;
					DB_DT_VARCHAR publisher;
					DB_DT_VARCHAR datepublished;

					pRS->GetColValueVARCHAR(0,0,&refNo);
					pRS->GetColValueVARCHAR(0,1,&title);
					pRS->GetColValueVARCHAR(0,2,&author);
					pRS->GetColValueVARCHAR(0,3,&isbn);
					pRS->GetColValueVARCHAR(0,4,&course);
					pRS->GetColValueVARCHAR(0,5,&publisher);
					pRS->GetColValueVARCHAR(0,6,&datepublished);
					SAFE_DELETE(pRS);
					TextBook * textBookObj = new TextBook(refNo,title,author,isbn,course,publisher,datepublished);
					this->setModel(textBookObj);
					sqlite3_close(l_sql_db);
				}
			}
		}
	}
}
bool TextBookForm::validate()
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
			if(pos==6)
				consoleObj.xyCoord(TextBookCoord[pos][0]-23,TextBookCoord[pos][1]); 
			else 
				consoleObj.xyCoord(TextBookCoord[pos][0]-15,TextBookCoord[pos][1]); 
			consoleObj.setColour(12);
			cout<<"<Required>";
			consoleObj.setColour(15);
			incomplete=true;
		}
	}
	return incomplete;
}