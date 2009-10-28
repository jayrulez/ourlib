#ifndef _REFERENCEMATERIAL_H
#define _REFERENCEMATERIAL_H

class ReferenceMaterial
{
protected:
    char* referenceNumber;
    char* title;
    char* author;
public:
    ReferenceMaterial();
    ~ReferenceMaterial();
};
#endif
