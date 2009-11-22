#ifndef _TEXTBOOK_H
#include "TextBook.h"
#endif

#include <iostream>
#include <string>
using namespace std;
/*
*
*/
TextBook::TextBook()
{
        this->dataFileName = "textbooks.bin";
}

/*
*
*/
TextBook::~TextBook()
{
    this->referenceNumberPrefix = "TX-";
}
TextBook::TextBook(string referenceNumber,string author,string title, string ISBN,string course,string publisher)
{
	this->referenceNumber = referenceNumber;
	this->author = author;
	this->title = title;
	this->ISBN = ISBN;
	this->course = course;
	this->publisher = publisher;
}

void TextBook::setISBN(string ISBN)
{
	this->ISBN = ISBN;
}
void TextBook::setCourse(string course)
{
	this->course = course;
}
void TextBook::setPublisher(string publisher)
{
	this->publisher = publisher;
}
void TextBook::setDatePublished(string datePublished)
{
	this->datePublished = datePublished;
}
string TextBook::getISBN() const
{
	return this->ISBN;
}
string TextBook::getCourse() const
{
	return this->course;
}
string TextBook::getPublisher() const
{
	return this->publisher;
}
string TextBook::getDatePublished() const
{
    return this->datePublished;
}
void TextBook::showReferenceMaterial(int xCoord,int yCoord)
{
    frameObj.setFrame(xCoord,20,yCoord,8,false);
    frameObj.sFraming();

    consoleObj.xyCoord(xCoord+2,yCoord+2);
    cout<<referenceNumber;
    consoleObj.xyCoord(xCoord+2,yCoord+4);
    cout<<author;
    consoleObj.xyCoord(xCoord+2,yCoord+6);
    cout<<title;

    consoleObj.xyCoord(xCoord+2,yCoord+8);
    cout<<ISBN;
    consoleObj.xyCoord(xCoord+2,yCoord+10);
    cout<<course;
    consoleObj.xyCoord(xCoord+2,yCoord+12);
    cout<<publisher;
    consoleObj.xyCoord(xCoord+2,yCoord+14);
    cout<<datePublished;

}

char* TextBook::getDataFileName()
{
    return this->dataFileName;
}

string TextBook::getReferenceNumberPrefix()
{
    return this->referenceNumberPrefix;
}


