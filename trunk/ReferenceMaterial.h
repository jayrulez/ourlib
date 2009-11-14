#ifndef _REFERENCEMATERIAL_H
#define _REFERENCEMATERIAL_H

#include <string>
using namespace std;

class ReferenceMaterial
{
protected:
	string referenceNumber;
	string title;
	string author;
public:
	ReferenceMaterial();
	~ReferenceMaterial();
};
#endif
