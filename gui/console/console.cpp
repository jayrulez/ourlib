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
/*
* necessary for the GetConsoleWindow() function to work!
* it basically says that you are running this
* program on Windows 2000 or higher
*/
#include<iostream>
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include "console.h"
console::console()
{
    colour=0;
    v_size=0;
    h_size=0;
}
console::~console()
{
}
void console::setConsoleSize(int x,int y)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //stores the console's current dimensions
    //MoveWindow(window_handle, x, y, width, height, redraw_window);
    MoveWindow(console, r.left, r.top, y, x, TRUE);
}
void console::xyCoord(int x,int y)
{
    /*gets the console output handle ans stores it*/
    hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    /*specifing the cursor coordinates*/
    Position.X=x;
    Position.Y=y;
    /*sets the cursor position to that specified above*/
    SetConsoleCursorPosition(hOut,Position);
}
void console::setCursor(bool visible,int size)
{
    /*gets the console output handle ans stores it*/
    hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    /*sets the visibilty of the cursor (visible or hidden)*/
    cursor_info.bVisible=visible;
    /*sets the size of the cursor*/
    cursor_info.dwSize=size;
    SetConsoleCursorInfo(hOut,&cursor_info);
}
void console::setColour(int c)
{
    /*gets the console output handle ans stores it*/
    hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    /*sets the colour of the console text*/
    SetConsoleTextAttribute(hOut,c);
    colour=c;
}

void console::clearScreen()
{
  DWORD n;      /* Number of characters written */
  DWORD size;         /* number of visible characters */
  COORD coord = {0};    /* Top left screen position */
  CONSOLE_SCREEN_BUFFER_INFO csbi;

  /* Get a handle to the console */
  HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );

  GetConsoleScreenBufferInfo ( h, &csbi );

  /* Find the number of characters to overwrite */
  size = csbi.dwSize.X * csbi.dwSize.Y;

  /* Overwrite the screen buffer with whitespace */
  FillConsoleOutputCharacter ( h, TEXT ( ' ' ), size, coord, &n );
  GetConsoleScreenBufferInfo ( h, &csbi );
  FillConsoleOutputAttribute ( h, csbi.wAttributes, size, coord, &n );

  /* Reset the cursor to the top left position */
  SetConsoleCursorPosition ( h, coord );
}
