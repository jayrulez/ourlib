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
    frameObj.setFrame(xCoord,xCoord+35,yCoord,yCoord+9,false);
    frameObj.sFraming();

    consoleObj.xyCoord(xCoord+2,yCoord+1);
    cout<<"Reference Number: "<< this->getReferenceNumber();
    consoleObj.xyCoord(xCoord+2,yCoord+2);
    cout<<"Author: "<< this->getAuthor();
    consoleObj.xyCoord(xCoord+2,yCoord+3);
    cout<<"Title: "<< this->getTitle();

    consoleObj.xyCoord(xCoord+2,yCoord+4);
    cout<<"ISBN: "<< this->getISBN();
    consoleObj.xyCoord(xCoord+2,yCoord+5);
    cout<<"Course: "<< this->getCourse();
    consoleObj.xyCoord(xCoord+2,yCoord+6);
    cout<<"Publisher: "<< this->getPublisher();
    consoleObj.xyCoord(xCoord+2,yCoord+7);
    cout<<"Date Published: "<< this->getDatePublished();

}


