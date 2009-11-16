#ifndef _RESEARCHPAPERFORM_H
#include "ResearchpaperForm.h"
#endif
#ifndef _RESEARCHPAPER_H
#include "../ResearchPaper.h"
#endif

#include <iostream>
using namespace std;

ResearchPaperForm::ResearchPaperForm()
{
    xyReferenceNumber[0]=25;
    xyReferenceNumber[1]=12;
    xyReferenceNumber[2]=18;
    xyAuthor[0]=25;
    xyAuthor[1]=15;
    xyAuthor[2]=8;
    xyResearchTopic[0]=25;
    xyResearchTopic[1]=18;
    xyResearchTopic[2]=6;
    xySupervisor[0]=25;
    xySupervisor[1]=21;
    xySupervisor[2]=8;
    xySponsor[0]=25;
    xySponsor[1]=24;
    xySponsor[2]=11;

}

ResearchPaperForm::~ResearchPaperForm()
{

}

void ResearchPaperForm::show(ResearchPaper * researchPaperObj)
{
	string referenceNumber = researchPaperObj->getReferenceNumber();
	if(referenceNumber.empty())
	{
		//NEW RECORD
	}else{
		//record from file
	}
	consoleObj.xyCoord(xyReferenceNumber[0],xyReferenceNumber[1]);
	cout<<"Reference Number: ";
	consoleObj.xyCoord(xyAuthor[0],xyAuthor[1]);
	cout<<"Author: ";
    consoleObj.xyCoord(xyResearchTopic[0],xyResearchTopic[1]);
	cout<<"Research Topic: ";
	consoleObj.xyCoord(xySupervisor[0],xySupervisor[1]);
	cout<<"Supervisor: ";
	consoleObj.xyCoord(xySponsor[0],xySponsor[1]);
	cout<<"Sponsor: ";
}
