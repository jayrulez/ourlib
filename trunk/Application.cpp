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

#include <iostream>
#include <string>
#include "windows.h"
#include <mmsystem.h>
#ifndef _APPLICATION_H
#include "Application.h"
#endif
#ifndef _CONTROLLER_H
#include "Controller.h"
#endif
#ifndef _APPLICATIONEXCEPTION_H
#include "ApplicationException.h"
#endif
#ifndef _MENUBUILDER_H
#include "MenuBuilder.h"
#endif
#ifndef _TEXTBOOK_H
#include "TextBook.h"
#endif
#ifndef _RESEARCHPAPER_H
#include "ResearchPaper.h"
#endif
#ifndef _MAGAZINE_H
#include "Magazine.h"
#endif
#include <fstream>

using namespace std;

/*
* Sets @attribute Application::state to true upon instantiation
*/
Application::Application()
{
	this->setState(true);
	this->reRun = false;
}

/*
* Destroys the Application Object
*/
Application::~Application()
{
}

/*
* Sets the state of the application
* @param bool state
*/
void Application::setState(bool state)
{
	this->state = state;
}

/*
* Returns the state of the application
* @Return bool
*/
bool Application::getState()
{
	return this->state;
}

/*
* Terminates the application
* @Return int
*/
int Application::terminate()
{
	return 0;
}

void Application::process()
{
	SetConsoleTitle("NATIONAL LIBRARY");
	this->welcome();
	PlaySound("sound/startup.wav",NULL,SND_FILENAME|SND_ASYNC);
	PlaySound("sound/welcome.wav",NULL,SND_FILENAME|SND_ASYNC);
	this->main();
}

void Application::welcome()
{
	//cout << "Application Skeleton";
}

void Application::buildDataFiles()
{

}

void Application::main()
{
	/*
	try block and catch ApplicationException& e, e.toString();
	*/
	this->buildDataFiles(); // build data files if they do not exist
	this->controllerObj = new Controller();
	this->controllerObj->init()->callMenu(MAINMENU);
}

/*
* Starts the application
* Application runs while @attribute Application::state is true
* @Return @method Application::terminate
*/
int Application::run()
{
	while(this->getState()==true)
	{
		/*
		* The application process
		*/
		this->process();

		/*
		* If @attribute Application::state is true and
		* @attribute Application::reRun is set to false
		* Sets @attribute Application::state to false
		* Stops the loop from running again in order
		* for method Application::terminate() to be returned
		* after the loop
		*/
		if(this->getState()==true && this->reRun==false)
			this->setState(false);
	}
	return this->terminate();
}
