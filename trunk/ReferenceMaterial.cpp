#ifndef _REFERENCEMATERIAL_H
#include "ReferenceMaterial.h"
#endif
#include <iostream>
#include <string>
#include <stdlib.h>

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
    int refNoLength = referenceNumber.length();
    const char* refNoAsCharStr = referenceNumber.c_str();
	int idLength = refNoLength - 3;
	int i = 3;
	int c;
	char idAsString[idLength];

	for(c=0; c < idLength; i++, c++)
	{
		idAsString[c] = refNoAsCharStr[i];
	}

	int id = atoi(idAsString);
	return id;
}


