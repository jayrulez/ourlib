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
	if(referenceNumber.length()>4)
	{
		if(referenceNumber.find("TX-")!=string::npos)
		{
			return TYPE_TEXTBOOK;
		}else if(referenceNumber.find("MG-")!=string::npos)
		{
			return TYPE_MAGAZINE;
		}else if(referenceNumber.find("RP-")!=string::npos)
		{
			return TYPE_RESEARCHPAPER;
		}else{
			return TYPE_NONEXISTENT;
		}
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

void ReferenceMaterial::showReferenceMaterial(int xCoord, int yCoord)
{

}


