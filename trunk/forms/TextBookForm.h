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
public:
    TextBookForm();
    ~TextBookForm();
    void BrowseTextBookForm();
	void show(TextBook*);
};

#endif
