#pragma once
#include <string>
using namespace std;

//����������<0,9>
char GetDigit();
//������Сд��ĸ<a,z>
char GetLower();
//�����ô�д��ĸ<A,Z>
char GetUpper();
//��������ַ���
void ProRandomStringData(string* a, int n);