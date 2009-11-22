#ifndef _MEMBER_H
#include "Member.h"
#endif
#include <iostream>
#include <string>

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
Member::Member(int id,string fname,string lname,string address,string contactNumber)
{
	this->id = id;
	this->firstName = fname;
	this->lastName = lname;
	this->address = contactNumber;
}
void Member::setId(int)
{
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
int Member::getId() const
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
    frameObj.setFrame(xCoord,xCoord+45,yCoord,yCoord+12,false);
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
