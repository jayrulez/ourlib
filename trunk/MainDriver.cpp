#include "Application.h"

/*
* The entry point for the application.
* Create Application Object
* @Return @method Application::run()
*/
int main()
{
	Application *app = new Application();
	return app->run();
}
