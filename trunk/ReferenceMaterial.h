/*
 @Group: BSC2D
 @Group Members:
	 <ul>
		<li>Robert Campbell: 0701334</li>
		<li>Audley Gordon: 0802218</li>
		<li>Dale McFarlane: 0801042</li>
		<li>Dyonne Duberry: 0802189</li>
		<li>Xavier Lowe: </li>
	 </ul>
 @
*/
#ifndef _REFERENCEMATERIAL_H
#define _REFERENCEMATERIAL_H
using namespace std;

class ReferenceMaterial
{
protected:
    char* referenceNumber;
    char* title;
    char* author;
public:
    ReferenceMaterial();
    ~ReferenceMaterial();
};
#endif
