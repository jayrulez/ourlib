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

Loan::Loan(string memberId,string referenceNumber,string requestDate,string loanType)
{
    this->memberId = memberId;
    this->referenceNumber = referenceNumber;
	this->requestDate = requestDate;
    this->loanType = loanType;
}

void Loan::setMemberId(string memberId)
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

string Loan::getMemberId() const
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
    frameObj.setFrame(xCoord,xCoord+45,yCoord,yCoord+12,false);
    frameObj.sFraming();

    consoleObj.xyCoord(xCoord+2,yCoord+2);
    cout<<"Member ID: "<<this->getMemberId();
    consoleObj.xyCoord(xCoord+2,yCoord+4);
    cout<<"Reference Number: "<<this->getReferenceNumber();
    consoleObj.xyCoord(xCoord+2,yCoord+6);
    cout<<"Request Date: "<<this->getRequestDate();

    consoleObj.xyCoord(xCoord+2,yCoord+8);
    cout<<"Loan Type: "<<this->getLoanType();
}
