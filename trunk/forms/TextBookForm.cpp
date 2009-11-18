#ifndef _TEXTBOOKFORM_H
#include "TextBookForm.h"
#endif
#ifndef _TEXTBOOK_H
#include "../TextBook.h"
#endif

#include <iostream>
using namespace std;

TextBookForm::TextBookForm()
{
    TextBookCoord[0][0]=25;
    TextBookCoord[0][1]=12;
    TextBookCoord[0][2]=18;
    TextBookCoord[1][0]=25;
    TextBookCoord[1][1]=15;
    TextBookCoord[1][2]=8;
    TextBookCoord[2][0]=25;
    TextBookCoord[2][1]=18;
    TextBookCoord[2][2]=6;
    TextBookCoord[3][0]=25;
    TextBookCoord[3][1]=21;
    TextBookCoord[3][2]=8;
    TextBookCoord[4][0]=25;
    TextBookCoord[4][1]=24;
    TextBookCoord[4][2]=11;
    TextBookCoord[5][0]=25;
    TextBookCoord[5][1]=27;
    TextBookCoord[5][2]=16;
}

TextBookForm::~TextBookForm()
{

}
void TextBookForm::BrowseTextBookForm()
{
    consoleObj.setCursor(true,3);
	static string input;
	string *InputPtr;
	InputPtr=&input;
	int FieldPosition=0;
	bool read=false;
	int KeyType;
	consoleObj.xyCoord(TextBookCoord[FieldPosition][0]+TextBookCoord[FieldPosition][2]+InputPtr->length(),TextBookCoord[FieldPosition][1]);
	while(!read)
	{
	    switch(FieldPosition)
	    {
            case 0:
                KeyType=FormInputBuilderObj.FormInput(ALPHANUMERIC^HIPHEN,NOSPACING,InputPtr,10);
                break;
            case 1:
                KeyType=FormInputBuilderObj.FormInput(ALPHABETICAL^PUNCTUATION,SPACING,InputPtr,10);
                break;
            case 2:
                KeyType=FormInputBuilderObj.FormInput(ALPHANUMERIC,NOSPACING,InputPtr,10);
                break;

            case 3:
                KeyType=FormInputBuilderObj.FormInput(ALPHANUMERIC^PUNCTUATION,SPACING,InputPtr,10);
                break;
            case 4:
                KeyType=FormInputBuilderObj.FormInput(ALPHANUMERIC^PUNCTUATION,SPACING,InputPtr,10);
                break;
            case 5:
                KeyType=FormInputBuilderObj.FormInput(NUMERIC^DATESLASH,NOSPACING,InputPtr,10);
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
        if(FieldPosition>5)
        {
            read=true;
            break;
        }
        consoleObj.xyCoord(TextBookCoord[FieldPosition][0]+TextBookCoord[FieldPosition][2]+InputPtr->length(),TextBookCoord[FieldPosition][1]);
    }
	consoleObj.setCursor(false,3);
}

void TextBookForm::show(TextBook * textBookObj)
{
	string referenceNumber = textBookObj->getReferenceNumber();
	if(referenceNumber.empty())
	{
		//NEW RECORD
	}else{
		//record from file
	}
    consoleObj.xyCoord(TextBookCoord[0][0],TextBookCoord[0][1]);
	cout<<"Reference Number: ";
	consoleObj.xyCoord(TextBookCoord[1][0],TextBookCoord[1][1]);
	cout<<"Author: ";
    consoleObj.xyCoord(TextBookCoord[2][0],TextBookCoord[2][1]);
	cout<<"ISBN: ";
	consoleObj.xyCoord(TextBookCoord[3][0],TextBookCoord[3][1]);
	cout<<"Course: ";
	consoleObj.xyCoord(TextBookCoord[4][0],TextBookCoord[4][1]);
	cout<<"Publisher: ";
	consoleObj.xyCoord(TextBookCoord[5][0],TextBookCoord[5][1]);
	cout<<"Date Published: ";
}
