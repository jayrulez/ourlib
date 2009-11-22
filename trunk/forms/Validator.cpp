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

#include <fstream>

Validator::Validator() {}
Validator::~Validator() {}

bool Validator::recordExists(string referenceNumber)
{
    ReferenceMaterial referenceMaterial;
    int recordId = referenceMaterial.getIdFromReferenceNumber(referenceNumber);
    if(recordId > 0) recordId -= 1;
    int referenceType = referenceMaterial.getMaterialTypeFromReferenceNumber(referenceNumber);
    ifstream fileObj;
    bool exists = false;

    switch(referenceType)
    {
        case TYPE_TEXTBOOK:
            TextBook textBookObj;
            fileObj.open(textBookObj.getDataFileName(),ios::in | ios::binary);
            if(fileObj.is_open())
            {
                cout << "Debug recordId: " << recordId <<endl;
                fileObj.seekg(recordId * sizeof(TextBook));
                cout << "Debug: I am here"<<endl;
                fileObj.read(reinterpret_cast < char * > (&textBookObj),sizeof(TextBook));
                fileObj.close();
                cout << "Debug: Did i get here?" << endl;
                cout << "Debug textBookObj.getReferenceNumber(): " << textBookObj.getReferenceNumber() << endl;
                if(referenceNumber.compare(textBookObj.getReferenceNumber())==0)
                {
                    exists = true;
                    cout << "Debug: So i do exist" << endl;
                    return true;
                }
                cout << "Debug: Are you saying i do not exist?" << endl;
            }
        break;
        /*case TYPE_MAGAZINE:
        break;
        case TYPE_RESEARCHPAPER:
        break;*/
    }
    return false;
}
