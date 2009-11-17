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
    ResearchPaperCoord[0][0]=25;
    ResearchPaperCoord[0][1]=12;
    ResearchPaperCoord[0][2]=18;
    ResearchPaperCoord[1][0]=25;
    ResearchPaperCoord[1][1]=15;
    ResearchPaperCoord[1][2]=8;
    ResearchPaperCoord[2][0]=25;
    ResearchPaperCoord[2][1]=18;
    ResearchPaperCoord[2][2]=16;
    ResearchPaperCoord[3][0]=25;
    ResearchPaperCoord[3][1]=21;
    ResearchPaperCoord[3][2]=12;
    ResearchPaperCoord[4][0]=25;
    ResearchPaperCoord[4][1]=24;
    ResearchPaperCoord[4][2]=9;

}

ResearchPaperForm::~ResearchPaperForm()
{

}
void ResearchPaperForm::BrowseResearchPaperForm()
{
    consoleObj.setCursor(true,3);
	static string input;
	string *InputPtr;
	InputPtr=&input;
	int FieldPosition=0;
	bool read=false;
	int KeyType;
	consoleObj.xyCoord(ResearchPaperCoord[FieldPosition][0]+ResearchPaperCoord[FieldPosition][2]+InputPtr->length(),ResearchPaperCoord[FieldPosition][1]);
	while(!read)
	{
	    switch(FieldPosition)
	    {
            case 0:
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,NOSPACING,InputPtr,10);
                break;
            case 1:
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,SPACING,InputPtr,10);
                break;
            case 2:
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,NOSPACING,InputPtr,10);
                break;

            case 3:
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,SPACING,InputPtr,10);
                break;
            case 4:
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,SPACING,InputPtr,10);
                break;
	    }
        switch(KeyType)
        {
            case VK_UP:
                if(FieldPosition<0)
                {
                    FieldPosition=0;
                    break;
                }
                FieldPosition-=1;
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
            read=true;
            break;
        }
        consoleObj.xyCoord(ResearchPaperCoord[FieldPosition][0]+ResearchPaperCoord[FieldPosition][2]+InputPtr->length(),ResearchPaperCoord[FieldPosition][1]);
    }
	consoleObj.setCursor(false,3);
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
	consoleObj.xyCoord(ResearchPaperCoord[0][0],ResearchPaperCoord[0][1]);
	cout<<"Reference Number: ";
	consoleObj.xyCoord(ResearchPaperCoord[1][0],ResearchPaperCoord[1][1]);
	cout<<"Author: ";
    consoleObj.xyCoord(ResearchPaperCoord[2][0],ResearchPaperCoord[2][1]);
	cout<<"Research Topic: ";
	consoleObj.xyCoord(ResearchPaperCoord[3][0],ResearchPaperCoord[3][1]);
	cout<<"Supervisor: ";
	consoleObj.xyCoord(ResearchPaperCoord[4][0],ResearchPaperCoord[4][1]);
	cout<<"Sponsor: ";
}
