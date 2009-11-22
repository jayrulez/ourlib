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
	void show();
	void save();
};

#endif
