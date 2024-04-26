#ifndef _UI_H
#define _UI_H

class UI
{
public:
	static void GetPass(char password[]);
	static int GetNumber();
	static double GetFloatValue();
	static double GetCashValue();
	static char GetKey();
	static void pause();
};

#endif // _UI_H
