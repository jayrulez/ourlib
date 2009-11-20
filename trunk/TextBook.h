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
	string datePublished;
public:
	TextBook();
	TextBook(string,string,string,string,string,string);
	~TextBook();
	void setISBN(string);
	void setCourse(string);
	void setPublisher(string);
	void setDatePublished(string);
	string getISBN() const;
    string getCourse() const;
	string getPublisher() const;
	void showReferenceMaterial(int,int);
};
#endif
