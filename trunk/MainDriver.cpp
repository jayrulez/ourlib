#include "install/Installer.h"
#include "Application.h"

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
