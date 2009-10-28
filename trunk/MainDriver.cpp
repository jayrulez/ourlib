/*
 @Group: BSC2D
 @Group Members:
	 <ul>
		<li>Robert Campbell: 0701334</li>
		<li>Audley Gordon: 0802218</li>
		<li>Dale McFarlane: 0801042</li>
		<li>Dyonne Duberry: 0802189</li>
		<li>Xavier Lowe: </li>
	 </ul>
 @
*/
#include "install/Installer.h"
#include "Application.h"
/*
#include <mysql.h>
#include "Member.h"
#include "Loan.h"
#include "DateTime.h"
#include "ReferenceMaterial.h"
#include "ResearchPaper.h"
#include "Magazine.h"
#include "TextBook.h"
*/
using namespace std;

/*
* The entry point for the application.
* Creates Installer object
* Check if Application is installed, on false, call @method Installer::invoke
* Create Application Object
* @Return @method Application::run
*/
int main()
{
    /*
    Installer *ins = new Installer();
    if(!ins->checkInstalled()==true)
    {
        ins->invoke();
    }
    */
    Application *app = new Application();
    return app->run();
}
