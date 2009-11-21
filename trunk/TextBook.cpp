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
        this->dataFileName = "textbooks.txt";
}

/*
*
*/
TextBook::~TextBook()
{

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
}

string TextBook::getDataFileName()
{
    return this->dataFileName;
}
