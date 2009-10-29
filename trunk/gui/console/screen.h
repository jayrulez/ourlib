#ifndef SCREEN_H
#define SCREEN_H
#include "console.h"
class screen
{
private:
	char* name;

public:
	screen(char*);
	~screen();
	void setScreenName(char*);
	char* getScreenName();
};
#endif
