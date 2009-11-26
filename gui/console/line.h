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
#ifndef LINE_H
#define LINE_H
#include "console.h"

class line
{
    private:
        int x1;
        int x2;
        int xy;
        int y1;
        int y2;
        int yx;
        const int xDChar;
        const int yDChar;
        const int xSChar;
        const int ySChar;
        console console_line;
    public:
        line();
        line(int,int,int,int,int,int);
        ~line();
        bool setHCoord(int,int,int);
        bool setVCoord(int,int,int);
        /*will be used to draw a horizontal double line*/
        void hDLine();
        /*will be used to draw a veritcal double line*/
        void vDLine();
        /*will be used to draw a horizontal single line*/
        void hSLine();
        /*will be used to draw a vertical single line*/
        void vSLine();
};
#endif // LINE_H
