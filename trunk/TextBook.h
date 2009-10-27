#ifndef _TEXTBOOK_H
#define _TEXTBOOK_H
#include "Referencematerial.h"
#include "DateTime.h"
using namespace std;

class TextBook:protected ReferenceMaterial
{
private:
	char* ISBN;
	char* course;
	char* publisher;
	DateTime datePublished;
public:
    TextBook();
    ~TextBook();
};
#endif
