/*
 @Group: BSC2D
 @Group Members:
	 <ul>
		<li>Robert Campbell: 0701334</li>
		<li>Audley Gordon: 0802218</li>
		<li>Dale McFarlane: 0801042</li>
		<li>Dyonne Duberry: 0802189</li>
		<li>Xavier Lowe: </li>
	 </ul>
 @
*/
#include <iostream>
#include "Application.h"
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
    return 0;
}

/*
* Starts the application
* Application runs while @attribute Application::state is true
* @Return @method Application::terminate
*/
int Application::run()
{
	while(this->getState())
	{
        for(int x=0;x<10;x++)
        {
            cout << x << "\n";
        }
        this->setState(false);
	}
	return this->terminate();
}
