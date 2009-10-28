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
* Create Application Object
* @Return @method Application::run
*/
int main()
{
    Application *app = new Application();
    return app->run();
}
