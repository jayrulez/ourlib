#ifndef _VALIDATOR_H
#define _VALIDATOR_H
#ifndef _REFERENCEMATERIAL_H
#include "../ReferenceMaterial.h"
#endif
#include <string>
#define INVALID_DAY
#define INVALID_MONTH
#define INVALID_YEAR

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
    int checkDate(string);
    void formValidate(int *);
};

#endif
