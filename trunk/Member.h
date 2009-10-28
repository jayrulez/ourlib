/*
 @Group: BSC2D
 @Group Members:
	 <ul>
		<li>Robert Campbell: 0701334</li>
		<li>Audley Gordon: 0802218</li>
		<li>Dale McFarlane: 0801042</li>
		<li>Dyonne Duberry: 0802189</li>
		<li>Xavier Lowe: </li>
	 </ul>
 @
*/
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
