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
	ReferenceMaterial(string,string,string);
	string getReferenceNumber() const;
	string getTitle() const;
	string getAuthor() const;
	void setReferenceNumber(string);
	void setTitle() const;
	void getAuthor() const;
	virtual void showReferenceMaterial(int,int)=0;
};
#endif
