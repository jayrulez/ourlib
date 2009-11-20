#ifndef _MEMBERFORM_H
#include "MemberForm.h"
#endif

#include <string>
#include <iostream>
using namespace std;

MemberForm::MemberForm()
{
    memberPtr = new Member;
    MemberCoord[0][0]=20;
    MemberCoord[0][1]=14;
    MemberCoord[0][2]=11;
    MemberCoord[1][0]=20;
    MemberCoord[1][1]=17;
    MemberCoord[1][2]=12;
    MemberCoord[2][0]=20;
    MemberCoord[2][1]=20;
    MemberCoord[2][2]=11;
    MemberCoord[3][0]=20;
    MemberCoord[3][1]=23;
    MemberCoord[3][2]=9;
    MemberCoord[4][0]=20;
    MemberCoord[4][1]=26;
    MemberCoord[4][2]=16;
}
MemberForm::~MemberForm()
{
}
void MemberForm::BrowseMemberForm()
{
	static string input;
	string AllInput[5];
	string *InputPtr;
	char* tempId;
	int FieldPosition=0;
	bool read=false;
	int KeyType;
	InputPtr=&input;
	consoleObj.setCursor(true,3);
	consoleObj.xyCoord(MemberCoord[FieldPosition][0]+MemberCoord[FieldPosition][2]+AllInput[FieldPosition].length(),MemberCoord[FieldPosition][1]);
	while(!read)
	{
	    switch(FieldPosition)
	    {
            case 0:
                *InputPtr = itoa(this->memberPtr->getId(),tempId,10);
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,NOSPACING,InputPtr,10,false);
                this->memberPtr->setId(atoi(InputPtr->c_str()));
                *InputPtr=tempId;
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 1:
                *InputPtr = this->memberPtr->getFirstName();
                KeyType=FormInputBuilderObj.FormInput(ALPHABETICAL,NOSPACING,InputPtr,10,false);
                this->memberPtr->setFirstName(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 2:
                *InputPtr = this->memberPtr->getLastName();
                KeyType=FormInputBuilderObj.FormInput(ALPHABETICAL,NOSPACING,InputPtr,10,false);
                this->memberPtr->setLastName(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 3:
                *InputPtr = this->memberPtr->getAddress();
                KeyType=FormInputBuilderObj.FormInput(ALPHANUMERIC,SPACING,InputPtr,10,false);
                this->memberPtr->setAddress(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 4:
                *InputPtr = this->memberPtr->getContactNumber();
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,NOSPACING,InputPtr,10,false);
                this->memberPtr->setContactNumber(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
	    }
        switch(KeyType)
        {
            case VK_UP:
                if(FieldPosition<0)
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
            read=true;
            break;
        }
        consoleObj.xyCoord(MemberCoord[FieldPosition][0]+MemberCoord[FieldPosition][2]+AllInput[FieldPosition].length(),MemberCoord[FieldPosition][1]);
    }
	consoleObj.setCursor(false,3);
}

void MemberForm::show()
{
    consoleObj.xyCoord(MemberCoord[0][0],MemberCoord[0][1]);
	cout<<"Id Number: ";
	consoleObj.xyCoord(MemberCoord[1][0],MemberCoord[1][1]);
	cout<<"First Name: ";
    consoleObj.xyCoord(MemberCoord[2][0],MemberCoord[2][1]);
	cout<<"Last Name: ";
	consoleObj.xyCoord(MemberCoord[3][0],MemberCoord[3][1]);
	cout<<"Address: ";
	consoleObj.xyCoord(MemberCoord[4][0],MemberCoord[4][1]);
	cout<<"Contact Number: ";
}
