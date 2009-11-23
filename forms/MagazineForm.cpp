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
#include <fstream>
#ifndef _VALIDATOR_H
#include "./Validator.h"
#endif

using namespace std;

MagazineForm::MagazineForm()
{
    this->magazinePtr = new Magazine;
    FieldPosition=0;
    InputPtr=&input;
    MagazineCoord[0][0]=25;
    MagazineCoord[0][1]=11;
    MagazineCoord[0][2]=21;

    MagazineCoord[1][0]=25;
    MagazineCoord[1][1]=14;
    MagazineCoord[1][2]=7;

    MagazineCoord[2][0]=25;
    MagazineCoord[2][1]=17;
    MagazineCoord[2][2]=8;

    MagazineCoord[3][0]=25;
    MagazineCoord[3][1]=20;
    MagazineCoord[3][2]=8;

    MagazineCoord[4][0]=25;
    MagazineCoord[4][1]=23;
    MagazineCoord[4][2]=12;

    MagazineCoord[5][0]=25;
    MagazineCoord[5][1]=26;
    MagazineCoord[5][2]=13;
}

MagazineForm::~MagazineForm()
{

}
void MagazineForm::browseForm()
{
	// 5 pointers needed for 5 inputs
	bool read=false;
	int KeyType;
	consoleObj.xyCoord(MagazineCoord[0][0]+18,MagazineCoord[0][1]);
	cout<<this->magazinePtr->getReferenceNumberPrefix();
	consoleObj.xyCoord(MagazineCoord[FieldPosition][0]+MagazineCoord[FieldPosition][2]+AllInput[FieldPosition].length(),MagazineCoord[FieldPosition][1]);
	while(!read)
	{
	    switch(FieldPosition)
	    {
            case 0:
                *InputPtr = this->magazinePtr->getReferenceNumber();
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,NOSPACING,InputPtr,3,MagazineCoord,FieldPosition,false);
                this->magazinePtr->setReferenceNumber(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 1:
                *InputPtr = this->magazinePtr->getTitle();
                KeyType=FormInputBuilderObj.FormInput(ALPHANUMERIC,SPACING,InputPtr,15,MagazineCoord,FieldPosition,false);
                this->magazinePtr->setTitle(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 2:
                *InputPtr = this->magazinePtr->getAuthor();
                KeyType=FormInputBuilderObj.FormInput(ALPHABETICAL,SPACING,InputPtr,15,MagazineCoord,FieldPosition,false);
                this->magazinePtr->setAuthor(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 3:
                *InputPtr = this->magazinePtr->getVolume();
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,NOSPACING,InputPtr,3,MagazineCoord,FieldPosition,false);
                this->magazinePtr->setVolume(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;

            case 4:
                *InputPtr = this->magazinePtr->getIssueDate();
                KeyType=FormInputBuilderObj.FormInput(DATE,NOSPACING,InputPtr,8,MagazineCoord,FieldPosition,false);
                this->magazinePtr->setIssueDate(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;

            case 5:
                *InputPtr = this->magazinePtr->getIssueTopic();
                KeyType=FormInputBuilderObj.FormInput(ALPHANUMERIC,SPACING,InputPtr,15,MagazineCoord,FieldPosition,false);
                this->magazinePtr->setIssueTopic(*InputPtr);
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
        if(FieldPosition>5)
        {
            FieldPosition=5;
            read=true;
        }
        //*InputPtr = "";
        consoleObj.xyCoord(60,3);
        cout<< FieldPosition;
        consoleObj.xyCoord(MagazineCoord[FieldPosition][0]+MagazineCoord[FieldPosition][2]+AllInput[FieldPosition].length(),MagazineCoord[FieldPosition][1]);
    }
	consoleObj.setCursor(false,3);
}

void MagazineForm::show()
{
	consoleObj.xyCoord(MagazineCoord[0][0],MagazineCoord[0][1]);
	cout<<"Reference Number: ";
	consoleObj.xyCoord(MagazineCoord[1][0],MagazineCoord[1][1]);
	cout<<"Title: ";
	consoleObj.xyCoord(MagazineCoord[2][0],MagazineCoord[2][1]);
	cout<<"Author: ";
	consoleObj.xyCoord(MagazineCoord[3][0],MagazineCoord[3][1]);
	cout<<"Volume: ";
    consoleObj.xyCoord(13,23);
	cout<<"<mm/dd/yy>";
	consoleObj.xyCoord(MagazineCoord[4][0],MagazineCoord[4][1]);
	cout<<"Issue Date: ";
	consoleObj.xyCoord(MagazineCoord[5][0],MagazineCoord[5][1]);
	cout<<"Issue Topic: ";
}

void MagazineForm::save()
{
    this->magazinePtr->insertReferenceNumberPrefix(this->magazinePtr->getReferenceNumber());

    int position = this->magazinePtr->getIdFromReferenceNumber(this->magazinePtr->getReferenceNumber());
    if(position>0) position -= 1;

    Validator * validator = new Validator();
    ReferenceMaterial *referenceObj = this->magazinePtr;
    validator->formValidate((int*)referenceObj);
    if (validator->hasError())
    {
        this->setState(STATE_ERROR);
        this->setError(validator->getError());
    }else{
        ofstream fileWriteObj (this->magazinePtr->getDataFileName(),ios::out | ios::binary);
        fileWriteObj.exceptions(ofstream::eofbit | ofstream::failbit | ofstream::badbit);
        fileWriteObj.seekp(position * sizeof(Magazine));
        try
        {
            fileWriteObj.write(reinterpret_cast < char * > (this->magazinePtr),sizeof(Magazine));
            this->setState(STATE_SUCCESS);
            this->setModel(this->magazinePtr);
        }catch(ofstream::failure e)
        {
            this->setState(STATE_FAILURE);
            this->setError(e.what());
        }
        cout << "here" <<endl;
        system("pause");
        fileWriteObj.close();
    }
}
