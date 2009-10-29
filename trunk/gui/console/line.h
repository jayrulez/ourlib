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
        line(int x1=0,int x2=0,int xy=0,int y1=0,int y2=0,int yx=0);
        ~line();
        bool setHCoord(int,int,int);
        bool setVCoord(int,int,int);
        void hDLine();
        void vDLine();
        void hSLine();
        void vSLine();

};
#endif // LINE_H
