#ifndef FRAME_H
#define FRAME_H
#include "line.h"
#include "console.h"
class frame
{
private:
    int x1;
    int x2;
    int y1;
    int y2;
    const int Sx1y1Char;
    const int Sx2y2Char;
    const int Sx1y2Char;
    const int Sx2y1Char;
    const int Dx1y1Char;
    const int Dx2y2Char;
    const int Dx1y2Char;
    const int Dx2y1Char;
	console frame_console;
	line frame_line;
public:
    frame(int h1=0,int h2=0,int v1=0,int v2=0);
    ~frame();
    bool setFrame(int,int,int,int);
    void dFraming();
    void sFraming();
};
#endif // FRAME_H
