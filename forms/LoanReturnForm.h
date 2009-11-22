#ifndef LOANRETURNFORM_H
#define LOANRETURNFORM_H

#include "../gui/console/console.h"
#include "FormInputBuilder.h"
#include <string>

#include "Form.h"

using namespace std;

class LoanReturnForm: public Form
{
private:
    int LoanReturnCoord[3][3];
    console consoleObj;
    FormInputBuilder FormInputBuilderObj;
    string ReferenceNumber;
    int IdNumber;
    int FieldPosition;
    string LoanReturnDate;
    string AllInput[3];
    string input;
    string *InputPtr;
public:
    LoanReturnForm();
    ~LoanReturnForm();
    void browseForm();
	void show();
    void save();
};

#endif // LOANFORM_H
