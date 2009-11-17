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

ReferenceMaterial::ReferenceMaterial(string,string,string)
{
}
string ReferenceMaterial::getReferenceNumber() const
{
    return this->referenceNumber;
}
string ReferenceMaterial::getTitle() const
{
}
string ReferenceMaterial::getAuthor() const
{
}
void ReferenceMaterial::setReferenceNumber(string)
{
}
void ReferenceMaterial::setTitle(string)
{
}
void ReferenceMaterial::setAuthor(string)
{
}


