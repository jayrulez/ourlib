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
#ifndef _MEMBER_H
#define _MEMBER_H

#include "gui\console\console.h"
#include "gui\console\frame.h"

#include <string>
using namespace std;

class Member
{
private:
	string id;
	string firstName;
	string lastName;
	string address;
	string contactNumber;
	console consoleObj;
	frame frameObj;
public:
	Member();
	~Member();
	Member(string,string,string,string,string);
	void setId(string);
	int getNewId();
	void setFirstName(string);
	void setLastName(string);
	void setAddress(string);
	void setContactNumber(string);
	string getId() const;
	string getFirstName() const;
	string getLastName() const;
	string getAddress() const;
	string getContactNumber() const;
	void showMember(int,int);
};
#endif
