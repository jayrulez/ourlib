#include <iostream>
#include "line.h"
#include "console.h"
#include "frame.h"

using namespace std;

frame::frame(int h1,int h2,int v1,int v2):Dx1y1Char(201),Dx1y2Char(200),Dx2y1Char(187),Dx2y2Char(188),
Sx1y1Char(218),Sx1y2Char(192),Sx2y1Char(191),Sx2y2Char(217)
{
    if(h1>=0&&h2>=0&&v1>=0&&v2>=0){
        x1=h1;
        x2=h2;
        y1=v1;
        y2=v2;
    }
    else{
        cout<<"frame construction failed!"<<endl;
    }
}
frame::~frame()
{
}
bool frame::setFrame(int h1,int h2,int v1,int v2)
{
        if(h1>=0&&h2>=0&&v1>=0&&v2>=0){
        x1=h1;
        x2=h2;
        y1=v1;
        y2=v2;
        return true;
    }
    cout<<"failed to set frame"<<endl;
    return false;
}
void frame::dFraming()
{
    frame_line.setVCoord(y1,y2,x1);
    frame_line.vDLine();
    frame_line.setVCoord(y1,y2,x2);
    frame_line.vDLine();
    frame_line.setHCoord(x1,x2,y1);
    frame_line.hDLine();
    frame_line.setHCoord(x1,x2,y2);
    frame_line.hDLine();

    frame_console.xyCoord(x1,y1);
    cout<<(unsigned char)Dx1y1Char;
    frame_console.xyCoord(x2,y1);
    cout<<(unsigned char)Dx2y1Char;
    frame_console.xyCoord(x1,y2);
    cout<<(unsigned char)Dx1y2Char;
    frame_console.xyCoord(x2,y2);
    cout<<(unsigned char)Dx2y2Char;
}
void frame::sFraming()
{
    frame_line.setVCoord(y1,y2,x1);
    frame_line.vSLine();
    frame_line.setVCoord(y1,y2,x2);
    frame_line.vSLine();
    frame_line.setHCoord(x1,x2,y1);
    frame_line.hSLine();
    frame_line.setHCoord(x1,x2,y2);
    frame_line.hSLine();

    frame_console.xyCoord(x1,y1);
    cout<<(unsigned char)Sx1y1Char;
    frame_console.xyCoord(x2,y1);
    cout<<(unsigned char)Sx2y1Char;
    frame_console.xyCoord(x1,y2);
    cout<<(unsigned char)Sx1y2Char;
    frame_console.xyCoord(x2,y2);
    cout<<(unsigned char)Sx2y2Char;
}
