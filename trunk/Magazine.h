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
#ifndef _MAGAZINE_H
#define _MAGAZINE_H
#include "Referencematerial.h"
#include "Date.h"

using namespace std;

class Magazine:public ReferenceMaterial
{
private:
	char* volume;
	char* issueTopic;
	Date issueDate;
public:
    Magazine();
    ~Magazine();
};
#endif
