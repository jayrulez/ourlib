#ifndef MEMBERFORM_H
#define MEMBERFORM_H

#ifndef _MEMBER_H
#include "../Member.h"
#endif

#include "../gui/console/console.h"
#include "FormInputBuilder.h"

class MemberForm
{
private:
    int MemberCoord[5][3];
    console consoleObj;
    FormInputBuilder FormInputBuilderObj;
public:
    MemberForm();
    ~MemberForm();
    void BrowseMemberForm();
	void show();
};
#endif // MEMBERFORM_H_
