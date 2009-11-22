#ifndef FORM_H
#define FORM_H

class Form
{
    public:
        Form();
        virtual ~Form();
        virtual void show()=0;
        virtual void browseForm()=0;
        virtual void save() = 0;
};
#endif // FORM_H
