#ifndef _APPLICATIONEXCEPTION_H
#define _APPLICATIONEXCEPTION_H
#include <iostream>
using namespace std;

class ApplicationException:public exception
{
private:
	char* errorMessage;
public:
	ApplicationException();
	//~ApplicationException();
};
#endif
