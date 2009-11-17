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
}

/*
*
*/
TextBook::~TextBook()
{

}
TextBook::TextBook(string referenceNumber,string author,string ISBN,string course,string publisher)
{
	this->referenceNumber = referenceNumber;
	this->author = author;
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
string TextBook::setCourse() const
{
	return this->course;
}
string TextBook::setPublisher() const
{
	return this->publisher;
}
void TextBook::showReferenceMaterial(int xCoord,int yCoord)
{
}
