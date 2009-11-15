#ifndef _TEXTBOOKFORM_H
#define _TEXTBOOKFORM_H
#ifndef _TEXTBOOK_H
#include "../TextBook.h"
#endif

#ifndef CONSOLE_H
#include "../gui/console/console.h"
#endif

class TextBookForm
{
private:
    int xyISBN[3];
    int xyCourse[3];
    int xyPublisher[3];
    int xyDatePublished[3];
    console consoleObj;
public:
    TextBookForm();
    ~TextBookForm();
	void show(TextBook*);
};

#endif
