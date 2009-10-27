#ifndef _LOAN_H
#define _LOAN_H
#include "DateTime.h"

using namespace std;

class Loan
{
private:
	int memberId;
	char* remerenceNumber;
	DateTime requestDate;
	char loanType;
public:
    Loan();
    ~Loan();
};
#endif
