#ifndef FORMINPUTBUILDER_H
#define FORMINPUTBUILDER_H

#define NUMERIC 1
#define ALPHABETICAL 2
#define ALPHANUMERIC 3

#include <string>
using namespace std;

class FormInputBuilder
{
public:
    FormInputBuilder();
    ~FormInputBuilder();
    int FormInput(int,string,int);
    int InputInterface(int);
};

#endif // FORMINPUTBUILDER_H
