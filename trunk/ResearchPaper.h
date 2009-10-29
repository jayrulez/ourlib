#ifndef _RESEARCHPAPER_H
#define _RESEARCHPAPER_H
#ifndef _REFERENCEMATERIAL_H
#include "Referencematerial.h"
#endif

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
