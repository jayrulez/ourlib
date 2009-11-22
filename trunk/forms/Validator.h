#ifndef _VALIDATOR_H
#define _VALIDATOR_H
#ifndef _REFERENCEMATERIAL_H
#include "../ReferenceMaterial.h"
#endif
#include <string>
using namespace std;
class Validator
{
private:
    string error;
public:
    bool hasError();
    string getError() const;
    Validator();
    ~Validator();
    bool recordExists(string);
    void formValidate(int *);
};

#endif
