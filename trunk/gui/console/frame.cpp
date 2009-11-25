#include <iostream>
#include "line.h"
#include "console.h"
#include "frame.h"

using namespace std;
frame::frame():
    Sx1y1Char(218),
    Sx2y2Char(217),
    Sx1y2Char(192),
    Sx2y1Char(191),
    Dx1y1Char(201),
    Dx2y2Char(188),
    Dx1y2Char(200),
    Dx2y1Char(187)
{
    x1=0;
    x2=0;
    y1=0;
    y2=0;
    type=false;
}
frame::frame(int h1,int h2,int v1,int v2,bool t):
    Sx1y1Char(218),
    Sx2y2Char(217),
    Sx1y2Char(192),
    Sx2y1Char(191),
    Dx1y1Char(201),
    Dx2y2Char(188),
    Dx1y2Char(200),
    Dx2y1Char(187)
{
    if(h1>=0&&h2>=0&&v1>=0&&v2>=0){
        x1=h1;
        x2=h2;
        y1=v1;
        y2=v2;
        type=t;
    }
    else{
        cout<<"frame construction failed!"<<endl;
    }
}
frame::~frame()
{
}
bool frame::setFrame(int h1,int h2,int v1,int v2,bool t)
{
        if(h1>=0&&h2>=0&&v1>=0&&v2>=0){
        x1=h1;
        x2=h2;
        y1=v1;
        y2=v2;
        type=t;
        return true;
    }
    cout<<"failed to set frame"<<endl;
    return false;
}
void frame::dFraming()
{
    const int leftJoint=199;
    const int rightJoint=182;
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
    if(type)
    {
        frame_line.setHCoord(x1,x2,y1+2);
        frame_line.hSLine();
        frame_console.xyCoord(x1,y1+2);
        cout<<(unsigned char)leftJoint;
        frame_console.xyCoord(x2,y1+2);
        cout<<(unsigned char)rightJoint;
    }
}
void frame::sFraming()
{
    const int leftJoint=195;
    const int rightJoint=180;
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
    if(type)
    {
        frame_line.setHCoord(x1,x2,y1+2);
        frame_line.hSLine();
        frame_console.xyCoord(x1,y1+2);
        cout<<(unsigned char)leftJoint;
        frame_console.xyCoord(x2,y1+2);
        cout<<(unsigned char)rightJoint;
    }
}
