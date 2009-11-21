#ifndef _TEXTBOOKFORM_H
#include "TextBookForm.h"
#endif
#ifndef _TEXTBOOK_H
#include "../TextBook.h"
#endif
#ifndef _SERIALIZER_HPP
#include "Serializer.hpp"
#endif

#include <iostream>
using namespace std;

TextBookForm::TextBookForm()
{
    this->textBookPtr = new TextBook;
    FieldPosition=0;
    InputPtr=&input;
    TextBookCoord[0][0]=25;
    TextBookCoord[0][1]=12;
    TextBookCoord[0][2]=18;

    TextBookCoord[1][0]=25;
    TextBookCoord[1][1]=15;
    TextBookCoord[1][2]=7;

    TextBookCoord[2][0]=25;
    TextBookCoord[2][1]=18;
    TextBookCoord[2][2]=8;

    TextBookCoord[3][0]=25;
    TextBookCoord[3][1]=21;
    TextBookCoord[3][2]=6;

    TextBookCoord[4][0]=25;
    TextBookCoord[4][1]=24;
    TextBookCoord[4][2]=8;

    TextBookCoord[5][0]=25;
    TextBookCoord[5][1]=27;
    TextBookCoord[5][2]=11;

    TextBookCoord[6][0]=25;
    TextBookCoord[6][1]=30;
    TextBookCoord[6][2]=16;
}

TextBookForm::~TextBookForm()
{

}
void TextBookForm::BrowseTextBookForm()
{
	bool read=false;
	int KeyType;
	consoleObj.xyCoord(TextBookCoord[FieldPosition][0]+TextBookCoord[FieldPosition][2]+AllInput[FieldPosition].length(),TextBookCoord[FieldPosition][1]);
	while(!read)
	{
	    switch(FieldPosition)
	    {
            case 0:
                *InputPtr = this->textBookPtr->getReferenceNumber();
                KeyType=FormInputBuilderObj.FormInput(NUMERIC,NOSPACING,InputPtr,10,TextBookCoord,FieldPosition,false);
                this->textBookPtr->setReferenceNumber(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 1:
                *InputPtr = this->textBookPtr->getTitle();
                KeyType=FormInputBuilderObj.FormInput(ALPHABETICAL,SPACING,InputPtr,10,TextBookCoord,FieldPosition,false);
                this->textBookPtr->setTitle(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 2:
                *InputPtr = this->textBookPtr->getAuthor();
                KeyType=FormInputBuilderObj.FormInput(ALPHABETICAL,SPACING,InputPtr,10,TextBookCoord,FieldPosition,false);
                this->textBookPtr->setAuthor(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 3:
                *InputPtr = this->textBookPtr->getISBN();
                KeyType=FormInputBuilderObj.FormInput(ALPHANUMERIC,NOSPACING,InputPtr,10,TextBookCoord,FieldPosition,false);
                this->textBookPtr->setISBN(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;

            case 4:
                *InputPtr = this->textBookPtr->getCourse();
                KeyType=FormInputBuilderObj.FormInput(ALPHANUMERIC,SPACING,InputPtr,10,TextBookCoord,FieldPosition,false);
                this->textBookPtr->setCourse(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 5:
                *InputPtr = this->textBookPtr->getPublisher();
                KeyType=FormInputBuilderObj.FormInput(ALPHANUMERIC,SPACING,InputPtr,10,TextBookCoord,FieldPosition,false);
                this->textBookPtr->setPublisher(*InputPtr);
                AllInput[FieldPosition] = *InputPtr;
                break;
            case 6:
                *InputPtr = this->textBookPtr->getDatePublished();
                KeyType=FormInputBuilderObj.FormInput(DATE,NOSPACING,InputPtr,10,TextBookCoord,FieldPosition,false);
                this->textBookPtr->setDatePublished(*InputPtr);
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
        if(FieldPosition>5)
        {
            FieldPosition=5;
            read=true;
        }
        consoleObj.xyCoord(60,3);
        cout<< FieldPosition;
        consoleObj.xyCoord(TextBookCoord[FieldPosition][0]+TextBookCoord[FieldPosition][2]+AllInput[FieldPosition].length(),TextBookCoord[FieldPosition][1]);
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
	cout<<"Title: ";
	consoleObj.xyCoord(TextBookCoord[2][0],TextBookCoord[2][1]);
	cout<<"Author: ";
    consoleObj.xyCoord(TextBookCoord[3][0],TextBookCoord[3][1]);
	cout<<"ISBN: ";
	consoleObj.xyCoord(TextBookCoord[4][0],TextBookCoord[4][1]);
	cout<<"Course: ";
	consoleObj.xyCoord(TextBookCoord[5][0],TextBookCoord[5][1]);
	cout<<"Publisher: ";
    consoleObj.xyCoord(13,27);
	cout<<"<dd/mm/yy>";
	consoleObj.xyCoord(TextBookCoord[6][0],TextBookCoord[6][1]);
	cout<<"Date Published: ";
}

int TextBookForm::save()
{
    const unsigned int max_buffer_size = 65536 * 10;
    char* buffer = new char[max_buffer_size];
    Serializer s(buffer,max_buffer_size);
    s.clear();
    TextBook textBookObj;

    cout << this->textBookPtr->getReferenceNumber() << endl;

    ifstream fileReadObj (this->textBookPtr->getDataFileName(),ios::in | ios::binary);
    if(fileReadObj.is_open())
    {
        cout << "I am open" << endl;
        while(!fileReadObj.eof())
        {
            cout << "I am being searched" << endl;
            textBookObj.read(s);
            cout << "I am ref No. " << textBookObj.getReferenceNumber() << endl;
            break;
            if(textBookObj.getReferenceNumber()==this->textBookPtr->getReferenceNumber())
            {
                cout << "Error, Record with id exists: " << textBookObj.getReferenceNumber() << ":" << this->textBookPtr->getReferenceNumber() << endl;
            }
        }
    }


    this->textBookPtr->write(s);
    ofstream fileObj;
    fileObj.exceptions(ofstream::eofbit | ofstream::failbit | ofstream::badbit);
    try
    {
        fileObj.open(this->textBookPtr->getDataFileName(),ios::out | ios::binary);
        s.write_to_stream(fileObj);
    }catch(ofstream::failure e)
    {
        cout << "Error!" << endl;
    }
    fileObj.close();
    return 0;
}
