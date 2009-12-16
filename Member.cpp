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
#ifndef _MEMBER_H
#include "Member.h"
#endif
#include <iostream>
#include <string>
#ifndef DATABASE_FILE
#define DATABASE_FILE "database.sqlite"
#endif
#include "./sqlite3.h"
#include "./Glob_Defs.h"
#include "./RJM_SQLite_Resultset.h"
using namespace std;
/*
*
*/
Member::Member()
{
}

/*
*
*/
Member::~Member()
{
}
Member::Member(string id,string fname,string lname,string address,string contactNumber)
{
	this->id = id;
	this->firstName = fname;
	this->lastName = lname;
	this->address = address;
	this->contactNumber = contactNumber;
}
void Member::setId(string id)
{
	this->id = id;
}
void Member::setFirstName(string fname)
{
	this->firstName = fname;
}
void Member::setLastName(string lname)
{
	this->lastName = lname;
}
void Member::setAddress(string address)
{
	this->address = address;
}
void Member::setContactNumber(string contactNumber)
{
	this->contactNumber = contactNumber;
}
string Member::getId() const
{
	return this->id;
}
string Member::getFirstName() const
{
	return this->firstName;
}
string Member::getLastName() const
{
	return this->lastName;
}

int Member::getNewId()
{
	string l_filename = DATABASE_FILE;
	ostringstream l_query;
	sqlite3* l_sql_db = NULL;
	
	int rc = sqlite3_open(l_filename.c_str(), &l_sql_db);
	if( rc ){
		sqlite3_close(l_sql_db);
	};
	RJM_SQLite_Resultset *pRS = NULL;
	l_query.str("");
	l_query << "SELECT * FROM member;";
	pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);	
	if (!pRS->Valid()) {
		SAFE_DELETE(pRS);
		sqlite3_close(l_sql_db);
	};
	rc = pRS->GetRowCount();
	SAFE_DELETE(pRS);
	return rc+1;
}

string Member::getAddress() const
{
	return this->address;
}
string Member::getContactNumber() const
{
	return this->contactNumber;
}
void Member::showMember(int xCoord,int yCoord)
{
    frameObj.setFrame(xCoord,xCoord+55,yCoord,yCoord+12,false);
    frameObj.sFraming();

    consoleObj.xyCoord(xCoord+2,yCoord+2);
    cout<<"Id Number: "<<this->id;
    consoleObj.xyCoord(xCoord+2,yCoord+4);
    cout<<"First Name: "<<this->firstName;
    consoleObj.xyCoord(xCoord+2,yCoord+6);
    cout<<"Last Name: "<<this->lastName;

    consoleObj.xyCoord(xCoord+2,yCoord+8);
    cout<<"Address: "<<this->address;
    consoleObj.xyCoord(xCoord+2,yCoord+10);
    cout<<"Contact Number: "<<this->contactNumber;
}
