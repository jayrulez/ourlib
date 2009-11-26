#ifndef RETURNFORM_H
#define RETURNFORM_H
#ifndef _LOAN_H
#include "../Loan.h"
#endif
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
    string IdNumber;
    string ReturnDate;
	Loan * loanPtr;

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
