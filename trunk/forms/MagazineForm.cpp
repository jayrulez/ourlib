#ifndef _MAGAZINEFORM_H
#include "MagazineForm.h"
#endif
#ifndef _MAGAZINE_H
#include "../Magazine.h"
#endif
#include <iostream>
#include <string>
#include <windows.h>
#include "../gui/console/console.h"
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
void MagazineForm::BrowseMagazineForm(int field)
{
    int coord[5][3];
    coord[0]=xyReferenceNumber;
    HANDLE hIn;
	DWORD AmtRead;
	INPUT_RECORD InputRec;
	bool read=false;
	hIn = GetStdHandle(STD_INPUT_HANDLE);
	while(!read)
	{
		ReadConsoleInput(hIn,&InputRec,1,&AmtRead);
		switch(InputRec.EventType)
		{
			case KEY_EVENT:
				if(InputRec.Event.KeyEvent.bKeyDown)
				{
				    switch(InputRec.Event.KeyEvent.wVirtualKeyCode)
                    {
                        case VK_UP:
                        break;
                        case VK_RETURN:
                        break;
                        case VK_TAB:
                        break;
                        case VK_DOWN:
                        break;
                    }
				}
            break;
		}
	}
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
