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
