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
    hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    Position.X=x;
    Position.Y=y;
    SetConsoleCursorPosition(hOut,Position);
}
void console::setCursor(bool visible,int size)
{
    hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    cursor_info.bVisible=visible;
    cursor_info.dwSize=size;
    SetConsoleCursorInfo(hOut,&cursor_info);
}
void console::setColour(int c)
{
    hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hOut,c);
    colour=c;
}

void console::clrscr()
{
  DWORD n;                         /* Number of characters written */
  DWORD size;                      /* number of visible characters */
  COORD coord = {0};               /* Top left screen position */
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
