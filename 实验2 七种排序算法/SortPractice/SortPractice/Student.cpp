#include <iomanip>
#include "Student.h"
#include "ProRandomStringData.h"
#include "ProRandomFloatData.h"

unsigned int StudentID=1;
//extern SortFld sFld;
SortFld sFld = ID;

Student::Student(void)
{
	//学号自动加1
	num=StudentID++;
	//自动生成5个英文字符名字
	name="";
	name+=GetUpper();
	for(int i=1;i<5; i++)
		name+=GetLower();
	for(int j=0;j<3; j++)
		scores[j]= ProARandomFloat(70.0f,10.0f);

}


Student::~Student(void)
{

}

bool operator < (Student &s1,Student &s2)
{
	switch(sFld)
	{
	case ID:
		return s1.num < s2.num;
	case NA:
		return s1.name < s2.name;
	case CH:
		return s1.scores[Chinese] < s2.scores[Chinese];
	case MA:
		return s1.scores[Mathematics] < s2.scores[Mathematics];
	case EN:
		return s1.scores[English] < s2.scores[English];
	case AVG:
		return s1.Average() < s2.Average();
	}
	return false;
}

bool operator > (Student &s1,Student &s2)
{
	switch(sFld)
	{
	case ID:
		return s1.num > s2.num;
	case NA:
		return s1.name > s2.name;
	case CH:
		return s1.scores[Chinese] > s2.scores[Chinese];
	case MA:
		return s1.scores[Mathematics] > s2.scores[Mathematics];
	case EN:
		return s1.scores[English] > s2.scores[English];
	case AVG:
		return s1.Average() > s2.Average();
	}
	return false;
}

ostream& operator << (ostream& out, Student& s)
{
	out<<setiosflags(ios::right);
	out<<setw(10)<<s.num<<' '<<setw(5)<<s.name<<' ';
	out<<setprecision(1)<<setiosflags(ios::fixed);
	out<<setw(5)<<s.scores[Chinese]<<' ';
	out<<setw(5)<<s.scores[Mathematics]<<' ';
	out<<setw(5)<<s.scores[English]<<' ';
	out<<setw(5)<<s.Total()<<' ';
	out<<setw(5)<<s.Average()<<' ';
	return out;
}