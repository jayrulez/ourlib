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
	void browseEditForm(string);
    void browseForm();
	void show();
    void save();
	void editSave();
};

#endif
