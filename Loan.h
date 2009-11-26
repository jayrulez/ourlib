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
