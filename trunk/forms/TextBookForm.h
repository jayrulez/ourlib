#ifndef _TEXTBOOKFORM_H
#define _TEXTBOOKFORM_H
#ifndef _TEXTBOOK_H
#include "../TextBook.h"
#endif

class TextBookForm
{
public:
    TextBookForm();
    ~TextBookForm();
	void show(TextBook*);
};

#endif
