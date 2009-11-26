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
#ifndef _RESEARCHPAPER_H
#define _RESEARCHPAPER_H
#ifndef _REFERENCEMATERIAL_H
#include "Referencematerial.h"
#endif

#include "gui\console\console.h"
#include "gui\console\frame.h"

#include <iostream>
#include <string>
using namespace std;

class ResearchPaper:public ReferenceMaterial
{
private:
	string researchTopic;
	string supervisor;
	string sponsor;
	console consoleObj;
	frame frameObj;
public:
	ResearchPaper();
	~ResearchPaper();
	ResearchPaper(string,string,string,string,string,string);
	void setResearchTopic(string);
	void setSupervisor(string);
	void setSponsor(string);
	string getResearchTopic() const;
	string getSupervisor() const;
	string getSponsor() const;
	void showReferenceMaterial(int,int);
};
#endif
