#ifndef LOANRETURNFORM_H
#include "LoanReturnForm.h"
#endif

#include <string>
#include <iostream>
using namespace std;

LoanReturnForm::LoanReturnForm()
{
}
LoanReturnForm::~LoanReturnForm()
{
}
LoanReturnForm::LoanReturnForm(bool t)
{
    this->FormType=t;
    FieldPosition=0;
    InputPtr=&input;
    LoanReturnCoord[0][0]=25;
    LoanReturnCoord[0][1]=13;
    LoanReturnCoord[0][2]=18;

    LoanReturnCoord[1][0]=25;
    LoanReturnCoord[1][1]=16;
    LoanReturnCoord[1][2]=11;

    LoanReturnCoord[2][0]=25;
    LoanReturnCoord[2][1]=19;
    LoanReturnCoord[2][2]=6;

    LoanReturnCoord[3][0]=25;
    LoanReturnCoord[3][1]=22;
    LoanReturnCoord[3][2]=11;
}

void LoanReturnForm::setLoanForm(bool t)
{
    this->FormType=t;
}
void LoanReturnForm::browseForm()
{
    char* tempId;
	bool read=false;
	int KeyType;
	consoleObj.xyCoord(LoanReturnCoord[FieldPosition][0]+LoanReturnCoord[FieldPosition][2]+AllInput[FieldPosition].length(),LoanReturnCoord[FieldPosition][1]);

	while(!read)
	{
	    //consoleObj.xyCoord(60,3);
	    //cout<<FieldPosition;

	    switch(FieldPosition)
	    {
            case 0:
                *InputPtr =  ReferenceNumber;
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,NOSPACING,InputPtr,10,LoanReturnCoord,FieldPosition,false);
                ReferenceNumber = *InputPtr;
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 1:
                itoa(IdNumber,tempId,10);
                *InputPtr=tempId;
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,NOSPACING,InputPtr,7,LoanReturnCoord,FieldPosition,false);
                IdNumber = atoi(InputPtr->c_str());
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 2:
                *InputPtr = LoanReturnDate;
                KeyType=FormInputBuilderObj.FormInput(DATE,SPACING,InputPtr,10,LoanReturnCoord,FieldPosition,false);
                LoanReturnDate = *InputPtr;
                AllInput[FieldPosition] = *InputPtr;
                break;
            if(FormType)
            {
                case 3:
                    *InputPtr = LoanType;
                    KeyType=FormInputBuilderObj.FormInput(ALPHABETICAL,SPACING,InputPtr,3,LoanReturnCoord,FieldPosition,false);
                    LoanType = *InputPtr;
                    AllInput[FieldPosition] = *InputPtr;
                    break;
            }
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
        if(FormType)
        {
            if(FieldPosition>3)
            {
                FieldPosition=3;
                read=true;
            }
        }
        else if(!FormType)
        {
            if(FieldPosition>2)
            {
                FieldPosition=2;
                read=true;
            }
        }
        consoleObj.xyCoord(LoanReturnCoord[FieldPosition][0]+
        LoanReturnCoord[FieldPosition][2]+AllInput[FieldPosition].length(),
        LoanReturnCoord[FieldPosition][1]);
    }
	consoleObj.setCursor(false,3);
}

void LoanReturnForm::show()
{
    consoleObj.xyCoord(LoanReturnCoord[0][0],LoanReturnCoord[0][1]);
	cout<<"Reference Number: ";
	consoleObj.xyCoord(LoanReturnCoord[1][0],LoanReturnCoord[1][1]);
	cout<<"Id Number: ";
	consoleObj.xyCoord(LoanReturnCoord[2][0],LoanReturnCoord[2][1]);
	cout<<"Date: ";
	if(FormType)
	{
        consoleObj.xyCoord(LoanReturnCoord[3][0],LoanReturnCoord[3][1]);
        cout<<"Loan Type: ";
	}
}
void LoanReturnForm::save()
{
}
