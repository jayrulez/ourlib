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
