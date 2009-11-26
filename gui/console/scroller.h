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
#ifndef SCROLLER_H
#define SCROLLER_H
#include "frame.h"
class scroller
{
private:
    int item_code;
    int itemX;
    int itemY;
    int lenght;
    /*frame will be used to make the scroller*/
    frame frameScroller;
    console consoleScroller;
public:
    scroller();
    ~scroller();
    bool setScroller(int,int,int);
    /*used to put the scroller in motion*/
    void scroll();
    /*kill/erases the scroller's trace on the screen*/
    void killScroll();
};
#endif // SCROLLER_H
