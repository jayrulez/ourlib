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
}
/*
*
*/
Magazine::~Magazine()
{
}
Magazine::Magazine(string referenceNumber, string author, string volume,string issueTopic)
{
	this->referenceNumber = referenceNumber;
	this->author = author;
	this->volume = volume;
	this->issueTopic = issueTopic;
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
void Magazine::showReferenceMaterial(int xCoord,int yCoord)
{
}
