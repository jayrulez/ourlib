#ifndef _VALIDATOR_H
#include "./Validator.h"
#endif
#ifndef _REFERENCEMATERIAL_H
#include "../ReferenceMaterial.h"
#endif
#ifndef _TEXTBOOK_H
#include "../TextBook.h"
#endif
#ifndef _MAGAZINE_H
#include "../Magazine.h"
#endif
#ifndef _RESEARCHPAPER_H
#include "../ResearchPaper.h"
#endif
#ifndef _FILEMODEL_H
#include "../FileModel.h"
#endif

#include <fstream>

Validator::Validator() {}
Validator::~Validator() {}

string Validator::getError() const
{
        return this->error;
}

bool Validator::hasError()
{
    return (this->error).length()>0;
}

int Validator::checkDate(string dateStr)
{
    char month[2];
    char day[2];
    char year[2];
    memset( month, '\0', 2 );
    memset( day, '\0', 2 );
    memset( year, '\0', 2 );
    if(dateStr.length()!=8)
    {
        return 0;
    }else{
        dateStr.copy(month,2);
        int dayAsInt = atoi(day);
        int monthAsInt = atoi(month);
        int yearAsInt = atoi(year);
        //if(year)
        //{
            //return;
        //}
    }
    return 0;
}

void Validator::formValidate(int *referenceObj)
{
    ReferenceMaterial *referenceMaterialObj = (ReferenceMaterial*)referenceObj;
    int materialType = referenceMaterialObj->getMaterialTypeFromReferenceNumber(referenceMaterialObj->getReferenceNumber());

    int refNo = referenceMaterialObj->getIdFromReferenceNumber(referenceMaterialObj->getReferenceNumber());
    switch(materialType)
    {
        case TYPE_TEXTBOOK:
            if(refNo < 1 || refNo > 999)
            {
                this->error = "Reference Number must be between TX-001 and TX-999.";
            }else if(this->recordExists(referenceMaterialObj->getReferenceNumber()))
            {
                this->error = "A Textbook with the Reference number \"";
                (this->error).append((char*)refNo);
                (this->error).append("\" already exists.");
            }
        break;
        case TYPE_MAGAZINE:
            if(refNo < 1 || refNo > 999)
            {
                this->error = "Reference Number must be between MG-001 and MG-999.";
            }else if(this->recordExists(referenceMaterialObj->getReferenceNumber()))
            {
                this->error = "A Magazine with the Reference number \"";
                (this->error).append((char*)refNo);
                (this->error).append("\" already exists.");
            }
        break;
        case TYPE_RESEARCHPAPER:
            if(refNo < 1 || refNo > 999)
            {
                this->error = "Reference Number must be between RP-001 and RP-999.";
            }else if(this->recordExists(referenceMaterialObj->getReferenceNumber()))
            {
                this->error = "A Research Paper with the Reference number \"";
                (this->error).append((char*)refNo);
                (this->error).append("\" already exists.");
            }
        break;
    }
}

bool Validator::recordExists(string referenceNumber)
{
    FileModel * fileModelObj = new FileModel();
    if(fileModelObj->getReferenceMaterialRecordFromFile(referenceNumber)->getReferenceNumber()==referenceNumber)
        return true;
    else
        return false;
}
