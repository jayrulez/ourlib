#ifndef _FORMBUILDER_H
#include "FormBuilder.h"
#endif

#include "windows.h"
#include <iostream>
#include <cctype>
#include <string>

#define NUMERIC 1
#define ALPHABETICAL 2
#define ALPHANUMERIC 3

FormBuilder::FormBuilder()
{

}

FormBuilder::~FormBuilder()
{

}

string FormBuilder::FormInput (int type,string input,int length)
{
	HANDLE hIn;
	DWORD AmtRead;
	INPUT_RECORD InputRec;
	 //string input;
	int position=input.length();
	bool read=false;
	hIn = GetStdHandle(STD_INPUT_HANDLE);
	while(!read)
	{
		ReadConsoleInput(hIn,&InputRec,1,&AmtRead);
		switch(InputRec.EventType)
		{
			case KEY_EVENT:
				if(InputRec.Event.KeyEvent.bKeyDown)
				{
				    if(input.length()<(unsigned)length)
				    {
                        switch(type)
                        {
                            case NUMERIC:
                                if(isdigit(InputRec.Event.KeyEvent.uChar.AsciiChar))
                                {
                                    input+=InputRec.Event.KeyEvent.uChar.AsciiChar;
                                    cout<<InputRec.Event.KeyEvent.uChar.AsciiChar;
                                    position+=1;
                                }
                            break;
                            case ALPHABETICAL:
                                if(isalpha(InputRec.Event.KeyEvent.uChar.AsciiChar))
                                {
                                    input+=InputRec.Event.KeyEvent.uChar.AsciiChar;
                                    cout<<InputRec.Event.KeyEvent.uChar.AsciiChar;
                                    position+=1;
                                }
                            break;
                        }
				    }
                    switch(InputRec.Event.KeyEvent.wVirtualKeyCode)
                    {
                        case VK_UP:
                        case VK_RETURN:
                        case VK_TAB:
                        case VK_DOWN:
                            return input;
                        break;
                        case VK_RIGHT:
                        break;
                        case VK_LEFT:
                            if(position>0)
                            {
                                cout<<"\b\b";
                                position-=1;
                            }
                        break;
                        case VK_BACK:
                            if(input.length()>0)
                            {
                                cout<<"\b \b";
                                input.erase(position);
                                position-=1;
                            }
                        break;
                    }
                }
			break;
		}
	}
	return input;
}



