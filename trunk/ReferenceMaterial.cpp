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

int ReferenceMaterial::getIdFromReferenceNumber(string referenceNumber) const
{
    string idAsString = referenceNumber.substr(3);
    int id = atoi(idAsString.c_str());
	return id;
}

int ReferenceMaterial::getMaterialTypeFromReferenceNumber(string referenceNumber) const
{
    string shortType = referenceNumber.substr(3);

    if(shortType.compare("TX-")==0)
    {
        return TYPE_TEXTBOOK;
    }else if(shortType.compare("MG-")==0)
    {
        return TYPE_MAGAZINE;
    }else if(shortType.compare("RP-")==0)
    {
        return TYPE_RESEARCHPAPER;
    }else{
        return TYPE_NONEXISTENT;
    }
}

void ReferenceMaterial::setReferenceNumberPrefix(string referenceNumberPrefix)
{
    this->referenceNumberPrefix = referenceNumberPrefix;
}

string ReferenceMaterial::getReferenceNumberPrefix() const
{
    return this->referenceNumberPrefix;
}


