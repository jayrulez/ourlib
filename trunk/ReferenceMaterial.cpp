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

string ReferenceMaterial::getReferenceNumber()
{
	return this->referenceNumber;
}
ReferenceMaterial::ReferenceMaterial(string,string,string)
{
}
string ReferenceMaterial::getReferenceNumber() const
{
}
string ReferenceMaterial::getTitle() const
{
}
string ReferenceMaterial::getAuthor() const
{
}
void ReferenceMaterial::setTitle() const
{
}
string ReferenceMaterial::getAuthor() const
{
}

