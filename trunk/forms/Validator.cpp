/*#ifndef _VALIDATOR_H
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
    int referenceType = referenceMaterial.getMaterialTypeFromReferenceNumber(referenceNumber);
    ifstream fileObj;
    switch(referenceType)
    {
        case TYPE_TEXTBOOK:
            TextBook textBookObj;
            fileObj.open(textBookObj.getDataFileName(),ios::in | ios::binary);
            if(fileObj.is_open())
            {
                fileObj.seekg(recordId * sizeof(TextBook));
                fileObj.read(reinterpret_cast < char * > (&textBookObj),sizeof(TextBook));
                if(textBookObj.getReferenceNumber().compare(referenceNumber)==0)
                    return true;
                fileObj.close();
            }
            return false;
        break;
        case TYPE_MAGAZINE:
        break;
        case TYPE_RESEARCHPAPER:
        break;
    }
    return false;
}
*/
