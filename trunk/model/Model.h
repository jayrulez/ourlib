#ifndef _MODEL_H
#define _MODEL_H
#ifndef _MODEL_DRIVER
#define _MODEL_DRIVER "file"
#endif
#ifndef _FILE_H
#include "driver/file/File.h"
#endif

#include <string>
using namespace std;

class Model:public File
{
private:
	string driver;
public:
	Model();
	~Model();
};
#endif
