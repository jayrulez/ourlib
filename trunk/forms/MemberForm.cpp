#ifndef MEMBERFORM_H
#include "MemberForm.h"
#endif

#include <iostream>
using namespace std;

MemberForm::MemberForm()
{
    xyIdNumber[0]=20;
    xyIdNumber[1]=14;
    xyIdNumber[2]=11;
    xyFirstName[0]=20;
    xyFirstName[1]=17;
    xyFirstName[2]=12;
    xyLastName[0]=20;
    xyLastName[1]=20;
    xyLastName[2]=11;
    xyAddress[0]=20;
    xyAddress[1]=23;
    xyAddress[2]=9;
    xyContactNumber[0]=20;
    xyContactNumber[1]=26;
    xyContactNumber[2]=16;
}
MemberForm::~MemberForm()
{
}
void MemberForm::show()
{
    consoleObj.xyCoord(xyIdNumber[0],xyIdNumber[1]);
	cout<<"Id Number: ";
	consoleObj.xyCoord(xyFirstName[0],xyFirstName[1]);
	cout<<"First Name: ";
    consoleObj.xyCoord(xyLastName[0],xyLastName[1]);
	cout<<"Last Name: ";
	consoleObj.xyCoord(xyAddress[0],xyAddress[1]);
	cout<<"Address: ";
	consoleObj.xyCoord(xyContactNumber[0],xyContactNumber[1]);
	cout<<"Contact Number: ";
}
