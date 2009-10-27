#ifndef _RESEARCHPAPER_H
#define _RESEARCHPAPER_H
#include "Referencematerial.h"
using namespace std;

class ResearchPaper:protected ReferenceMaterial
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
