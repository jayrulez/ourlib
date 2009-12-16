/*
@Group: BSC2D
@Group Members:
	<ul>
		<li>Robert Campbell: 0701334</li>
		<li>Audley Gordon: 0802218</li>
		<li>Dale McFarlane: 0801042</li>
		<li>Dyonne Duberry: 0802189</li>
		<li>Xavier Lowe: 0802488</li>
	</ul>
@
*/
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
    frameObj.setFrame(xCoord,xCoord+55,yCoord,yCoord+14,false);
    frameObj.sFraming();

    consoleObj.xyCoord(xCoord+2,yCoord+1);
    cout<<"Reference Number: "<< this->getReferenceNumber();
    consoleObj.xyCoord(xCoord+2,yCoord+3);
    cout<<"Author: "<< this->getAuthor();
    consoleObj.xyCoord(xCoord+2,yCoord+5);
    cout<<"Title: "<< this->getTitle();

    consoleObj.xyCoord(xCoord+2,yCoord+7);
    cout<<"ISBN: "<< this->getISBN();
    consoleObj.xyCoord(xCoord+2,yCoord+9);
    cout<<"Course: "<< this->getCourse();
    consoleObj.xyCoord(xCoord+2,yCoord+11);
    cout<<"Publisher: "<< this->getPublisher();
    consoleObj.xyCoord(xCoord+2,yCoord+13);
    cout<<"Date Published: "<< this->getDatePublished();
}


