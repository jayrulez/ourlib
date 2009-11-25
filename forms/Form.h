#ifndef FORM_H
#define FORM_H
#ifndef _REFERENCEMATERIAL_H
#include "../ReferenceMaterial.h"
#endif
#ifndef _MEMBER_H
#include "../Member.h"
#endif
#ifndef _TEXTBOOK_H
#include "../TextBook.h"
#endif

#include <string>

using namespace std;

#define STATE_DEFAULT 0
#define STATE_SUCCESS 1
#define STATE_ERROR 2
#define STATE_FAILURE 3
#define TYPE_ADD 1
#define TYPE_EDIT 2

class Form
{
    private:
        int state;
        string error;
        ReferenceMaterial * model;
		Member * member;
        ReferenceMaterial * referenceMaterialPtr;
        int formType;
    public:
        Form();
        virtual ~Form();
        virtual void show();
        virtual void browseForm();
        virtual void save();
        void setError(string);
        void setState(int);
        int getState() const;
        string getError() const;
        bool hasError() const;
        void setModel(ReferenceMaterial*);
		void setMember(Member*);
		Member* getMember();
        void setFormType(int);
        int getFormType() const;
        ReferenceMaterial* getModel();
        virtual void setReferenceMaterialPtr(ReferenceMaterial*);
};
#endif // FORM_H
