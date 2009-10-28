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

/*
* Starts the application
* Application runs while @attribute Application::state is true
* @Return @method Application::terminate
*/
int Application::run()
{
	while(this->getState()==true)
	{
        for(int x=0;x<10;x++)
        {
            cout << x << "\n";
        }
        //this->setState(false);//break;
	}
	return this->terminate();
}
