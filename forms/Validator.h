/*
@Group: BSC2D
@Group Members:
	<ul>
		<li>Robert Campbell: 0701334</li>
		<li>Audley Gordon: 0802218</li>
		<li>Dale McFarlane: 0801042</li>
		<li>Dyonne Duberry: 0802189</li>
		<li>Xavier Lowe: 0802488</li>
	</ul>
@
*/
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
    bool checkDate(string);
    void formValidate(int*);
    bool checkReferenceNumber(string);
};

#endif
