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
    string input;
    string AllInput[5];
    string *InputPtr;
public:
    MemberForm();
    ~MemberForm();
    void BrowseMemberForm();
	void show();
};
#endif // MEMBERFORM_H_
