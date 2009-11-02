#ifndef _APPLICATION_H
#define _APPLICATION_H
#ifndef ITEM_H
#include "gui/console/item.h"
#endif
#ifndef MEDIA_H
#include "gui/console/media.h"
#endif
#ifndef _APPLICATIONEXCEPTION_H
#include "ApplicationException.h"
#endif

class Application
{
private:
	bool state;
	bool reRun;
	ApplicationException *error;
public:
	Application();
	~Application();
	//ApplicationException *error;
	void setState(bool = true);
	bool getState();
	void process();
	void welcome();
	void main();
	item* mainMenu();
	void menuBrowserOperator(item*,media*);
	void mainMenuShow(item*);
	int mainMenuRangeY(item*,int,int);
	int mainMenuRangeX(item*,int,int);
	int terminate();
	int run();
};
#endif
