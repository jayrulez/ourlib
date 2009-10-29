#include <iostream>
#include "scroller.h"
#include "frame.h"
using namespace std;
scroller::scroller()
{
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
    console_scroller.setColour(0);
    frame_scroller.setFrame(itemX-1,itemX+lenght,itemY-1,itemY+1);
    frame_scroller.sFraming();
}
void scroller::killScroll()
{
    console_scroller.setColour(0);
    frame_scroller.setFrame(itemX-1,itemX+lenght,itemY-1,itemY+1);
    frame_scroller.sFraming();
}
