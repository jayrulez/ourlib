/*
@Group: BSC2D
@Group Members:
	<ul>
		<li>Robert Campbell: 0701334</li>
		<li>Audley Gordon: 0802218</li>
		<li>Dale McFarlane: 0801042</li>
		<li>Dyonne Duberry: 0802189</li>
		<li>Xavier Lowe: 0802488</li>
	</ul>
@
*/
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
