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
};
#endif
