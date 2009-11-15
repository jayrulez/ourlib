#ifndef _MAGAZINEFORM_H
#define _MAGAZINEFORM_H
#ifndef _MAGAZINE_H
#include "../Magazine.h"
#endif

class MagazineForm
{
public:
    MagazineForm();
    ~MagazineForm();
	void show(Magazine*);
};

#endif
