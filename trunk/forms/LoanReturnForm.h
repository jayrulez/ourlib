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
    int LoanReturnCoord[4][3];
    console consoleObj;
    FormInputBuilder FormInputBuilderObj;

    string ReferenceNumber;
    int IdNumber;
    string LoanReturnDate;
    string LoanType;

    int FieldPosition;
    string AllInput[4];
    string input;
    string *InputPtr;
    string choices[2];
public:
    LoanReturnForm();
    ~LoanReturnForm();
    void browseForm();
	void show();
    void save();
};

#endif // LOANFORM_H
