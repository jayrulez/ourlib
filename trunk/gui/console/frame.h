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
    bool type;
    /*will store the extended charcter ascii value
    for the top left corner of the single frame*/
    const int Sx1y1Char;
    /*will store the extended charcter ascii value
    for the bottom right corner of the single frame*/
    const int Sx2y2Char;
    /*will store the extended charcter ascii value
    for the bottom left corner of the single frame*/
    const int Sx1y2Char;
    /*will store the extended charcter ascii value
    for the top right of the single frame*/
    const int Sx2y1Char;
    /*will store the extended charcter ascii value
    for the top left corner of the double frame*/
    const int Dx1y1Char;
    /*will store the extended charcter ascii value
    for the bottom right of the double frame*/
    const int Dx2y2Char;
    /*will store the extended charcter ascii value
    for the bottom left corner of the double frame*/
    const int Dx1y2Char;
    /*will store the extended charcter ascii value
    for the top right corner of the double frame*/
    const int Dx2y1Char;
	console frame_console;
	line frame_line;
public:
    frame();
    frame(int,int,int,int,bool);
    ~frame();
    bool setFrame(int,int,int,int,bool);
    void dFraming();
    void sFraming();
};
#endif // FRAME_H
