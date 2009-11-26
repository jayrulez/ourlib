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
#ifndef FORMINPUTBUILDER_H
#define FORMINPUTBUILDER_H

#ifndef CONSOLE_H
#include "..\gui\console\console.h"
#endif

#define NUMERIC 1
#define ALPHABETICAL 2
#define ALPHANUMERIC 3
#define PUNCTUATION 4
#define DATE 5
#define SPACING 1
#define NOSPACING 2

#include <string>
using namespace std;

class FormInputBuilder
{
private:
        console consoleObj;
public:
    FormInputBuilder();
    ~FormInputBuilder();
    int FormInput(int,int,string*,int,int[][3],int,bool);
};

#endif // FORMINPUTBUILDER_H
