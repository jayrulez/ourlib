#ifndef _DATETIME_H
#define _DATETIME_H

class Date
{
private:
	int day;
	int month;
	int year;
	char* format;
public:
	Date();
	void setDate(int, int, int);
	char* getDate();
	void printDate(char* = "normal");
	~Date();
};
#endif
