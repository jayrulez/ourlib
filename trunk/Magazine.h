#ifndef _MAGAZINE_H
#define _MAGAZINE_H
#include "Referencematerial.h"
#include "DateTime.h"

using namespace std;

class Magazine:protected ReferenceMaterial
{
private:
	char* volume;
	char* issueTopic;
	DateTime issueDate;
public:
    Magazine();
    ~Magazine();
};
#endif
