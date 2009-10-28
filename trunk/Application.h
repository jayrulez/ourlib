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
#ifndef _APPLICATION_H
#define _APPLICATION_H

using namespace std;

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
