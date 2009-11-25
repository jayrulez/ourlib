#ifndef FORMINPUTBUILDER_H
#define FORMINPUTBUILDER_H

#ifndef CONSOLE_H
#include "..\gui\console\console.h"
#endif

#define NUMERIC 1
#define ALPHABETICAL 2
#define ALPHANUMERIC 3
#define PUNCTUATION 4
#define DATE 5
#define SPACING 1
#define NOSPACING 2

#include <string>
using namespace std;

class FormInputBuilder
{
private:
        console consoleObj;
public:
    FormInputBuilder();
    ~FormInputBuilder();
    int FormInput(int,int,string*,int,int[][3],int,bool);
};

#endif // FORMINPUTBUILDER_H
