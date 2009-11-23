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

bool Validator::checkDate(string dateStr)
{
    char month[2];
    char day[2];
    char year[2];
    char sep1[1];
    char sep2[1];
    memset( month, '\0', 2 );
    memset( day, '\0', 2 );
    memset( year, '\0', 2 );
    memset( sep1, '\0', 1 );
    memset( sep2, '\0', 2 );
    if(dateStr.length()!=8||())
    {
        return false;
    }else{
       /* dateStr.copy(month,2);
        dateStr = dateStr.substr(2);
        dateStr.copy(sep1,1);
        dateStr.substr(1);

        dateStr.copy(month,2);
        dateStr = dateStr.substr(2);
        dateStr.copy(sep2,1);
        dateStr.substr(1);

        int dayAsInt = atoi(day);
        int monthAsInt = atoi(month);
        int yearAsInt = atoi(year);
        cout << monthAsInt << dayAsInt << yearAsInt << endl;
        //if(year)
        //{
            //return;
        //}*/
    }
    return true;
}

void Validator::formValidate(int *referenceObj)
{
    int materialType = ((ReferenceMaterial*)referenceObj)->getMaterialTypeFromReferenceNumber(((ReferenceMaterial*)referenceObj)->getReferenceNumber());

    int refNo = ((ReferenceMaterial*)referenceObj)->getIdFromReferenceNumber(((ReferenceMaterial*)referenceObj)->getReferenceNumber());
    switch(materialType)
    {
        case TYPE_TEXTBOOK:
            TextBook *textBookObj = (TextBook*)referenceObj;
            if(refNo < 1 || refNo > 999)
            {
                this->error = "Reference Number must be between TX-001 and TX-999.";
            }else if(this->recordExists(textBookObj->getReferenceNumber()))
            {
                this->error = "A Textbook with the Reference number already exists.";
            }else if(textBookObj->getTitle().length()<5)
            {
                this->error = "Title must be atleast 5 characters long";
            }else if(textBookObj->getAuthor().length()<5)
            {
                this->error = "Author\'s name must be atleast 5 characters long.";
            }else if(textBookObj->getISBN().length()<9)
            {
                this->error = "ISBN must be atleast 9 characters long.";
            }else if(textBookObj->getPublisher().length()<5)
            {
                this->error = "Publisher\'s name must be atleast 5 characters long.";
            }else if(!this->checkDate(textBookObj->getDatePublished()))
            {
                this->error = "Enter a valid date in the format mm/dd/yy";
            }
        break;
        case TYPE_MAGAZINE:
            Magazine *magazineObj = (Magazine*)referenceObj;
            int volume;
            volume = atoi(magazineObj->getVolume().c_str());
            if(refNo < 1 || refNo > 999)
            {
                this->error = "Reference Number must be between MG-001 and MG-999.";
            }else if(this->recordExists(magazineObj->getReferenceNumber()))
            {
                this->error = "Reference number already exists";
            }else if(magazineObj->getTitle().length()<5)
            {
                this->error = "Title must be atleast 5 characters long.";
            }else if(magazineObj->getAuthor().length()<10)
            {
                this->error = "Author\'s name must be atleast 10 characters long.";
            }else if(volume < 1 || volume > 100)
            {
                this->error = "You must enter a volume between 1 and 100.";
            }else if(!this->checkDate(magazineObj->getIssueDate()))
            {
                this->error = "Issue date requires a valid date in the format mm/dd/yy.";
            }else if(magazineObj->getIssueTopic().length()<5)
            {
                this->error = "Issue Topic must be atleast 5 characters long.";
            }
        break;
        case TYPE_RESEARCHPAPER:
            ResearchPaper *researchPaperObj = (ResearchPaper*)referenceObj;
            if(refNo < 1 || refNo > 999)
            {
                this->error = "Reference Number must be between RP-001 and RP-999.";
            }else if(this->recordExists(researchPaperObj->getReferenceNumber()))
            {
                this->error = "A Research Paper with the Reference number already exists.";
            }else if(researchPaperObj->getTitle().length()<10)
            {
                this->error = "Title must be atleast 10 characters long.";
            }else if(researchPaperObj->getAuthor().length()<10)
            {
                this->error = "Author\'s name must be atleast 10 characters long.";
            }else if(researchPaperObj->getResearchTopic().length()<10)
            {
                this->error = "Research Topic must be atleast 10 characters long.";
            }else if(researchPaperObj->getSupervisor().length()<10)
            {
                this->error = "Supervisor field must be atleast 10 characters long.";
            }else if(researchPaperObj->getSponsor().length()<10)
            {
                this->error = "Sponsor field must be atleast 10 characters long.";
            }
        break;
    }
}

bool Validator::recordExists(string referenceNumber)
{
    FileModel * fileModelObj = new FileModel();
    string recordReferenceNumber = fileModelObj->getReferenceMaterialRecordFromFile(referenceNumber)->getReferenceNumber();
    bool flag = (recordReferenceNumber.compare(referenceNumber)==0);
    return flag;
}

bool Validator::checkReferenceNumber(string referenceNumber)
{
    ReferenceMaterial *refObj = new ReferenceMaterial();
    int type = refObj->getMaterialTypeFromReferenceNumber(referenceNumber);
    return (type==TYPE_TEXTBOOK||type==TYPE_MAGAZINE||type==TYPE_RESEARCHPAPER) ? true : false;
}
