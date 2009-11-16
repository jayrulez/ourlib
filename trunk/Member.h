#ifndef _MEMBER_H
#define _MEMBER_H

#include <string>
using namespace std;

class Member
{
private:
	int id;
	string firstName;
	string lastName;
	string address;
	string contactNumber;
public:
	Member();
	~Member();
	Member(int,string,string,string,string);
	void setId(int);
	void setFirstName(string);
	void setLastName(string);
	void setAddress(string);
	void setContactNumber(string);
	int getId() const;
	string getFirstName() const;
	string getLastName() const;
	string getAddress() const;
	string getContactNumber() const;
	void showMember(int,int);
};
#endif
