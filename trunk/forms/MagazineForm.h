#ifndef _MAGAZINEFORM_H
#define _MAGAZINEFORM_H
#ifndef _MAGAZINE_H
#include "../Magazine.h"
#endif
#include "../gui/console/console.h"
#include "FormInputBuilder.h"



class MagazineForm
{
private:
    int MagazineCoord[5][3];
    FormInputBuilder FormInputBuilderObj;
    console consoleObj;
public:
    MagazineForm();
    ~MagazineForm();
    void BrowseMagazineForm();
	void show(Magazine*);
};

#endif
