#ifndef _RESEARCHPAPERFORM_H
#define _RESEARCHPAPERFORM_H

#ifndef _RESEARCHPAPER_H
#include "../ResearchPaper.h"
#endif

#ifndef CONSOLE_H
#include "../gui/console/console.h"
#endif

#include "FormInputBuilder.h"
#include "Form.h"

class ResearchPaperForm: public Form
{
private:
    int ResearchPaperCoord[6][3];
	console consoleObj;
	FormInputBuilder FormInputBuilderObj;
	ResearchPaper *researchPaperPtr;
    int FieldPosition;
    string input;
    string AllInput[6];
    string *InputPtr;
    string tag;
public:
    ResearchPaperForm();
    ~ResearchPaperForm();
    void BrowseResearchPaperForm();
	void show(ResearchPaper*);
};

#endif
