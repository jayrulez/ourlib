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
	string referenceNumber;
	Date requestDate;
	string loanType;
public:
	Loan();
	~Loan();
	Loan(int,string,string);
	void setMemberId(int);
	void setReferenceNumber(string);
	void setLoanType(string);
	void setRequestDate(int,int,int);
	int getMemberId() const;
	string getReferenceNumber() const;
	string getLoanType() const;
	void showLoan(int,int);
};
#endif
