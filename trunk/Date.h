#include <string>

using namespace std;

#ifndef _DATE_H
#define _DATE_H
class Date
{
private:
    string date;
public:
    Date();
    ~Date();
    string sysDate();
    string getDate();
    void setDate(string);
    bool validate(string);
};
#endif
