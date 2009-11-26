/*
@Group: BSC2D
@Group Members:
	<ul>
		<li>Robert Campbell: 0701334</li>
		<li>Audley Gordon: 0802218</li>
		<li>Dale McFarlane: 0801042</li>
		<li>Dyonne Duberry: 0802189</li>
		<li>Xavier Lowe: 0802488</li>
	</ul>
@
*/
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
	string ISBN;
	string course;
	string publisher;
	string datePublished;
	console consoleObj;
	frame frameObj;
public:
	TextBook();
	TextBook(string,string,string,string,string,string,string);
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
