#ifndef _RESEARCHPAPER_H
#include "ResearchPaper.h"
#endif

#include <iostream>
#include <string>
using namespace std;
/*
*
*/
ResearchPaper::ResearchPaper()
{
        this->dataFileName = "researchpapers.bin";
        this->setReferenceNumberPrefix("RP-");
}

/*
*
*/
ResearchPaper::~ResearchPaper()
{
}

ResearchPaper::ResearchPaper(string referenceNumber, string title, string author, string researchTopic, string supervisor, string sponsor)
{
    this->referenceNumber = referenceNumber;
    this->title = title;
    this->author = author;
    this->researchTopic = researchTopic;
    this->supervisor = supervisor;
    this->sponsor = sponsor;
}

void ResearchPaper::setResearchTopic(string researchTopic)
{
    this->researchTopic = researchTopic;
}

void ResearchPaper::setSupervisor(string supervisor)
{
    this->supervisor = supervisor;
}

void ResearchPaper::setSponsor(string sponsor)
{
    this->sponsor = sponsor;
}

string ResearchPaper::getResearchTopic() const
{
	return this->researchTopic;
}

string ResearchPaper::getSupervisor() const
{
	return this->supervisor;
}

string ResearchPaper::getSponsor() const
{
	return this->sponsor;
}
void ResearchPaper::showReferenceMaterial(int xCoord,int yCoord)
{
    frameObj.setFrame(xCoord,20,yCoord,8,false);
    frameObj.sFraming();

    consoleObj.xyCoord(xCoord+2,yCoord+2);
    cout<<referenceNumber;
    consoleObj.xyCoord(xCoord+2,yCoord+4);
    cout<<author;
    consoleObj.xyCoord(xCoord+2,yCoord+6);
    cout<<title;

    consoleObj.xyCoord(xCoord+2,yCoord+8);
    cout<<researchTopic;
    consoleObj.xyCoord(xCoord+2,yCoord+10);
    cout<<supervisor;
    consoleObj.xyCoord(xCoord+2,yCoord+12);
    cout<<sponsor;
}
