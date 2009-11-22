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
	virtual ~ReferenceMaterial();
	ReferenceMaterial(string,string,string);
	string getReferenceNumber() const;
	string getTitle() const;
	string getAuthor() const;
	void setReferenceNumber(string);
	void setTitle(string);
	void setAuthor(string);
	int getIdFromReferenceNumber(string);
};
#endif
