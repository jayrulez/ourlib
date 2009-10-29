#include "Application.h"
//#include "install/Installer.h"

/*
* The entry point for the application.
* Create Application Object
* @Return @method Application::run()
*/
int main()
{
	/*
	Installer *ins = new Installer();
	if(ins->checkInstall()==false)
		ins->invoke();
	*/
	Application *app = new Application();
	return app->run();
}
