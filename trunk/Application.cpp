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

Application::Application() {
    this->setState();
}

Application::~Application() {}

void Application::setState(bool state)
{
    this->state = state;
}

bool Application::getState()
{
   return this->state;
}

int Application::terminate()
{
    return 0;
}

int Application::run() {
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
