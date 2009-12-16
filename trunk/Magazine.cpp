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
	this->title = title;
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
    frameObj.setFrame(xCoord,xCoord+55,yCoord,yCoord+14,false);
    frameObj.sFraming();

    consoleObj.xyCoord(xCoord+2,yCoord+2);
    cout<<"Reference Number: "<<this->getReferenceNumber();
    consoleObj.xyCoord(xCoord+2,yCoord+4);
    cout<<"Author: "<<this->getAuthor();
    consoleObj.xyCoord(xCoord+2,yCoord+6);
    cout<<"Title: "<<this->getTitle();
    consoleObj.xyCoord(xCoord+2,yCoord+8);
    cout<<"Volume: "<<this->getVolume();
	consoleObj.xyCoord(xCoord+2,yCoord+10);
    cout<<"Issue Date: "<<this->getIssueDate();
    consoleObj.xyCoord(xCoord+2,yCoord+12);
    cout<<"Issue Topic: "<<this->getIssueTopic();
}
