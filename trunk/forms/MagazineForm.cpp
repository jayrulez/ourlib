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
    MagazineCoord[0][0]=25;
    MagazineCoord[0][1]=11;
    MagazineCoord[0][2]=18;
    MagazineCoord[1][0]=25;
    MagazineCoord[1][1]=14;
    MagazineCoord[1][2]=8;
    MagazineCoord[2][0]=25;
    MagazineCoord[2][1]=17;
    MagazineCoord[2][2]=8;
    MagazineCoord[3][0]=25;
    MagazineCoord[3][1]=20;
    MagazineCoord[3][2]=13;
    MagazineCoord[4][0]=25;
    MagazineCoord[4][1]=23;
    MagazineCoord[4][2]=12;
}

MagazineForm::~MagazineForm()
{

}
void MagazineForm::BrowseMagazineForm(int field)
{
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
