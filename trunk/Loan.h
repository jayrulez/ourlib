#ifndef _LOAN_H
#define _LOAN_H
#ifndef _DATE_H
#include "Date.h"
#endif

#include <string>
using namespace std;

class Loan
{
private:
	int memberId;
	string remerenceNumber;
	Date requestDate;
	string loanType;
public:
	Loan();
	~Loan();
};
#endif
