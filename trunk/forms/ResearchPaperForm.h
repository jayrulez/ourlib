#ifndef _RESEARCHPAPERFORM_H
#define _RESEARCHPAPERFORM_H

#ifndef _RESEARCHPAPER_H
#include "../ResearchPaper.h"
#endif

#ifndef CONSOLE_H
#include "../gui/console/console.h"
#endif

class ResearchPaperForm
{
private:
    int xyReferenceNumber[3];
    int xyAuthor[3];
    int xyResearchTopic[3];
	int xySupervisor[3];
	int xySponsor[3];
	console consoleObj;
public:
    ResearchPaperForm();
    ~ResearchPaperForm();
	void show(ResearchPaper*);
};

#endif
