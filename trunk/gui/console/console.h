#ifndef CONSOLE_H
#define CONSOLE_H
#include <windows.h>
class console
{
    private:
        unsigned int colour;
        int h_size;
        int v_size;
        HANDLE hOut;
        COORD Position;
        CONSOLE_CURSOR_INFO cursor_info;
    public:
        console();
        ~console();
        void clrscr();
        void setColour(int);
        void xyCoord(int, int);
        void setCursor(bool,int);
};
#endif // WINDOW_H
