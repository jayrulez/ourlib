#ifndef _TEXTBOOK_H
#define _TEXTBOOK_H
#ifndef _REFERENCEMATERIAL_H
#include "Referencematerial.h"
#endif
#ifndef _DATE_H
#include "Date.h"
#endif
#ifndef _SERIALIZER_HPP
#include "Serializer.hpp"
#endif

#include "gui\console\console.h"
#include "gui\console\frame.h"

#include <string>
using namespace std;

class TextBook:public ReferenceMaterial
{
private:
    string referenceNumberPrefix;
	string ISBN;
	string course;
	string publisher;
	string datePublished;
	char* dataFileName;
	console consoleObj;
	frame frameObj;
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
	string getDatePublished() const;
	void showReferenceMaterial(int,int);
	string getReferenceNumberPrefix();
	char* getDataFileName();
	void write(Serializer& s)
	{
	    s << referenceNumber;
	    s << title;
	    s << author;
	    s << ISBN;
	    s << course;
	    s << publisher;
	    s << datePublished;
	}
	void read(Serializer& s)
	{
	    s >> referenceNumber;
	    s >> title;
	    s >> author;
	    s >> ISBN;
	    s >> course;
	    s >> publisher;
	    s >> datePublished;
	}
};
#endif
