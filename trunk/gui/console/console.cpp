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
