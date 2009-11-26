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
#ifndef CONSOLE_H
#define CONSOLE_H
#include <windows.h>
class console
{
    private:
        unsigned int colour;
        int h_size;
        int v_size;
        int consoleX;
        int consoleY;
        /*an output handle for manipulating
        the console*/
        HANDLE hOut;
        /*a structure containing the cursor's
        position information*/
        COORD Position;
        CONSOLE_CURSOR_INFO cursor_info;
    public:
        console();
        ~console();
        void setConsoleSize(int,int);
        void clearScreen();
        void setColour(int);
        void xyCoord(int, int);
        void setCursor(bool,int);
};
#endif // WINDOW_H
