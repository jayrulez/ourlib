#ifndef _MAGAZINE_H
#include "Magazine.h"
#endif
#include <iostream>
#include <string>

using namespace std;
/*
*
*/
Magazine::Magazine()
{
        this->dataFileName = "magazines.bin";
        this->setReferenceNumberPrefix("MG-");
}
/*
*
*/
Magazine::~Magazine()
{
}

Magazine::Magazine(string referenceNumber, string author,string title, string volume,string issueTopic, string issueDate)
{
	this->referenceNumber = referenceNumber;
	this->author = author;
	this->volume = volume;
	this->issueTopic = issueTopic;
	this->issueDate = issueDate;
}

void Magazine::setVolume(string volume)
{
	this->volume = volume;
}

void Magazine::setIssueTopic(string issueTopic)
{
	this->issueTopic = issueTopic;
}

void Magazine::setIssueDate(string issueDate)
{
	this->issueDate = issueDate;
}

string Magazine::getVolume() const
{
	return this->volume;
}

string Magazine::getIssueTopic() const
{
	return this->issueTopic;
}

string Magazine::getIssueDate() const
{
	return this->issueDate;
}

void Magazine::showReferenceMaterial(int xCoord,int yCoord)
{
    frameObj.setFrame(xCoord,xCoord+45,yCoord,yCoord+14,false);
    frameObj.sFraming();

    consoleObj.xyCoord(xCoord+2,yCoord+2);
    cout<<"Reference Number: "<<referenceNumber;
    consoleObj.xyCoord(xCoord+2,yCoord+4);
    cout<<"Author: "<<author;
    consoleObj.xyCoord(xCoord+2,yCoord+6);
    cout<<"Title: "<<title;
    consoleObj.xyCoord(xCoord+2,yCoord+8);
    cout<<"Volume: "<<volume;
    consoleObj.xyCoord(xCoord+2,yCoord+10);
    cout<<"Issue Topic: "<<issueTopic;
    consoleObj.xyCoord(xCoord+2,yCoord+12);
    cout<<"Issue Date: "<<issueDate;
}
