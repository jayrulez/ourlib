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
    xyReferenceNumber[0]=25;
    xyReferenceNumber[1]=12;
    xyReferenceNumber[2]=18;
    xyAuthor[0]=25;
    xyAuthor[1]=15;
    xyAuthor[2]=8;
    xyISBN[0]=25;
    xyISBN[1]=18;
    xyISBN[2]=6;
    xyCourse[0]=25;
    xyCourse[1]=21;
    xyCourse[2]=8;
    xyPublisher[0]=25;
    xyPublisher[1]=24;
    xyPublisher[2]=11;
    xyDatePublished[0]=25;
    xyDatePublished[1]=27;
    xyDatePublished[2]=16;
}

TextBookForm::~TextBookForm()
{

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
    consoleObj.xyCoord(xyReferenceNumber[0],xyReferenceNumber[1]);
	cout<<"Reference Number: ";
	consoleObj.xyCoord(xyAuthor[0],xyAuthor[1]);
	cout<<"Author: ";
    consoleObj.xyCoord(xyISBN[0],xyISBN[1]);
	cout<<"ISBN: ";
	consoleObj.xyCoord(xyCourse[0],xyCourse[1]);
	cout<<"Course: ";
	consoleObj.xyCoord(xyPublisher[0],xyPublisher[1]);
	cout<<"Publisher: ";
	consoleObj.xyCoord(xyDatePublished[0],xyDatePublished[1]);
	cout<<"Date Published: ";
}
