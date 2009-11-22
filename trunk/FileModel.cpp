#ifndef _FILEMODEL_H
#include "./FileModel.h"
#endif
#ifndef _REFERENCEMATERIAL_H
#include "ReferenceMaterial.h"
#endif
#ifndef _TEXTBOOK_H
#include "TextBook.h"
#endif
#ifndef _RESEARCHPAPER_H
#include "ResearchPaper.h"
#endif
#ifndef _MAGAZINE_H
#include "Magazine.h"
#endif

FileModel::FileModel() {}
FileModel::~FileModel() {}

ReferenceMaterial* FileModel::getReferenceMaterialRecordFromFile(string referenceNumber)
{
    ReferenceMaterial * referenceMaterialObj;
    int materialType = referenceMaterialObj->getMaterialTypeFromReferenceNumber(referenceNumber);
    ifstream fileObj;
    int recordPosition = referenceMaterialObj->getIdFromReferenceNumber(referenceNumber);
    if(recordPosition>0) recordPosition -= 1;
    switch(materialType)
    {
        case TYPE_TEXTBOOK:
            referenceMaterialObj = new TextBook();
            fileObj.open(referenceMaterialObj->getDataFileName(),ios::in | ios::binary);

            if(fileObj.is_open())
            {
                fileObj.seekg((recordPosition) * sizeof(TextBook));
                fileObj.read(reinterpret_cast < char * > (referenceMaterialObj),sizeof(TextBook));
                if(referenceMaterialObj->getReferenceNumber().compare(referenceNumber)==0)
                {
                }
                fileObj.close();
            }
        break;
        case TYPE_MAGAZINE:
            referenceMaterialObj = new Magazine();
            fileObj.open(referenceMaterialObj->getDataFileName(),ios::in | ios::binary);

            if(fileObj.is_open())
            {
                fileObj.seekg((recordPosition) * sizeof(Magazine));
                fileObj.read(reinterpret_cast < char * > (referenceMaterialObj),sizeof(TextBook));
                if(referenceMaterialObj->getReferenceNumber().compare(referenceNumber)==0)
                {
                }
                fileObj.close();
            }
        break;
        case TYPE_RESEARCHPAPER:
            referenceMaterialObj = new ResearchPaper();
            fileObj.open(referenceMaterialObj->getDataFileName(),ios::in | ios::binary);

            if(fileObj.is_open())
            {
                fileObj.seekg((recordPosition) * sizeof(TextBook));
                fileObj.read(reinterpret_cast < char * > (referenceMaterialObj),sizeof(ResearchPaper));
                if(referenceMaterialObj->getReferenceNumber().compare(referenceNumber)==0)
                {
                }
                fileObj.close();
            }
        break;
    }
    return referenceMaterialObj;
}
