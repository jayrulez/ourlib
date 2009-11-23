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
            TextBook *textBookObj = new TextBook();
            fileObj.open(referenceMaterialObj->getDataFileName(),ios::in | ios::binary);
            if(fileObj.is_open())
            {
                fileObj.seekg((recordPosition) * sizeof(TextBook));
                fileObj.read(reinterpret_cast < char * > (textBookObj),sizeof(TextBook));
            }
            referenceMaterialObj = textBookObj;
        break;
        case TYPE_MAGAZINE:
            Magazine *magazineObj = new Magazine();
            fileObj.open(referenceMaterialObj->getDataFileName(),ios::in | ios::binary);

            if(fileObj.is_open())
            {
                fileObj.seekg((recordPosition) * sizeof(Magazine));
                fileObj.read(reinterpret_cast < char * > (magazineObj),sizeof(Magazine));
            }
            referenceMaterialObj = magazineObj;
        break;
        case TYPE_RESEARCHPAPER:
            ResearchPaper *researchPaperObj = new ResearchPaper();
            fileObj.open(referenceMaterialObj->getDataFileName(),ios::in | ios::binary);

            if(fileObj.is_open())
            {
                fileObj.seekg((recordPosition) * sizeof(ResearchPaper));
                fileObj.read(reinterpret_cast < char * > (researchPaperObj),sizeof(ResearchPaper));
            }
            referenceMaterialObj = researchPaperObj;
        break;
    }
    fileObj.close();
    return referenceMaterialObj;
}
