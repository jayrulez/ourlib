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
    this->magazinePtr = new Magazine;
    FieldPosition=0;
    InputPtr=&input;
    MagazineCoord[0][0]=25;
    MagazineCoord[0][1]=11;
    MagazineCoord[0][2]=18;

    MagazineCoord[1][0]=25;
    MagazineCoord[1][1]=14;
    MagazineCoord[1][2]=7;

    MagazineCoord[2][0]=25;
    MagazineCoord[2][1]=17;
    MagazineCoord[2][2]=8;

    MagazineCoord[3][0]=25;
    MagazineCoord[3][1]=21;
    MagazineCoord[3][2]=8;

    MagazineCoord[4][0]=25;
    MagazineCoord[4][1]=23;
    MagazineCoord[4][2]=13;

    MagazineCoord[5][0]=25;
    MagazineCoord[5][1]=26;
    MagazineCoord[5][2]=12;
}

MagazineForm::~MagazineForm()
{

}
void MagazineForm::BrowseMagazineForm()
{
	// 5 pointers needed for 5 inputs
	bool read=false;
	int KeyType;
	consoleObj.xyCoord(MagazineCoord[FieldPosition][0]+MagazineCoord[FieldPosition][2]+AllInput[FieldPosition].length(),MagazineCoord[FieldPosition][1]);
	while(!read)
	{
	    switch(FieldPosition)
	    {
            case 0:
                *InputPtr = this->magazinePtr->getReferenceNumber();
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,NOSPACING,InputPtr,10,MagazineCoord,FieldPosition,false);
                this->magazinePtr->setReferenceNumber(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 1:
                *InputPtr = this->magazinePtr->getTitle();
                KeyType=FormInputBuilderObj.FormInput(ALPHANUMERIC,SPACING,InputPtr,10,MagazineCoord,FieldPosition,false);
                this->magazinePtr->setTitle(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 2:
                *InputPtr = this->magazinePtr->getAuthor();
                KeyType=FormInputBuilderObj.FormInput(ALPHABETICAL,SPACING,InputPtr,10,MagazineCoord,FieldPosition,false);
                this->magazinePtr->setAuthor(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 3:
                *InputPtr = this->magazinePtr->getTitle();
                KeyType=FormInputBuilderObj.FormInput(ALPHANUMERIC,SPACING,InputPtr,10,MagazineCoord,FieldPosition,false);
                this->magazinePtr->setTitle(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;

            case 4:
                *InputPtr = this->magazinePtr->getIssueTopic();
                KeyType=FormInputBuilderObj.FormInput(DATE,NOSPACING,InputPtr,10,MagazineCoord,FieldPosition,false);
                this->magazinePtr->setIssueTopic(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 5:
                *InputPtr = this->magazinePtr->getIssueDate();
                KeyType=FormInputBuilderObj.FormInput(ALPHANUMERIC,SPACING,InputPtr,10,MagazineCoord,FieldPosition,false);
                this->magazinePtr->setIssueDate(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
	    }
        switch(KeyType)
        {
            case VK_UP:
                if(FieldPosition<=0)
                {
                    FieldPosition=0;
                    break;
                }else{
                    FieldPosition-=1;
                }
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
            FieldPosition=4;
            read=true;
        }
        //*InputPtr = "";
        consoleObj.xyCoord(60,3);
        cout<< FieldPosition;
        consoleObj.xyCoord(MagazineCoord[FieldPosition][0]+MagazineCoord[FieldPosition][2]+AllInput[FieldPosition].length(),MagazineCoord[FieldPosition][1]);
    }
	consoleObj.setCursor(false,3);
}

void MagazineForm::showTest()
{
    cout << this->magazinePtr->getReferenceNumber() << endl;
    cout << this->magazinePtr->getIssueDate() << endl;
    cout << this->magazinePtr->getIssueTopic() << endl;
    fgetc(stdin);
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
	consoleObj.xyCoord(MagazineCoord[2][0],MagazineCoord[2][1]);
	cout<<"Title: ";
	consoleObj.xyCoord(MagazineCoord[2][0],MagazineCoord[2][1]);
	cout<<"Author: ";
	consoleObj.xyCoord(MagazineCoord[3][0],MagazineCoord[3][1]);
	cout<<"Volume: ";
    consoleObj.xyCoord(13,20);
	cout<<"<dd/mm/yy>";
	consoleObj.xyCoord(MagazineCoord[4][0],MagazineCoord[4][1]);
	cout<<"Issue Date: ";
	consoleObj.xyCoord(MagazineCoord[5][0],MagazineCoord[5][1]);
	cout<<"Issue Topic: ";
}
