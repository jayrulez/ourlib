#ifndef MEMBERFORM_H_
#define MEMBERFORM_H_

class MemberForm
{
private:
    int xyReferenceNumber[3];
    int xyAuthor[3];
    int xyISBN[3];
    int xyCourse[3];
    int xyPublisher[3];
    int xyDatePublished[3];
    console consoleObj;
public:
    MemberForm();
    ~MemberForm();
	void show(MemberForm*);
};
#endif // MEMBERFORM_H_
