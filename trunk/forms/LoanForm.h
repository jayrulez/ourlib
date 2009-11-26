/*
@Group: BSC2D
@Group Members:
	<ul>
		<li>Robert Campbell: 0701334</li>
		<li>Audley Gordon: 0802218</li>
		<li>Dale McFarlane: 0801042</li>
		<li>Dyonne Duberry: 0802189</li>
		<li>Xavier Lowe: 0802488</li>
	</ul>
@
*/
#ifndef LOANFORM_H
#define LOANFORM_H
#ifndef _LOAN_H
#include "../Loan.h"
#endif

#include "../gui/console/console.h"
#include "FormInputBuilder.h"
#include <string>

#include "Form.h"

using namespace std;

class LoanForm: public Form
{
private:
    int LoanCoord[4][3];
    console consoleObj;
    FormInputBuilder FormInputBuilderObj;
	Loan *loanPtr;

    string ReferenceNumber;
    int IdNumber;
    string LoanDate;
    string LoanType;

    int FieldPosition;
    string AllInput[4];
    string input;
    string *InputPtr;
public:
    LoanForm();
    ~LoanForm();
    void browseForm();
	void show();
    void save();
};

#endif // LOANFORM_H
