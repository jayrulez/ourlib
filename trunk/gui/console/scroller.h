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
public:
    scroller();
    ~scroller();
    bool setScroller(int,int,int);
    void scroll();
};
#endif // SCROLLER_H
