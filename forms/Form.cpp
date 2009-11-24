#ifndef FORM_H
#include "./Form.h"
#endif
#ifndef _REFERENCEMATERIAL_H
#include "../ReferenceMaterial.h"
#endif


Form::Form()
{
    this->state = 0;
    this->model = new ReferenceMaterial();
}

Form::~Form()
{
}

void Form::show() {}
void Form::browseForm() {}
void Form::save() {}

void Form::setState(int state)
{
    this->state = state;
}

int Form::getState() const
{
    return this->state;
}

void Form::setError(string error)
{
    this->error = error;
}

string Form::getError() const
{
    return this->error;
}

bool Form::hasError() const
{
    return (this->error).length()>0;
}

void Form::setFormType(int type)
{
    this->formType = type;
}

int Form::getFormType() const
{
    return this->formType;
}

void Form::setReferenceMaterialPtr(ReferenceMaterial* refObj)
{
    this->referenceMaterialPtr = refObj;
}

void Form::setModel(ReferenceMaterial *referenceMaterialObj)
{
    this->model = referenceMaterialObj;
}

ReferenceMaterial* Form::getModel()
{
    return this->model;
}
