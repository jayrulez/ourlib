#ifndef FORMINPUTBUILDER_H
#define FORMINPUTBUILDER_H

#define NUMERIC 1
#define ALPHABETICAL 2
#define ALPHANUMERIC 3
#define PUNCTUATION 4
#define HIPHEN 5
#define SPACING 1
#define NOSPACING 2

#include <string>
using namespace std;

class FormInputBuilder
{
public:
    FormInputBuilder();
    ~FormInputBuilder();
    int FormInput(int,int,string*,int);
};

#endif // FORMINPUTBUILDER_H
