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
