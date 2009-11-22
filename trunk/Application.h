#ifndef _APPLICATION_H
#define _APPLICATION_H
#ifndef _CONTROLLER_H
#include "Controller.h"
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
	void buildDataFiles();
	Controller* controllerObj;
	void setState(bool = true);
	bool getState();
	void process();
	void welcome();
	void main();
	int terminate();
	int run();
};
#endif
