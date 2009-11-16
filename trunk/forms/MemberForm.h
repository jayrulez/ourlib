#ifndef MEMBERFORM_H
#define MEMBERFORM_H

#include "../gui/console/console.h"

class MemberForm
{
private:
    int xyIdNumber[3];
    int xyFirstName[3];
    int xyLastName[3];
    int xyAddress[3];
    int xyContactNumber[3];
    console consoleObj;
public:
    MemberForm();
    ~MemberForm();
	void show();
};
#endif // MEMBERFORM_H_
