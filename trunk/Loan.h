#ifndef _LOAN_H
#define _LOAN_H
#ifndef _DATE_H
#include "Date.h"
#endif

class Loan
{
private:
	int memberId;
	char* remerenceNumber;
	Date requestDate;
	char loanType;
public:
	Loan();
	~Loan();
};
#endif
