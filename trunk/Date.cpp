#ifndef _DATE_H
#include "Date.h"
#endif

#include <iostream>
#include <ctime>

Date::Date(){}

Date::~Date(){
}

string Date::sysDate()
{
    string ret;

    char* d;
    _strdate(d);

    ret = d;
    return ret;
}

string Date::getDate()
{
    return this->date;
}

void Date::setDate(string d="system")
{
    if(d=="system")
        this->date = this->sysDate();
    else
        this->date = d;
}

bool Date::validate(string d)
{
    return false;
}
