
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

int FormInputBuilder::FormInput (int type,int SpaceType,string *input,int length,int coord[][3],int FieldPosition,bool SingleInput)
{
	HANDLE hIn;
	DWORD AmtRead;
	INPUT_RECORD InputRec;
	char tempInput[length];
	int position=input->length();
	bool read=false;
	hIn = GetStdHandle(STD_INPUT_HANDLE);
	consoleObj.setCursor(true,3);
	strcpy(tempInput,input->c_str());
	//tempInput = input->c_str();
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
                                if(isdigit(InputRec.Event.KeyEvent.uChar.AsciiChar))
                                {
                                    tempInput[position]=InputRec.Event.KeyEvent.uChar.AsciiChar;
                                    cout<<InputRec.Event.KeyEvent.uChar.AsciiChar;
                                    position+=1;
                                }
                             break;
                            case ALPHABETICAL:
                                if(isalpha(InputRec.Event.KeyEvent.uChar.AsciiChar)||
                                    ispunct(InputRec.Event.KeyEvent.uChar.AsciiChar))
                                {
                                    tempInput[position]=InputRec.Event.KeyEvent.uChar.AsciiChar;
                                    cout<<InputRec.Event.KeyEvent.uChar.AsciiChar;
                                    position+=1;
                                }
                            break;
                            case ALPHANUMERIC:
                                if(isalnum(InputRec.Event.KeyEvent.uChar.AsciiChar)||
                                    ispunct(InputRec.Event.KeyEvent.uChar.AsciiChar))
                                {
                                    tempInput[position]=InputRec.Event.KeyEvent.uChar.AsciiChar;
                                    cout<<InputRec.Event.KeyEvent.uChar.AsciiChar;
                                    position+=1;
                                }
                            break;
                            case DATE:
                                if(isdigit(InputRec.Event.KeyEvent.uChar.AsciiChar)||
                                    InputRec.Event.KeyEvent.uChar.AsciiChar=='-'||
                                    InputRec.Event.KeyEvent.uChar.AsciiChar=='/')
                                {
                                    tempInput[position]=InputRec.Event.KeyEvent.uChar.AsciiChar;
                                    cout<<InputRec.Event.KeyEvent.uChar.AsciiChar;
                                    position+=1;
                                }
                            break;
                        }
                        *input=tempInput;
				    }
                    switch(InputRec.Event.KeyEvent.wVirtualKeyCode)
                    {
                        case VK_RETURN:
                            if(SingleInput)
                            {
                                consoleObj.setCursor(false,3);
                                return InputRec.Event.KeyEvent.wVirtualKeyCode;
                            }
                        case VK_DOWN:
                        case VK_UP:
                        case VK_TAB:
                            consoleObj.setCursor(false,3);
                            return InputRec.Event.KeyEvent.wVirtualKeyCode;
                        break;
                        case VK_RIGHT:
                            if(position<length&&tempInput[position]!=NULL)
                            {

                                position+=1;
                                consoleObj.xyCoord(coord[FieldPosition][0]+
                                coord[FieldPosition][2]+position,coord[FieldPosition][1]);
                            }
                        break;
                        case VK_LEFT:
                            if(position>0)
                            {
                                position-=1;
                                consoleObj.xyCoord(coord[FieldPosition][0]+
                                coord[FieldPosition][2]+position,coord[FieldPosition][1]);
                            }
                        break;
                        case VK_BACK:
                            if(input->length()>0)
                            {
                                cout<<"\b \b";
                                position-=1;
                                input->erase(position);
                                strcpy(tempInput,input->c_str());
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
                    *input=tempInput;
                }
			break;
		}
	}
	return InputRec.Event.KeyEvent.wVirtualKeyCode;
}



