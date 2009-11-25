#ifndef RETURNFORM_H
#define RETURNFORM_H

#include "../gui/console/console.h"
#include "FormInputBuilder.h"

#include "Form.h"

#include <string>
using namespace std;

class ReturnForm: public Form
{
private:
    int ReturnCoord[3][3];
    console consoleObj;
    FormInputBuilder FormInputBuilderObj;

    string ReferenceNumber;
    int IdNumber;
    string ReturnDate;

    int FieldPosition;
    string AllInput[3];
    string input;
    string *InputPtr;
public:
    ReturnForm();
    ~ReturnForm();
    void browseForm();
	void show();
    void save();

};

#endif // RETURNFORM_H
