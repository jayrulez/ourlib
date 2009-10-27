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
#ifndef _RESEARCHPAPER_H
#define _RESEARCHPAPER_H
#include "Referencematerial.h"
using namespace std;

class ResearchPaper:public ReferenceMaterial
{
private:
    char* researchTopic;
    char* superVisor;
    char* sponsor;
public:
    ResearchPaper();
    ~ResearchPaper();
};
#endif
