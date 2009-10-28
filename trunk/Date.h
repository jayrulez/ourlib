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
#ifndef _DATETIME_H
#define _DATETIME_H
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;
    char* format;
    char* days[7];// = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    char* months[12];// = {"January","February","March","April","May","June","July","August","September","October","November","December"};
public:
    Date();
    void setDate(int, int, int);
    char* getDate();
    void printDate(char* = "normal");
    ~Date();
};
#endif
