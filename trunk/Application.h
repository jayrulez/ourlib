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
