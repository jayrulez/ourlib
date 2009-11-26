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
#ifndef _MAGAZINE_H
#define _MAGAZINE_H
#ifndef _REFERENCEMATERIAL_H
#include "Referencematerial.h"
#endif
#ifndef _DATE_H
#include "Date.h"
#endif

#include "gui\console\console.h"
#include "gui\console\frame.h"
#include <string>
using namespace std;

class Magazine:public ReferenceMaterial
{
private:
	string volume;
	string issueTopic;
	string issueDate;
	console consoleObj;
	frame frameObj;

public:
	Magazine();
	~Magazine();
	Magazine(string,string,string,string,string,string);
	void setVolume(string);
	void setIssueTopic(string);
	void setIssueDate(string);
	string getVolume() const;
	string getIssueTopic() const;
	string getIssueDate() const;
	void showReferenceMaterial(int,int);
};
#endif
