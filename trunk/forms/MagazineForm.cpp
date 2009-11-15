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
    xyVolume[0]=25;
    xyVolume[1]=15;
    xyVolume[2]=8;
    xyIssueTopic[0]=25;
    xyIssueTopic[1]=18;
    xyIssueTopic[2]=13;
    xyIssueDate[0]=25;
    xyIssueDate[1]=21;
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
	consoleObj.xyCoord(xyVolume[0],xyVolume[1]);
	cout<<"Volume: ";
	consoleObj.xyCoord(xyIssueDate[0],xyIssueDate[1]);
	cout<<"Issue Date: ";
	consoleObj.xyCoord(xyIssueTopic[0],xyIssueTopic[1]);
	cout<<"Issue Topic: ";
}
