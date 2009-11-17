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
void MagazineForm::BrowseMagazineForm()
{
	consoleObj.setCursor(true,3);
	static string input;
	string *InputPtr;
	InputPtr=&input;
	int FieldPosition=0;
	bool read=false;
	int KeyType;
	consoleObj.xyCoord(MagazineCoord[FieldPosition][0]+MagazineCoord[FieldPosition][2]+InputPtr->length(),MagazineCoord[FieldPosition][1]);
	while(!read)
	{
	    switch(FieldPosition)
	    {
            case 0:
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,InputPtr,10);
                break;
            case 1:
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,InputPtr,10);
                break;
            case 2:
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,InputPtr,10);
                break;

            case 3:
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,InputPtr,10);
                break;
            case 4:
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,InputPtr,10);
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
        consoleObj.xyCoord(MagazineCoord[FieldPosition][0]+MagazineCoord[FieldPosition][2]+InputPtr->length(),MagazineCoord[FieldPosition][1]);
    }
	consoleObj.setCursor(false,3);
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
	consoleObj.xyCoord(MagazineCoord[0][0],MagazineCoord[0][1]);
	cout<<"Reference Number: ";
	consoleObj.xyCoord(MagazineCoord[1][0],MagazineCoord[1][1]);
	cout<<"Author: ";
	consoleObj.xyCoord(MagazineCoord[2][0],MagazineCoord[2][1]);
	cout<<"Volume: ";
	consoleObj.xyCoord(MagazineCoord[3][0],MagazineCoord[3][1]);
	cout<<"Issue Date: ";
	consoleObj.xyCoord(MagazineCoord[4][0],MagazineCoord[4][1]);
	cout<<"Issue Topic: ";
}
