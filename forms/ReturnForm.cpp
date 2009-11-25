#include"ReturnForm.h"

#include <iostream>
#include <string>
using namespace std;



ReturnForm::ReturnForm()
{
    FieldPosition=0;
    InputPtr=&input;
    ReturnCoord[0][0]=25;
    ReturnCoord[0][1]=13;
    ReturnCoord[0][2]=18;

    ReturnCoord[1][0]=25;
    ReturnCoord[1][1]=16;
    ReturnCoord[1][2]=11;

    ReturnCoord[2][0]=25;
    ReturnCoord[2][1]=19;
    ReturnCoord[2][2]=6;
}

ReturnForm::~ReturnForm()
{
}

void ReturnForm::browseForm()
{
    //char* tempId;
	bool read=false;
	int KeyType;

	consoleObj.xyCoord(ReturnCoord[FieldPosition][0]+ReturnCoord[FieldPosition][2]+
	AllInput[FieldPosition].length(),ReturnCoord[FieldPosition][1]);

	while(!read)
	{

	    switch(FieldPosition)
	    {
            case 0:
                *InputPtr =  ReferenceNumber;
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,NOSPACING,InputPtr,6,ReturnCoord,FieldPosition,false);
                ReferenceNumber = *InputPtr;
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 1:
                /*itoa(IdNumber,tempId,10);
                *InputPtr=tempId;
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,NOSPACING,InputPtr,7,ReturnCoord,FieldPosition,false);
                IdNumber = atoi(InputPtr->c_str());
                AllInput[FieldPosition] = *InputPtr;*/
                break;
            case 2:
                *InputPtr = ReturnDate;
                KeyType=FormInputBuilderObj.FormInput(DATE,SPACING,InputPtr,8,ReturnCoord,FieldPosition,false);
                ReturnDate = *InputPtr;
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
            FieldPosition = 2;
            read=true;
        }
        consoleObj.xyCoord(ReturnCoord[FieldPosition][0]+
        ReturnCoord[FieldPosition][2]+AllInput[FieldPosition].length(),
        ReturnCoord[FieldPosition][1]);
    }
	consoleObj.setCursor(false,3);
}

void ReturnForm::show()
{
    consoleObj.xyCoord(ReturnCoord[0][0],ReturnCoord[0][1]);
	cout<<"Reference Number: ";
	consoleObj.xyCoord(ReturnCoord[1][0],ReturnCoord[1][1]);
	cout<<"Id Number: ";
	consoleObj.xyCoord(ReturnCoord[2][0]-13,ReturnCoord[2][1]);
	cout<<"<dd/mm/yy>";
	consoleObj.xyCoord(ReturnCoord[2][0],ReturnCoord[2][1]);
	cout<<"Date: ";
}

void ReturnForm::save()
{
}
