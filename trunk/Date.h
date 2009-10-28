#ifndef _DATETIME_H
#define _DATETIME_H

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
