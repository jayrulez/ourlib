#ifndef _TEXTBOOKFORM_H
#include "TextBookForm.h"
#endif
#ifndef _TEXTBOOK_H
#include "../TextBook.h"
#endif

TextBookForm::TextBookForm()
{

}

TextBookForm::~TextBookForm()
{

}

void TextBookForm::show(TextBook * textBookObj)
{
	string referenceNumber = textBookObj->getReferenceNumber();
	if(referenceNumber.empty())
	{
		//NEW RECORD
	}else{
		//record from file
	}
}
