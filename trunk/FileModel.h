#ifndef _FILEMODEL_H
#define _FILEMODEL_H
#ifndef _REFERENCEMATERIAL_H
#include "ReferenceMaterial.h"
#endif

class FileModel
{
public:
    FileModel();
    ~FileModel();
	ReferenceMaterial* getReferenceMaterialRecordFromFile(string);
};

#endif
