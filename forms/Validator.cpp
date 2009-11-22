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
    //if(recordId > 0) recordId -= 1;
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
               /* fileObj.read(reinterpret_cast < char * > (&textBookObj),sizeof(TextBook));
                while(!fileObj.eof())
                {
                    if(textBookObj.getReferenceNumber().compare(referenceNumber)==0)
                    {
                        cout << "Ref. No.: " << textBookObj.getReferenceNumber() << endl;
                        cout << "Debug tellg: " << fileObj.tellg() <<endl;
                    }
                    fileObj.read(reinterpret_cast < char * > (&textBookObj),sizeof(TextBook));
                }*/
                cout << "Debug recordId: " << recordId <<endl;
                fileObj.seekg((recordId-1) * sizeof(TextBook), ios::beg);
                cout << "Debug tellg: " << fileObj.tellg() <<endl;
                fileObj.read(reinterpret_cast < char * > (&textBookObj),sizeof(TextBook));
                cout << "Debug: Did i get here?" << endl;
                cout << "Debug textBookObj.getReferenceNumber(): " << textBookObj.getReferenceNumber() << endl;
                if(textBookObj.getReferenceNumber().compare(referenceNumber)==0)
                {
                    cout << "Debug: So i do exist" << endl;
                    exists = true;
                }else{
                    cout << "Debug: Are you saying i do not exist?" << endl;
                }
                fileObj.close();
            }
        break;
        /*case TYPE_MAGAZINE:
        break;
        case TYPE_RESEARCHPAPER:
        break;*/
    }
    return exists;
}
