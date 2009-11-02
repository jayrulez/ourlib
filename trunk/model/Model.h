#ifndef _MODEL_H
#define _MODEL_H
#ifndef _MODEL_DRIVER
#define _MODEL_DRIVER "file"
#endif
#ifndef _FILE_H
#include "file/File.h"
#endif

class Model:public File
{
private:
	char* driver;
public:
	Model();
	~Model();
};
#endif
