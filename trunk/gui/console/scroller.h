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
    frame frame_scroller;
    console console_scroller;
public:
    scroller();
    ~scroller();
    bool setScroller(int,int,int);
    void scroll();
    void killScroll();
};
#endif // SCROLLER_H
