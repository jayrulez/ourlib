#ifndef _RESEARCHPAPERFORM_H
#include "ResearchpaperForm.h"
#endif
#ifndef _RESEARCHPAPER_H
#include "../ResearchPaper.h"
#endif

ResearchPaperForm::ResearchPaperForm()
{

}

ResearchPaperForm::~ResearchPaperForm()
{

}

void ResearchPaperForm::show(ResearchPaper * researchPaperObj)
{
	string referenceNumber = researchPaperObj->getReferenceNumber();
	if(referenceNumber.empty())
	{
		//NEW RECORD
	}else{
		//record from file
	}
}
