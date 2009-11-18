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
