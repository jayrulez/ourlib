#ifndef _LOAN_H
#define _LOAN_H
#ifndef _DATE_H
#include "Date.h"
#endif
#include "./gui/console/console.h"
#include "./gui/console/frame.h"

#include <string>
using namespace std;

class Loan
{
private:
	string memberId;
	string referenceNumber;
	string requestDate;
	string loanType;
	console consoleObj;
	frame frameObj;
public:
	Loan();
	~Loan();
	Loan(string,string,string,string);
	void setMemberId(string);
	void setReferenceNumber(string);
	void setLoanType(string);
	void setRequestDate(string);
	string getMemberId() const;
	string getReferenceNumber() const;
	string getLoanType() const;
	string getRequestDate() const;
	void showLoan(int,int);
};
#endif
