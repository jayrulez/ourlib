#ifndef FORM_H
#define FORM_H

class Form
{
    public:
        Form();
        virtual ~Form();
        virtual void show();
        virtual void browseForm();
        virtual void save();
};
#endif // FORM_H
