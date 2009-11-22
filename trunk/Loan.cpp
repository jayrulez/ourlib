#ifndef _LOAN_H
#include "Loan.h"
#endif

#include <iostream>
#include <string>
using namespace std;
/*
*
*/
Loan::Loan()
{
}

/*
*
*/
Loan::~Loan()
{
}

Loan::Loan(int memberId,string referenceNumber,string loanType)
{
    this->memberId = memberId;
    this->referenceNumber = referenceNumber;
    this->loanType = loanType;
}

void Loan::setMemberId(int memberId)
{
    this->memberId = memberId;
}

void Loan::setReferenceNumber(string referenceNumber)
{
    this->referenceNumber = referenceNumber;
}

void Loan::setLoanType(string loanType)
{
    this->loanType = loanType;
}

void Loan::setRequestDate(string requestDate)
{
    this->requestDate = requestDate;
}

int Loan::getMemberId() const
{
    return this->memberId;
}

string Loan::getReferenceNumber() const
{
    return this->referenceNumber;
}

string Loan::getLoanType() const
{
    return this->loanType;
}

string Loan::getRequestDate() const
{
    return this->requestDate;
}

void Loan::showLoan(int xCoord,int yCoord)
{
}
