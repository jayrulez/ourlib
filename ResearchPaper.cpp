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
    frameObj.setFrame(xCoord,xCoord+55,yCoord,yCoord+14,false);
    frameObj.sFraming();

    consoleObj.xyCoord(xCoord+2,yCoord+2);
    cout<<"Reference Number: "<<referenceNumber;
    consoleObj.xyCoord(xCoord+2,yCoord+4);
    cout<<"Author: "<<author;
    consoleObj.xyCoord(xCoord+2,yCoord+6);
    cout<<"Title: "<<title;

    consoleObj.xyCoord(xCoord+2,yCoord+8);
    cout<<"Research Topic: "<<researchTopic;
    consoleObj.xyCoord(xCoord+2,yCoord+10);
    cout<<"Supervisor: "<<supervisor;
    consoleObj.xyCoord(xCoord+2,yCoord+12);
    cout<<"Sponsor: "<<sponsor;
}
