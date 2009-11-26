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
#ifndef _TEXTBOOKFORM_H
#define _TEXTBOOKFORM_H
#ifndef _TEXTBOOK_H
#include "../TextBook.h"
#endif

#ifndef CONSOLE_H
#include "../gui/console/console.h"
#endif

#include "FormInputBuilder.h"
#include "Form.h"

class TextBookForm: public Form
{
private:
    int TextBookCoord[7][3];
    console consoleObj;
    FormInputBuilder FormInputBuilderObj;
    TextBook *textBookPtr;
    int FieldPosition;
    string input;
    string AllInput[7];
    string *InputPtr;
    string tag;
    //string ReferenceNumber;
public:
    TextBookForm();
    ~TextBookForm();
    void browseForm();
	void browseEditForm(string);
	void show();
	void save();
	void editSave();
};

#endif
