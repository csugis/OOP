#pragma once
#include <iostream>
#include <string>
using namespace std;

enum Course { Chinese, Mathematics, English };
enum SortFld { ID, NA, CH, MA, EN, AVG };


class Student
{
	unsigned int num;
	string name;
	float scores[3];
public:
	Student(void);
	~Student(void);
	friend bool operator < (Student &s1,Student &s2);
	friend bool operator > (Student &s1,Student &s2);
	friend ostream& operator << (ostream& out, Student &s);
	inline float Average()//ƽ����
	{
		return Total()/3;
	}
	inline float Total()//�ܷ�
	{
		return scores[Chinese]+scores[Mathematics]+scores[English];
	}
	inline bool IsPassed(Course c)//�����Ƿ�ͨ��
	{
		return scores[c]>=60 ? true : false;
	}
	inline bool IsAllPassed()//���п�Ŀ�Ƿ�ͨ��
	{
		return IsPassed(Chinese) && IsPassed(Mathematics) && IsPassed(English);
	}
};

bool operator < (Student &s1,Student &s2);
bool operator > (Student &s1,Student &s2);
ostream& operator << (ostream& out, Student& s);
