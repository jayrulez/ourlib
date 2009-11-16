#ifndef _MAGAZINEFORM_H
#include "MagazineForm.h"
#endif
#ifndef _MAGAZINE_H
#include "../Magazine.h"
#endif
#include <iostream>
#include <string>
using namespace std;

MagazineForm::MagazineForm()
{
    xyReferenceNumber[0]=25;
    xyReferenceNumber[1]=11;
    xyReferenceNumber[2]=18;
    xyAuthor[0]=25;
    xyAuthor[1]=14;
    xyAuthor[2]=8;
    xyVolume[0]=25;
    xyVolume[1]=17;
    xyVolume[2]=8;
    xyIssueTopic[0]=25;
    xyIssueTopic[1]=20;
    xyIssueTopic[2]=13;
    xyIssueDate[0]=25;
    xyIssueDate[1]=23;
    xyIssueDate[2]=12;
}

MagazineForm::~MagazineForm()
{

}

void MagazineForm::show(Magazine * magazineObj)
{
	string referenceNumber = magazineObj->getReferenceNumber();
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
	consoleObj.xyCoord(xyVolume[0],xyVolume[1]);
	cout<<"Volume: ";
	consoleObj.xyCoord(xyIssueDate[0],xyIssueDate[1]);
	cout<<"Issue Date: ";
	consoleObj.xyCoord(xyIssueTopic[0],xyIssueTopic[1]);
	cout<<"Issue Topic: ";
}
