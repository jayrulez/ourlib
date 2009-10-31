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
    frame frameScroller;
    console consoleScroller;
public:
    scroller();
    ~scroller();
    bool setScroller(int,int,int);
    void scroll();
    void killScroll();
};
#endif // SCROLLER_H
