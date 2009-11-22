#ifndef _REFERENCEMATERIAL_H
#include "ReferenceMaterial.h"
#endif
#include <iostream>
#include <string>

using namespace std;
/*
*
*/
ReferenceMaterial::ReferenceMaterial()
{
}

/*
*
*/
ReferenceMaterial::~ReferenceMaterial()
{
}

ReferenceMaterial::ReferenceMaterial(string referenceNumber,string title,string author)
{
    this->referenceNumber = referenceNumber;
    this->title = title;
    this->author = author;
}
string ReferenceMaterial::getReferenceNumber() const
{
    return this->referenceNumber;
}
string ReferenceMaterial::getTitle() const
{
    return this->title;
}
string ReferenceMaterial::getAuthor() const
{
    return this->author;
}
void ReferenceMaterial::setReferenceNumber(string referenceNumber)
{
    this->referenceNumber = referenceNumber;
}
void ReferenceMaterial::setTitle(string title)
{
    this->title = title;
}
void ReferenceMaterial::setAuthor(string author)
{
    this->author = author;
}

int ReferenceMaterial::getIdFromReferenceNumber(string referenceNumber)
{
	int length = referenceNumber.length();
	char idAsChar[length-3];
	const char* asCharStr = referenceNumber.c_str();
	for(int i=2; i < length; i++)
	{
		idAsChar[i] = asCharStr[i];
	}

	int id = atoi(idAsChar);
	return id;
}


