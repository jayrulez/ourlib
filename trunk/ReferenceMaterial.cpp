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

void ReferenceMaterial::insertReferenceNumberPrefix(string referenceNumber)
{
    if(referenceNumber.length()==2)
    {
        referenceNumber = (string) "0" + referenceNumber;
    }
    if(referenceNumber.length()==1)
    {
        referenceNumber = (string) "00" + referenceNumber;
    }
    this->referenceNumber = (this->getReferenceNumberPrefix()).append(referenceNumber);
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
    char prefix[3];
    for(int i=0;i<3;i++)
        prefix[i] = referenceNumber[i];
    string shortType = prefix;

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

char* ReferenceMaterial::getDataFileName() const
{
    return this->dataFileName;
}

ReferenceMaterial* ReferenceMaterial::getRecordFromFile(string referenceNumber)
{
    ReferenceMaterial * referenceMaterialObj;
    switch(this->getMaterialTypeFromReferenceNumber(referenceNumber))
    {
        case TYPE_TEXTBOOK:
            //TextBook textBookObj;
            //referenceMaterialObj = &textBookObj;
        break;
        case TYPE_MAGAZINE:
        break;
        case TYPE_RESEARCHPAPER:
        break;
    }
    return referenceMaterialObj;
}


