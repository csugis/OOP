#include<iostream>
#include"ProRandomStringData.h"
#include <random>
#include <time.h>
using namespace std;

//����������<0,9>
char GetDigit()
{
	return static_cast<char>('0' + rand() % ('9' - '0' + 1));
}
//������Сд��ĸ<a,z>
char GetLower()
{
	return static_cast<char>('a' + rand() % ('z' - 'a' + 1));
}
//�����ô�д��ĸ<A,Z>
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
	cout << "\t||-----------------------��������"<<n<<"���������" << endl;
	//�����������ַ���
	char ch;	
	for (int i = 0; i < n; i++)
	{
		string str = "";
		for (int j = 0; j < 5; j++) //����5λ�ַ���
		{
			int k = rand() % 3;
			if (k == 0)     ch = GetDigit();				
			else if (k == 1)ch = GetLower();
			else			ch = GetUpper();
			str += ch;
		}
		a[i] = str;
	}
	cout << "\t||------------------------�������������-------------------------||" << endl;
	cout << "\t||---------------------------------------------------------------||" << endl;
	cout << "\t||===============================================================||" << endl;
}


