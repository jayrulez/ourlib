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
#ifndef _CONTROLLER_H
#include "Controller.h"
#endif


using namespace std;

/*
*
*/
Controller::Controller()
{
}

MenuBuilder* Controller::init()
{
	this->menuBuilderObj = new MenuBuilder();
	return this->menuBuilderObj;
}

/*
*
*/
Controller::~Controller()
{
}

