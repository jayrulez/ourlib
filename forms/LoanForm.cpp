#ifndef LOANFORM_H
#include "LoanForm.h"
#endif

#include <string>
#include <iostream>
using namespace std;

LoanForm::LoanForm()
{
    FieldPosition=0;
    InputPtr=&input;
    LoanCoord[0][0]=25;
    LoanCoord[0][1]=13;
    LoanCoord[0][2]=18;

    LoanCoord[1][0]=25;
    LoanCoord[1][1]=16;
    LoanCoord[1][2]=11;

    LoanCoord[2][0]=25;
    LoanCoord[2][1]=19;
    LoanCoord[2][2]=6;

    LoanCoord[3][0]=25;
    LoanCoord[3][1]=22;
    LoanCoord[3][2]=11;
}
LoanForm::~LoanForm()
{
}

void LoanForm::browseForm()
{
    char* tempId;
	bool read=false;
	int KeyType;

	consoleObj.xyCoord(LoanCoord[FieldPosition][0]+LoanCoord[FieldPosition][2]+AllInput[FieldPosition].length(),LoanCoord[FieldPosition][1]);

	while(!read)
	{

	    switch(FieldPosition)
	    {
            case 0:
                *InputPtr =  ReferenceNumber;
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,NOSPACING,InputPtr,6,LoanCoord,FieldPosition,false);
                ReferenceNumber = *InputPtr;
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 1:
                itoa(IdNumber,tempId,10);
                *InputPtr=tempId;
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,NOSPACING,InputPtr,7,LoanCoord,FieldPosition,false);
                IdNumber = atoi(InputPtr->c_str());
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 2:
                *InputPtr = LoanDate;
                KeyType=FormInputBuilderObj.FormInput(DATE,SPACING,InputPtr,8,LoanCoord,FieldPosition,false);
                LoanDate = *InputPtr;
                AllInput[FieldPosition] = *InputPtr;
                break;

            case 3:
                *InputPtr = LoanType;
                KeyType=FormInputBuilderObj.FormInput(ALPHABETICAL,SPACING,InputPtr,3,LoanCoord,FieldPosition,false);
                LoanType = *InputPtr;
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
        if(FieldPosition>3)
        {
            FieldPosition = 3;
            read=true;
        }
        consoleObj.xyCoord(LoanCoord[FieldPosition][0]+
        LoanCoord[FieldPosition][2]+AllInput[FieldPosition].length(),
        LoanCoord[FieldPosition][1]);
    }
	consoleObj.setCursor(false,3);
}

void LoanForm::show()
{
    consoleObj.xyCoord(LoanCoord[0][0],LoanCoord[0][1]);
	cout<<"Reference Number: ";
	consoleObj.xyCoord(LoanCoord[1][0],LoanCoord[1][1]);
	cout<<"Id Number: ";
	consoleObj.xyCoord(LoanCoord[2][0]-13,LoanCoord[2][1]);
	cout<<"<dd/mm/yy>";
	consoleObj.xyCoord(LoanCoord[2][0],LoanCoord[2][1]);
	cout<<"Date: ";
    consoleObj.xyCoord(LoanCoord[3][0]-11,LoanCoord[3][1]);
    cout<<"<IN/OUT>";
    consoleObj.xyCoord(LoanCoord[3][0],LoanCoord[3][1]);
    cout<<"Loan Type: ";

}
void LoanForm::save()
{
}
