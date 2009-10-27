/*
 @Group: BSC2D
 @Group Members:
	 <ul>
		<li>Robert Campbell: 0701334</li>
		<li>Audley Gordon: </li> 
		<li>Dale McFarlane: 0801042</li>
		<li>Dyonne Duberry: 0802189</li>
		<li>Xavier Lowe: </li>
	 </ul>
 @
*/
#ifndef _TEXTBOOK_H
#define _TEXTBOOK_H
#include "Referencematerial.h"
#include "Date.h"
using namespace std;

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
