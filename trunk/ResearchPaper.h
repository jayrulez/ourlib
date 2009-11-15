#ifndef _RESEARCHPAPER_H
#define _RESEARCHPAPER_H
#ifndef _REFERENCEMATERIAL_H
#include "Referencematerial.h"
#endif

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
};
#endif
