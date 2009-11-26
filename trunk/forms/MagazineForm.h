#ifndef _MAGAZINEFORM_H
#define _MAGAZINEFORM_H

#ifndef _MAGAZINE_H
#include "../Magazine.h"
#endif

#ifndef _REFERENCEMATERIAL_H
#include "ReferenceMaterial.h"
#endif

#include "../gui/console/console.h"
#include "FormInputBuilder.h"

#include "Form.h"

class MagazineForm: public Form
{
private:
    int MagazineCoord[6][3];
    FormInputBuilder FormInputBuilderObj;
    console consoleObj;
    Magazine *magazinePtr;
    int FieldPosition;
    string input;
    string AllInput[6];
    string *InputPtr;
    string tag;
public:
    void setMagazinePtr(Magazine*);
	void browseEditForm(string);
    MagazineForm();
    ~MagazineForm();
    void browseForm();
	void show();
    void save();
	void editSave();
};

#endif
