#ifndef _DATETIME_H
#define _DATETIME_H

#include <string>
using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;
	string format;
public:
	Date();
	void setDate(int, int, int);
	string getDate();
	void printDate(string = "normal");
	~Date();
};
#endif
