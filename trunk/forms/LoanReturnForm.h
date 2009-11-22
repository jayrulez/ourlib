#ifndef LOANRETURNFORM_H
#define LOANRETURNFORM_H

#include "../gui/console/console.h"
#include "FormInputBuilder.h"
#include <string>

using namespace std;

class LoanReturnForm
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
    void BrowseLoanReturnForm();
	void show();
};

#endif // LOANFORM_H
