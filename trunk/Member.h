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
