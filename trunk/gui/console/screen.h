#ifndef SCREEN_H
#define SCREEN_H
#include "console.h"

#include <string>
using namespace std;

class screen
{
private:
	string name;

public:
	screen(string);
	~screen();
	void setScreenName(string);
	string getScreenName();
};
#endif
