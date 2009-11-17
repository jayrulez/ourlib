#ifndef _RESEARCHPAPERFORM_H
#define _RESEARCHPAPERFORM_H

#ifndef _RESEARCHPAPER_H
#include "../ResearchPaper.h"
#endif

#ifndef CONSOLE_H
#include "../gui/console/console.h"
#endif

#include "FormInputBuilder.h"

class ResearchPaperForm
{
private:
    int ResearchPaperCoord[5][3];
	console consoleObj;
	FormInputBuilder FormInputBuilderObj;
public:
    ResearchPaperForm();
    ~ResearchPaperForm();
    void BrowseResearchPaperForm();
	void show(ResearchPaper*);
};

#endif
