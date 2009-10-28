#include <iostream>
#ifndef _APPLICATION_H
#include "Application.h"
#endif

using namespace std;

/*
* Sets @attribute Application::state to true upon instantiation
*/
Application::Application() {
    this->setState();
}

/*
* Destroys the Application Object
*/
Application::~Application() {}

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
    //delete this;
    return 0;
}

void Application::process()
{
    for(int x=0;x<10;x++)
    {
        cout << x << "\n";
    }
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
        * Sets @attribute Application::state to false
        * Stops the loop from running again in order
        * for method Application::terminate() to be returned
        * after the loop
        */
        this->setState(false);
	}
	return this->terminate();
}
