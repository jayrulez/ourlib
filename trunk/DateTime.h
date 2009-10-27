#ifndef _DATETIME_H
#define _DATETIME_H
using namespace std;

class DateTime
{
private:
    int hour;
    int minute;
    int second;
    int day;
    int month;
    int year;
public:
    DateTime();
    ~DateTime();
};
#endif
