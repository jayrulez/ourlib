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
#ifndef _MEMBERFORM_H
#include "MemberForm.h"
#endif

#include <string>
#include <iostream>
#include <sstream>
#ifndef DATABASE_FILE
#define DATABASE_FILE "database.sqlite"
#endif
#include "../sqlite3.h"
#include "../Glob_Defs.h"
#include "../RJM_SQLite_Resultset.h"
using namespace std;

MemberForm::MemberForm()
{
    memberPtr = new Member;
    FieldPosition=0;
    InputPtr=&input;
    MemberCoord[0][0]=20;
    MemberCoord[0][1]=14;
    MemberCoord[0][2]=11;
    MemberCoord[1][0]=20;
    MemberCoord[1][1]=17;
    MemberCoord[1][2]=12;
    MemberCoord[2][0]=20;
    MemberCoord[2][1]=20;
    MemberCoord[2][2]=11;
    MemberCoord[3][0]=20;
    MemberCoord[3][1]=23;
    MemberCoord[3][2]=9;
    MemberCoord[4][0]=20;
    MemberCoord[4][1]=26;
    MemberCoord[4][2]=16;
}
MemberForm::~MemberForm()
{
}
void MemberForm::browseForm()
{
	bool read=false;
	int KeyType;
    string s;
    stringstream out;
	consoleObj.xyCoord(MemberCoord[FieldPosition][0]+MemberCoord[FieldPosition][2]+AllInput[FieldPosition].length(),MemberCoord[FieldPosition][1]);
	int newId = memberPtr->getNewId();
	cout<<newId;
	while(!read)
	{
	    switch(FieldPosition)
	    {
            case 0:
				char buffer[10];
                out << newId;
                s = itoa(newId,buffer,10);
                *InputPtr=s;
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,NOSPACING,InputPtr,0,MemberCoord,FieldPosition,false);
                this->memberPtr->setId(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 1:
                *InputPtr = this->memberPtr->getFirstName();
                KeyType=FormInputBuilderObj.FormInput(ALPHABETICAL,NOSPACING,InputPtr,10,MemberCoord,FieldPosition,false);
                this->memberPtr->setFirstName(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 2:
                *InputPtr = this->memberPtr->getLastName();
                KeyType=FormInputBuilderObj.FormInput(ALPHABETICAL,NOSPACING,InputPtr,10,MemberCoord,FieldPosition,false);
                this->memberPtr->setLastName(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 3:
                *InputPtr = this->memberPtr->getAddress();
                KeyType=FormInputBuilderObj.FormInput(ALPHANUMERIC,SPACING,InputPtr,10,MemberCoord,FieldPosition,false);
                this->memberPtr->setAddress(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 4:
                *InputPtr = this->memberPtr->getContactNumber();
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,NOSPACING,InputPtr,10,MemberCoord,FieldPosition,false);
                this->memberPtr->setContactNumber(*InputPtr);
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
        if(FieldPosition>4)
        {
            FieldPosition=4;
            read=true;
        }
        consoleObj.xyCoord(MemberCoord[FieldPosition][0]+MemberCoord[FieldPosition][2]+AllInput[FieldPosition].length(),MemberCoord[FieldPosition][1]);
    }
	consoleObj.setCursor(false,3);
}

void MemberForm::show()
{
    consoleObj.xyCoord(MemberCoord[0][0],MemberCoord[0][1]);
	cout<<"Id Number: ";
	consoleObj.xyCoord(MemberCoord[1][0],MemberCoord[1][1]);
	cout<<"First Name: ";
    consoleObj.xyCoord(MemberCoord[2][0],MemberCoord[2][1]);
	cout<<"Last Name: ";
	consoleObj.xyCoord(MemberCoord[3][0],MemberCoord[3][1]);
	cout<<"Address: ";
	consoleObj.xyCoord(MemberCoord[4][0],MemberCoord[4][1]);
	cout<<"Contact Number: ";
}
void MemberForm::save()
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

	int memberId = atoi(this->memberPtr->getId().c_str());

	l_query.str("");
	l_query << "insert into member (id,firstname, lastname, address, contactnumber)";
	l_query << " values ('"<<memberId<<"','"<<this->memberPtr->getFirstName()<<"','"<<this->memberPtr->getLastName()<<"','"<<this->memberPtr->getAddress()<<"','"<< this->memberPtr->getContactNumber()<<"')";
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
		l_query << "select * FROM member WHERE id='"<<this->memberPtr->getId()<<"'";
		pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);
		if (!pRS->Valid()) {
			//cout << "Invalid result set returned " << pRS->GetLastError() << endl;
			SAFE_DELETE(pRS);
			sqlite3_close(l_sql_db);
		};
		rc = pRS->GetRowCount();
		
		DB_DT_LONG id;
		DB_DT_VARCHAR fname;
		DB_DT_VARCHAR lname;
		DB_DT_VARCHAR address;
		DB_DT_VARCHAR number;
		pRS->GetColValueINTEGER(0,0,&id);
		pRS->GetColValueVARCHAR(0,1,&fname);
		pRS->GetColValueVARCHAR(0,2,&lname);
		pRS->GetColValueVARCHAR(0,3,&address);
		pRS->GetColValueVARCHAR(0,4,&number);
		sqlite3_close(l_sql_db);
		SAFE_DELETE(pRS);
			
		int x = (int)id;
		char buffer[10];
		string memId = itoa(x,buffer,10);
		Member* memberObj = new Member(memId,fname,lname,address,number);
		this->setMember(memberObj);
		this->setState(STATE_SUCCESS);
	};
}
