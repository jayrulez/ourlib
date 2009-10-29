#ifndef _MAGAZINE_H
#define _MAGAZINE_H
#ifndef _REFERENCEMATERIAL_H
#include "Referencematerial.h"
#endif
#ifndef _DATE_H
#include "Date.h"
#endif

class Magazine:public ReferenceMaterial
{
private:
	char* volume;
	char* issueTopic;
	Date issueDate;
public:
	Magazine();
	~Magazine();
};
#endif
