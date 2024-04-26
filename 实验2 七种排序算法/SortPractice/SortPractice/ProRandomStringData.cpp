#include<iostream>
#include"ProRandomStringData.h"
#include <random>
#include <time.h>
using namespace std;

//随机获得数字<0,9>
char GetDigit()
{
	return static_cast<char>('0' + rand() % ('9' - '0' + 1));
}
//随机获得小写字母<a,z>
char GetLower()
{
	return static_cast<char>('a' + rand() % ('z' - 'a' + 1));
}
//随机获得大写字母<A,Z>
char GetUpper()
{
	return static_cast<char>('A' + rand() % ('Z' - 'A' + 1));
}

void ProRandomStringData(string* a, int n)
{	
	/////////////////////////////////////////////////////////////////////////////////////
	cout << endl << endl;
	cout << "\t||===============================================================||" << endl;
	cout << "\t||---------------------------------------------------------------||" << endl;
	cout << "\t||-----------------------正在生成"<<n<<"个随机数！" << endl;
	//产生多个随机字符串
	char ch;	
	for (int i = 0; i < n; i++)
	{
		string str = "";
		for (int j = 0; j < 5; j++) //生成5位字符串
		{
			int k = rand() % 3;
			if (k == 0)     ch = GetDigit();				
			else if (k == 1)ch = GetLower();
			else			ch = GetUpper();
			str += ch;
		}
		a[i] = str;
	}
	cout << "\t||------------------------生成随机数结束-------------------------||" << endl;
	cout << "\t||---------------------------------------------------------------||" << endl;
	cout << "\t||===============================================================||" << endl;
}


