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
#include "scroller.h"
#include "frame.h"
using namespace std;
scroller::scroller()
{
    item_code=0;
    itemX=0;
    itemY=0;
    lenght=0;
}
scroller::~scroller()
{
}
bool scroller::setScroller(int x,int y,int len)
{
    if(x>=0&&y>=1&&len>=0){
       itemX=x;
       itemY=y;
       lenght=len;
       return true;
    }
    cout<<"Failed! scoller is out of range."<<endl;
    return false;
}
void scroller::scroll()
{
    consoleScroller.setColour(15);
    frameScroller.setFrame(itemX-1,itemX+lenght,itemY-1,itemY+1,false);
    frameScroller.sFraming();
}
void scroller::killScroll()
{
    consoleScroller.setColour(0);
    frameScroller.setFrame(itemX-1,itemX+lenght,itemY-1,itemY+1,false);
    frameScroller.sFraming();
    consoleScroller.setColour(15);
}
