#ifndef _TEXTBOOK_H
#define _TEXTBOOK_H
#ifndef _REFERENCEMATERIAL_H
#include "Referencematerial.h"
#endif
#ifndef _DATE_H
#include "Date.h"
#endif

class TextBook:public ReferenceMaterial
{
private:
	char* ISBN;
	char* course;
	char* publisher;
	Date datePublished;
public:
    TextBook();
    ~TextBook();
};
#endif
