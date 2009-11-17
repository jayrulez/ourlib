#ifndef _MAGAZINEFORM_H
#define _MAGAZINEFORM_H
#ifndef _MAGAZINE_H
#include "../Magazine.h"
#include "../gui/console/console.h"
#endif

class MagazineForm
{
private:
    int xyReferenceNumber[3];
    int xyAuthor[3];
    int xyVolume[3];
    int xyIssueTopic[3];
    int xyIssueDate[3];
    console consoleObj;
public:
    MagazineForm();
    ~MagazineForm();
    void BrowseMagazineForm(int);
	void show(Magazine*);
};

#endif
