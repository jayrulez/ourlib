#ifndef LOANRETURNFORM_H
#include "LoanReturnForm.h"
#endif

#include <string>
#include <iostream.h>
using namespace std;

LoanForm::LoanReturnForm()
{
    FieldPosition=0;
    InputPtr=&input;
    LoanReturnCoord[0][0]=25;
    LoanReturnCoord[0][1]=20;
    LoanReturnCoord[0][2]=18;

    LoanReturnCoord[1][0]=25;
    LoanReturnCoord[1][1]=23;
    LoanReturnCoord[1][2]=11;

    LoanReturnCoord[2][0]=25;
    LoanReturnCoord[2][1]=26;
    LoanReturnCoord[2][2]=7;
}
LoanForm::~LoanReturnForm()
{
}
void LoanForm::BrowseLoanReturnForm()
{
	bool read=false;
	int KeyType;
	consoleObj.xyCoord(LoanReturnCoord[FieldPosition][0]+LoanReturnCoord[FieldPosition][2]+AllInput[FieldPosition].length(),LoanReturnCoord[FieldPosition][1]);
	while(!read)
	{
	    switch(FieldPosition)
	    {
            case 0:
                *InputPtr = ReferenceNumber;
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,NOSPACING,InputPtr,10,LoanReturnCoord,FieldPosition,false);
                ReferenceNumber =*InputPtr;
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 1:
                *InputPtr = IdNumber;
                KeyType=FormInputBuilderObj.FormInput(ALPHANUMERIC,SPACING,InputPtr,10,LoanReturnCoord,FieldPosition,false);
                IdNumber=*InputPtr;
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 2:
                *InputPtr = this->magazinePtr->getAuthor();
                KeyType=FormInputBuilderObj.FormInput(ALPHABETICAL,SPACING,InputPtr,10,LoanReturnCoord,FieldPosition,false);

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
        if(FieldPosition>2)
        {
            FieldPosition=2;
            read=true;
        }
        //*InputPtr = "";
        //consoleObj.xyCoord(60,3);
        //cout<< FieldPosition;
        consoleObj.xyCoord(LoanReturnCoord[FieldPosition][0]+LoanReturnCoord[FieldPosition][2]+AllInput[FieldPosition].length(),LoanReturnCoord[FieldPosition][1]);
    }
	consoleObj.setCursor(false,3);
}
}
void LoanForm::show()
{
    consoleObj.xyCoord(LoanReturnCoord[0][0],LoanReturnCoord[0][1]);
	cout<<"Reference Number: ";
	consoleObj.xyCoord(LoanReturnCoord[1][0],LoanReturnCoord[1][1]);
	cout<<"Id Number: ";
	consoleObj.xyCoord(LoanReturnCoord[2][0],LoanReturnCoord[2][1]);
	cout<<"Date: ";
}
