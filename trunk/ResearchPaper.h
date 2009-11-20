#ifndef _RESEARCHPAPER_H
#define _RESEARCHPAPER_H
#ifndef _REFERENCEMATERIAL_H
#include "Referencematerial.h"
#endif
#include <iostream>
#include <string>
using namespace std;

class ResearchPaper:public ReferenceMaterial
{
private:
	string researchTopic;
	string supervisor;
	string sponsor;
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
