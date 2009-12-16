NATIONAL LIBRARY

Running the program

1. A temporary blank database file is placed on the cd allowing the user to run the program from the CD. 
However, the full use and manipulation of the database file is limited because the files cannot be written to a CD-R once closed.

2. Copy the library.exe and sound folder to your desired destination on your computer.

3. Run library.exe and ENJOY!


Building the program

If you desire to build the files yourself you will need to follow these steps:
1. Ensure that you are using VC++ 2008 express edition with platform SDK installed.

2. mmsystems.h header file is used to play the sounds. To get this to compile you will have to manually link it to the project.
Go to the project settings->linker->general->additional link directories. Add the path for both "winmm.lib"(Program Files\Microsoft SDKs\Windows\v6.0A\Lib) and "mmsystems.h"(Program Files\Microsoft SDKs\Windows\v6.0A\Include). 
Now go to settings->linker->input->additional dependencies. add "winmm.lib".

If you have any problem building the project, please contact us at:
waprave@gmail.com, portmore_representa@yahoo.com, duberryd@candw.ms or xavierlowe78@yahoo.com.



