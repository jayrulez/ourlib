#ifndef _APPLICATIONEXCEPTION_H
#define _APPLICATIONEXCEPTION_H
#include <exception>
#include <iostream>
using namespace std;

class ApplicationException:public exception
{
private:
	string errorMessage;
public:
	ApplicationException();
	~ApplicationException() throw();
	void toString();
	//~ApplicationException();
};
#endif
