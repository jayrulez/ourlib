#ifndef _FORMBUILDER_H
#define _FORMBUILDER_H

#include <iostream>
#include <string>

using namespace std;

class FormBuilder
{
public:
    FormBuilder();
    virtual ~FormBuilder();
    string FormInput(int,string,int);
};

#endif
