#include <iostream>
#include <conio.h>
#include "utility.h"
#include "ui.h"

using namespace std;

/** ÃÜÂëÊäÈë */
void UI::GetPass(char password[])
{
#define ENTER_KEY 13
#define BACKSPACE_KEY 8

	char ch;
	int pos = 0;

	while (true) {
		ch = _getch();

		if (pos >= PwdBuffSize) { 
			cout << '\a'; 
			continue; 
		}

		if (ch == ENTER_KEY) {
			password[pos] = '\0';
			cout << endl;

			break;
		} else if (ch == BACKSPACE_KEY) {
			if (pos > 0) {
				cout << "\b \b";
				pos--;
			}
		} else {
			cout << "*";
			password[pos++] = ch;
		}
	}
}

int UI::GetNumber()
{
	const int BuffSize = 1024;
	char cmd[BuffSize];
	while (true) {
		cin.getline(cmd, BuffSize);

		bool flag = *cmd != '\0';
		for (char *pch = cmd; *pch != '\0' && flag; pch++)
			flag = *pch >= '0' && *pch <= '9';

		if (flag)
			return atoi(cmd);
	}
}

double UI::GetFloatValue()
{
	const int BuffSize = 1024;
	char cmd[BuffSize];

	while (true) {
		cin.getline(cmd, BuffSize);

		bool flag = *cmd != '\0';
		for (char *pch = cmd; *pch != '\0' && flag; pch++)
			flag = (*pch >= '0' && *pch <= '9') || *pch == '.';

		if (flag)
			return atof(cmd);
	}
}

double UI::GetCashValue()
{
	const int BuffSize = 1024;
	char cmd[BuffSize];

	while (true) {
		cin.getline(cmd, BuffSize);

		bool IsCharValid = *cmd != '\0';
		char *pch = cmd;
		for (; *pch != '\0' && IsCharValid; pch++)
			IsCharValid = (*pch >= '0' && *pch <= '9') || *pch == '.';

		pch = cmd;
		char *pDot = NULL;
		int nDots = 0;
		for (; *pch != '\0'; pch++) {
			if (*pch == '.') {
				pDot = pch;
				nDots++;
			}
		}

		bool IsValueValid = pDot != NULL ?  
			nDots == 1 && pch - pDot <=3 : true;

		if (IsCharValid && IsValueValid)
			return atof(cmd);
	}
}

char UI::GetKey()
{
	const int BuffSize = 1024;
	char cmd[BuffSize];
	while (true) {
		cin.getline(cmd, BuffSize);
		if (cmd[1] == '\0')
			break;
	}
	
	return cmd[0];
}

void UI::pause()
{
	system("pause");
}