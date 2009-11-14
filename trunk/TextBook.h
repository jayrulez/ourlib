#ifndef _TEXTBOOK_H
#define _TEXTBOOK_H
#ifndef _REFERENCEMATERIAL_H
#include "Referencematerial.h"
#endif
#ifndef _DATE_H
#include "Date.h"
#endif

#include <string>
using namespace std;

class TextBook:public ReferenceMaterial
{
private:
	string ISBN;
	string course;
	string publisher;
	Date datePublished;
public:
	TextBook();
	~TextBook();
};
#endif
