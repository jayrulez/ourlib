
#include "windows.h"
#include <iostream>
#include <cctype>
#include <string>
#include "FormInputBuilder.h"

using namespace std;

FormInputBuilder::FormInputBuilder()
{
}
FormInputBuilder::~FormInputBuilder()
{
}

int FormInputBuilder::FormInput (int type,int SpaceType,string *input,int length)
{
	HANDLE hIn;
	DWORD AmtRead;
	INPUT_RECORD InputRec;
	int position=input->length();
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
				    if(input->length()<(unsigned)length)
				    {
                        switch(type)
                        {
                            case NUMERIC:
                                if(isdigit(InputRec.Event.KeyEvent.uChar.AsciiChar)||
                                ispunct(InputRec.Event.KeyEvent.uChar.AsciiChar))
                                {
                                    (*input)+=InputRec.Event.KeyEvent.uChar.AsciiChar;
                                    cout<<InputRec.Event.KeyEvent.uChar.AsciiChar;
                                    position+=1;
                                }
                             break;
                            case ALPHABETICAL:
                                if(isalpha(InputRec.Event.KeyEvent.uChar.AsciiChar)||
                                ispunct(InputRec.Event.KeyEvent.uChar.AsciiChar))
                                {
                                    (*input)+=InputRec.Event.KeyEvent.uChar.AsciiChar;
                                    cout<<InputRec.Event.KeyEvent.uChar.AsciiChar;
                                    position+=1;
                                }
                            break;
                            case ALPHANUMERIC:
                                if(isalnum(InputRec.Event.KeyEvent.uChar.AsciiChar)||
                                ispunct(InputRec.Event.KeyEvent.uChar.AsciiChar))
                                {
                                    (*input)+=InputRec.Event.KeyEvent.uChar.AsciiChar;
                                    cout<<InputRec.Event.KeyEvent.uChar.AsciiChar;
                                    position+=1;
                                }
                            break;
                        }
				    }
                    switch(InputRec.Event.KeyEvent.wVirtualKeyCode)
                    {
                        case VK_RETURN:
                        case VK_DOWN:
                        case VK_UP:
                        case VK_TAB:
                            return InputRec.Event.KeyEvent.wVirtualKeyCode;
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
                            if(input->length()>0)
                            {
                                cout<<"\b \b";
                                input->erase(position);
                                position-=1;
                            }
                        break;
                        case VK_SPACE:
                            switch(SpaceType)
                            {
                                case SPACING:
                                    (*input)+=" ";
                                    position+=1;
                                    cout<<" ";
                                break;
                                case NOSPACING:
                                break;
                            }
                        break;
                    }
                }
			break;
		}
	}
	return InputRec.Event.KeyEvent.wVirtualKeyCode;
}



