#include "console.h"
#include <windows.h>
console::console()
{
    colour=0;
    v_size=0;
    h_size=0;
}
console::~console()
{
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
