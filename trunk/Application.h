#ifndef _APPLICATION_H
#define _APPLICATION_H

class Application
{
private:
	bool state;
public:
    Application();
    ~Application();
    void setState(bool = true);
    bool getState();
    int terminate();
	int run();
};
#endif
