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
#include "console.h"
#include "line.h"
using namespace std;
line::line():
    xDChar(205),
    yDChar(186),
    xSChar(196),
    ySChar(179)
{
    x1=0;
    x2=0;
    xy=0;
    y1=0;
    y2=0;
    yx=0;
}
line::line(int h1,int h2,int hv,int v1,int v2,int vh):
    xDChar(205),
    yDChar(186),
    xSChar(196),
    ySChar(179)
{
    if(h1>=0&&h2>=0&&hv>=0&&v1>=0&&v2>=0&&vh>=0){
        x1=h1;
        x2=h2;
        xy=hv;
        y1=v1;
        y2=v2;
        yx=vh;
    }
    else{
        cout<<"Failed to construct a Line"<<endl;
    }
}
line::~line()
{
}
bool line::setHCoord(int h1, int h2, int hv)
{
    if(h1>=0&&h2>=0&&hv>=0){
        x1=h1;
        x2=h2;
        xy=hv;
        return true;
    }
    cout<<"failed to set coordinates"<<endl;
    return false;
}
bool line::setVCoord(int v1, int v2, int vh)
{
    if(v1>=0&&v2>=0&&vh>=0){
        y1=v1;
        y2=v2;
        yx=vh;
        return true;
    }
    return false;
}
void line::vDLine()
{
    int a;
    for(a=y1;a<=y2;a++)
    {
        console_line.xyCoord(yx,a);
        cout<<(unsigned char)yDChar;
    }
}
void line::hDLine()
{
    int a;
    for(a=x1;a<=x2;a++)
    {
        console_line.xyCoord(a,xy);
        cout<<(unsigned char)xDChar;
    }
}
void line::vSLine()
{
    int a;
    for(a=y1;a<=y2;a++)
    {
        console_line.xyCoord(yx,a);
        cout<<(unsigned char)ySChar;
    }
}
void line::hSLine()
{
    int a;
    for(a=x1;a<=x2;a++)
    {
        console_line.xyCoord(a,xy);
        cout<<(unsigned char)xSChar;
    }
}
