/*
 @Group: BSC2D
 @Group Members:
	 <ul>
		<li>Robert Campbell: 0701334</li>
		<li>Audley Gordon: </li> 
		<li>Dale McFarlane: 0801042</li>
		<li>Dyonne Duberry: 0802189</li>
		<li>Xavier Lowe: </li>
	 </ul>
 @
*/
#ifndef _DATETIME_H
#define _DATETIME_H
using namespace std;

class Date
{
private:
    int hour;
    int minute;
    int second;
    int day;
    int month;
    int year;
public:
    Date();
    ~Date();
};
#endif
