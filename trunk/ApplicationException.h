#ifndef _APPLICATIONEXCEPTION_H
#define _APPLICATIONEXCEPTION_H

class ApplicationException:public exception
{
private:
	char* errorMessage;
public:
	ApplicationException();
	~ApplicationException();
};
#endif
