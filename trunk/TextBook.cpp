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
        this->setReferenceNumberPrefix("TX-");
}

/*
*
*/
TextBook::~TextBook()
{
}
TextBook::TextBook(string referenceNumber,string author,string title, string ISBN,string course,string publisher,string datePublished)
{
	this->referenceNumber = referenceNumber;
	this->author = author;
	this->title = title;
	this->ISBN = ISBN;
	this->course = course;
	this->publisher = publisher;
	this->datePublished = datePublished;
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
    frameObj.setFrame(xCoord,xCoord+45,yCoord,yCoord+16,false);
    frameObj.sFraming();

    consoleObj.xyCoord(xCoord+2,yCoord+2);
    cout<<"Reference Number: "<< this->referenceNumber;
    consoleObj.xyCoord(xCoord+2,yCoord+4);
    cout<<"Author: "<< this->author;
    consoleObj.xyCoord(xCoord+2,yCoord+6);
    cout<<"Title: "<< this->title;

    consoleObj.xyCoord(xCoord+2,yCoord+8);
    cout<<"ISBN: "<< this->ISBN;
    consoleObj.xyCoord(xCoord+2,yCoord+10);
    cout<<"Course: "<< this->course;
    consoleObj.xyCoord(xCoord+2,yCoord+12);
    cout<<"Publisher: "<< this->publisher;
    consoleObj.xyCoord(xCoord+2,yCoord+14);
    cout<<"Date Published: "<< this->datePublished;

}


