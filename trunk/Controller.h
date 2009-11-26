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
#define _CONTROLLER_H
#ifndef _MENUBUILDER_H
#include "MenuBuilder.h"
#endif

class Controller
{
private:
    MenuBuilder *menuBuilderObj;
public:

	Controller();
	~Controller();
	MenuBuilder* init();
};
#endif
