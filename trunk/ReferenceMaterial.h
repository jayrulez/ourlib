#ifndef _REFERENCEMATERIAL_H
#define _REFERENCEMATERIAL_H

#define TYPE_TEXTBOOK 1
#define TYPE_MAGAZINE 2
#define TYPE_RESEARCHPAPER 3
#define TYPE_NONEXISTENT 0

#include <string>
using namespace std;

class ReferenceMaterial
{
protected:
	string referenceNumber;
    string referenceNumberPrefix;
	string title;
	string author;
	char* dataFileName;
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
	int getIdFromReferenceNumber(string) const;
	int getMaterialTypeFromReferenceNumber(string) const;
	void setReferenceNumberPrefix(string);
	string getReferenceNumberPrefix() const;
	void insertReferenceNumberPrefix(string);
	char* getDataFileName() const;
	virtual void showReferenceMaterial(int,int);
};
#endif
