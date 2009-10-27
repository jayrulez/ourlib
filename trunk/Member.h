#ifndef _MEMBER_H
#define _MEMBER_H
using namespace std;

class Member
{
private:
	int id;
	char* firstName;
	char* lastName;
	char* address;
	char* contactNumber;
public:
    Member();
    ~Member();
};
#endif
