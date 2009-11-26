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

  time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  ret = asctime(timeinfo);
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
