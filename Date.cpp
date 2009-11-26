/*
@Group: BSC2D
@Group Members:
	<ul>
		<li>Robert Campbell: 0701334</li>
		<li>Audley Gordon: 0802218</li>
		<li>Dale McFarlane: 0801042</li>
		<li>Dyonne Duberry: 0802189</li>
		<li>Xavier Lowe: 0802488</li>
	</ul>
@
*/
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
