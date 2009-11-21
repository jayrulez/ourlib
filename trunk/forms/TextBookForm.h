#ifndef _TEXTBOOKFORM_H
#define _TEXTBOOKFORM_H
#ifndef _TEXTBOOK_H
#include "../TextBook.h"
#endif

#ifndef CONSOLE_H
#include "../gui/console/console.h"
#endif

#include "FormInputBuilder.h"

class TextBookForm
{
private:
    int TextBookCoord[6][3];
    console consoleObj;
    FormInputBuilder FormInputBuilderObj;
    TextBook *textBookPtr;
    int FieldPosition;
    string input;
    string AllInput[5];
    string *InputPtr;
public:
    TextBookForm();
    ~TextBookForm();
    void BrowseTextBookForm();
	void show(TextBook*);
};

#endif
