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
    setState();
}

Application::~Application() {}

void Application::setState(bool _state)
{
    state = _state;
}

bool Application::getState()
{
   return state;
}

int Application::run() {
	while(getState()==true)
	{
        for(int x=0;x<10;x++)
        {
            cout << x << "\n";
        }
        setState(false);
	}
	return 0;
}
