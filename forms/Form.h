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
#ifndef _LOAN_H
#include "../Loan.h"
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
        string referenceNumber;
        int formType;
		Loan *loan;
    public:
        Form();
        virtual ~Form();
        virtual void show();
        virtual void browseForm();
		virtual void browseEditForm(string);
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
		void setReferenceNumber(string);
		string getReferenceNumber() const;
		virtual void editSave();
		Loan* getLoan();
		void setLoan(Loan*);
};
#endif // FORM_H
