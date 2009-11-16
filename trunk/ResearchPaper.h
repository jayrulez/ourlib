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
	ResearchPaper(string,string,string);
	void setResearchTopic(string);
	void setSupervisor(string);
	void setSponsor(string);
	int getResearchTopic() const;
	int getSupervisor() const;
	int getSponsor() const;
	void showReferenceMaterial(int,int);
};
#endif
