#ifndef _APPLICATION_H
#define _APPLICATION_H
#ifndef ITEM_H
#include "gui/console/item.h"
#endif
#ifndef MEDIA_H
#include "gui/console/media.h"
#endif
#ifndef SCROLLER_H
#include "gui/console/scroller.h"
#endif
#ifndef _APPLICATIONEXCEPTION_H
#include "ApplicationException.h"
#endif

class Application
{
private:
	bool state;
	bool reRun;
public:
	Application();
	~Application();
	void setState(bool = true);
	bool getState();
	void process();
	void welcome();
	void main();
	item* mainMenu();
	int menuBrowserOperator(item*);
	int MenuProcessing(unsigned int,item*,int*,scroller*);
	void mainMenuShow(item*);
	int mainMenuRangeY(item*,int,int);
	int mainMenuRangeX(item*,int,int);
	int terminate();
	int run();
};
#endif
