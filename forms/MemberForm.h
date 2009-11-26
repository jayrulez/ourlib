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
#ifndef _MEMBERFORM_H
#define _MEMBERFORM_H

#ifndef _MEMBER_H
#include "../Member.h"
#endif

#include "../gui/console/console.h"
#include "FormInputBuilder.h"

#include "Form.h"

class MemberForm: public Form
{
private:
    int MemberCoord[5][3];
    console consoleObj;
    FormInputBuilder FormInputBuilderObj;
    Member *memberPtr;
    int FieldPosition;
    int IdNumber;
    string input;
    string AllInput[5];
    string *InputPtr;
public:
    MemberForm();
    ~MemberForm();
    void browseForm();
	void show();
    void save();
};
#endif // MEMBERFORM_H_
