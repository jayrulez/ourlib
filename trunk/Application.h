#ifndef _APPLICATION_H
#define _APPLICATION_H

class Application
{
private:
	bool state = true;
	bool reRun = false;
public:
	Application();
	~Application();
	void setState(bool = true);
	bool getState();
	void process();
	int terminate();
	int run();
};
#endif
