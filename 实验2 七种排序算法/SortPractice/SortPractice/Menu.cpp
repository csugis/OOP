#include<iostream>
#include <windows.h>
#include "Sort.cpp"
#include <string>
using namespace std;
#include "Student.h"
#include "ProRandomStringData.h"
#include "ReadWriteFile.h"
#include "Menu.h"

extern SortFld sFld;

void ProgramMainWindow()
{
	cout << endl << endl << endl;
	cout << "\t||===============================================================||" << endl;
	cout << "\t||=========================程序功能介绍==========================||" << endl;
	cout << "\t||---------------------------------------------------------------||" << endl;
	cout << "\t||   随机生成一定数量的字符串型数据，采用以下7种排序算法进行排序,||" << endl;
	cout << "\t||对比分析各算法的排序效率。排序算法如下：                       ||" << endl;
	cout << "\t||         1、冒泡排序；2 选择排序；3 插入排序；4 堆排序；       ||" << endl;
	cout << "\t||         5、希尔排序；6 归并排序；7 快速排序.                  ||" << endl;
	cout << "\t||---------------------------------------------------------------||" << endl;
	cout << "\t||                          按任意键继续                         ||" << endl;
	cout << "\t||===============================================================||" << endl;
	system("pause");
}
//学生程序操作窗口
void ProgramStudentManipWindow()
{
	cout << endl << endl << endl;
	cout << "\t||===============================================================||" << endl;
	cout << "\t||=========================程序操作窗口==========================||" << endl;
	cout << "\t||---------------------------------------------------------------||" << endl;
	cout << "\t||   随机生成字符串型数据体，采用不同排序算法排序，对比排序效率  ||" << endl;
	cout << "\t||---------------------------------------------------------------||" << endl;
	cout << "\t||                           1: 开始排序过程                     ||" << endl;
	cout << "\t||                           0: 退出程序                         ||" << endl;
	cout << "\t||---------------------------------------------------------------||" << endl;
	cout << "\t||                           输入: 0 或 1                        ||" << endl;
	cout << "\t||===============================================================||" << endl;	
	string str;
	cin >> str;
	int ad = atoi(str.c_str());	
	if (ad > 1 || ad < 0)ProgramManipWindow();
	/////////////////////////////////////////////////////////////////////////////////////
	if (ad == 1)
	{		
		/////////////////////////////////////////////////////////////////////////////////
		int rn;             //产生随机数的个数
		Student *ra = NULL;  //随机学生	
		int sm;             //排序算法
		char  SortMode;     //升序还是降序	
				/////////////////////////////////////////////////////////////////////////////////
		//int mGetDataMethod;
		//GetDataMethod(mGetDataMethod);
		if(true/*mGetDataMethod*/)
		{		
			//输入产生随机数的个数
			InputRandomNum(rn);		
			try
			{
				ra = new Student[rn];//产生随机学生
			}
			catch (bad_alloc & memExp)
			{
				cerr << memExp.what() << endl;
				//重新输入随机数个数
				InputRandomNum(rn);
			}
			
			//输入随机数保存的文件名
			string FileName; //文件名			
			InputRandomFileName(FileName);			
			//将随机数保存到FileName文件
			WriteClsFile(FileName, ra, rn);
			//选择排序算法
			SelectSortMethod(sm);
			//选择排序字段
			SelectSortField(sFld);
			//设置排序的方式(升序或降序)
			SetSortMode(SortMode);
			/////////////////////////////////////////////////////////////////////////////
			//调用排序函数
			cout << endl << endl << endl;
			cout << "\t||===============================================================||" << endl;
			cout << "\t||---------------------------------------------------------------||" << endl;
			cout << "\t||-------------------------正在排序......------------------------||" << endl;
			//获取排序前的系统时间
			long t1 = GetTickCount(); 	
			//初始化排序类对象
			CSort<Student> object(ra, rn, sm, SortMode);
			//开始排序
			object.Sort();	
			//获取排序前的系统时间
			long t2 = GetTickCount(); 					
			cout << "\t||---------------------排序结束! 耗费时间：" << t2 - t1 << " MS" << endl;
			cout << "\t||---------------------------------------------------------------||" << endl;
			cout << "\t||===============================================================||" << endl;
			//输入排序结果的文件名
			InputSortResultFileName(FileName);
			//将排序结果保存到FileName文件
			WriteClsFile(FileName, ra, rn);	
			if (ra != NULL)delete[]ra;
		}
		///////////////////////////////////////////////////////////////////////
		//返回主窗口
		system("pause");
		system("cls");
		ProgramStudentManipWindow();
	}
	else
	{
		//退出程序
		return;
	}
}
//程序操作窗口
void ProgramManipWindow()
{
	cout << endl << endl << endl;
	cout << "\t||===============================================================||" << endl;
	cout << "\t||=========================程序操作窗口==========================||" << endl;
	cout << "\t||---------------------------------------------------------------||" << endl;
	cout << "\t||   随机生成字符串型数据体，采用不同排序算法排序，对比排序效率  ||" << endl;
	cout << "\t||---------------------------------------------------------------||" << endl;
	cout << "\t||                           1: 开始排序过程                     ||" << endl;
	cout << "\t||                           0: 退出程序                         ||" << endl;
	cout << "\t||---------------------------------------------------------------||" << endl;
	cout << "\t||                           输入: 0 或 1                        ||" << endl;
	cout << "\t||===============================================================||" << endl;	
	string str;
	cin >> str;
	int ad = atoi(str.c_str());	
	if (ad > 1 || ad < 0)ProgramManipWindow();
	/////////////////////////////////////////////////////////////////////////////////////
	if (ad == 1)
	{		
		/////////////////////////////////////////////////////////////////////////////////
		int rn;             //产生随机数的个数
		string *ra = NULL;  //随机数		
		//int sm;             //排序算法
		char  SortMode;     //升序还是降序		
		/////////////////////////////////////////////////////////////////////////////////

		//输入产生随机数的个数
ERRNUM:
		InputRandomNum(rn);		
		try
		{
			ra = new string[rn];
		}
		catch (bad_alloc & memExp)
		{
			cerr << memExp.what() << endl;
			//重新输入随机数个数
			goto ERRNUM;
			//InputRandomNum(rn);//？
		}
		//产生随机整数
		ProRandomStringData(ra, rn);
		//输入随机数保存的文件名
		string FileName; //文件名			
		InputRandomFileName(FileName);			
		//将随机数保存到FileName文件
		WriteBinaryFile(FileName, ra, rn);
		//设置排序的方式(升序或降序)
		SetSortMode(SortMode);
		//调用所有排序算法
		AllSortMethod(FileName, ra,rn, SortMode);

		if (ra != NULL)delete[]ra;

		///////////////////////////////////////////////////////////////////////
		//返回主窗口
		system("pause");
		system("cls");
		ProgramManipWindow();
	}
	else
	{
		//退出程序
		return;
	}
}
//调用所有排序算法
void AllSortMethod(string FileName, string* ra,int rn,char SortMode)
{
		/////////////////////////////////////////////////////////////////////////////
		//调用排序函数
		for(int i=1; i<=7; i++)
		{
			ReadBinaryFile(FileName,ra,rn);
			cout << endl << endl << endl;
			cout << "\t||===============================================================||" << endl;
			cout << "\t||---------------------------------------------------------------||" << endl;
			cout << "\t||-------------------------正在排序......------------------------||" << endl;
			//初始化排序类对象
			CSort<string> object(ra, rn, i, SortMode);
			//获取排序前的系统时间
			long t1 = GetTickCount(); 			
			//开始排序
			object.Sort();	
			//获取排序后的系统时间
			long t2 = GetTickCount(); 					
			cout << "\t||---------------------排序结束! 耗费时间：" << t2 - t1 << " MS" << endl;
			cout << "\t||---------------------------------------------------------------||" << endl;
			cout << "\t||===============================================================||" << endl;
			//输入排序结果的文件名
			string outFileName = FileName + to_string(i);	//(_ULonglong)		
			//将排序结果保存到FileName文件
			WriteBinaryFile(outFileName, ra, rn);	
		}
}
//获取随机数的个数
void InputRandomNum(int& n)
{
	cout << endl << endl << endl;
	cout << "\t||===============================================================||" << endl;
	cout << "\t||---------------------------------------------------------------||" << endl;
	cout << "\t||                 输入产生随机数的个数n: <1--1亿>               ||" << endl;
	cout << "\t||---------------------------------------------------------------||" << endl;
	cout << "\t||===============================================================||" << endl;	
	string str;
	cin >> str;
	n = atoi(str.c_str());	
	if (n <= 0 || n >= INT_MAX)InputRandomNum(n);
}
//输入随机数保存的文件
void InputRandomFileName(string &str)
{
	cout << endl << endl << endl;
	cout << "\t||===============================================================||" << endl;
	cout << "\t||---------------------------------------------------------------||" << endl;
	cout << "\t||                   输入随机数保存的文件名:                     ||" << endl;
	cout << "\t||---------------------------------------------------------------||" << endl;
	cout << "\t||===============================================================||" << endl;
	cin >> str;
	if (str == "")InputRandomFileName(str);
	str += ".dat";
}
//输入排序结果的文件名
void InputSortResultFileName(string& str)
{
	cout << endl << endl << endl;
	cout << "\t||===============================================================||" << endl;
	cout << "\t||---------------------------------------------------------------||" << endl;
	cout << "\t||                 输入排序结果保存的文件名:                     ||" << endl;
	cout << "\t||---------------------------------------------------------------||" << endl;
	cout << "\t||===============================================================||" << endl;
	cin >> str;
	if (str == "")InputRandomFileName(str);
	str += ".dat";
}
//获取数据
void GetDataMethod(int& Method)
{
	cout << endl << endl << endl;
	cout << "\t||===============================================================||" << endl;
	cout << "\t||=========================获取数据方法==========================||" << endl;
	cout << "\t||---------------------------------------------------------------||" << endl;	
	cout << "\t||                       1: 产生随机整数                         ||" << endl;	
	cout << "\t||---------------------------------------------------------------||" << endl;
	cout << "\t||                       0: 返回上一级菜单                       ||" << endl;
	cout << "\t||===============================================================||" << endl;	
	string str;
	cin >> str;
	Method = atoi(str.c_str());	
	if (Method < 0 || Method>1)GetDataMethod(Method);
}
//选择排序字段
void SelectSortField(SortFld &sf)
{
	cout << endl << endl << endl;
	cout << "\t||===============================================================||" << endl;
	cout << "\t||==========================选择排序字段=========================||" << endl;
	cout << "\t||---------------------------------------------------------------||" << endl;
	cout << "\t||                     可选择的排序算法<1--7>:                   ||" << endl;
	cout << "\t||                           1: 学    号                         ||" << endl;
	cout << "\t||                           2: 姓    名                         ||" << endl;
	cout << "\t||                           3: 语    文                         ||" << endl;
	cout << "\t||                           4: 数    学                         ||" << endl;
	cout << "\t||                           5: 英    语                         ||" << endl;
	cout << "\t||                           6: 平 均 分                         ||" << endl;
	cout << "\t||---------------------------------------------------------------||" << endl;
	cout << "\t||                        0: 返回上一级菜单                      ||" << endl;
	cout << "\t||===============================================================||" << endl;	
	string str;
	cin >> str;
	int isf = atoi(str.c_str());
	switch(isf)
	{
	case 1:sf=ID;break;
	case 2:sf=NA;break;
	case 3:sf=CH;break;
	case 4:sf=MA;break;
	case 5:sf=EN;break;
	case 6:sf=AVG;break;
	default:
		if (isf < 0 || isf>6) SelectSortField(sf);
	}
}
/////////////////////////////////////////////////////////////////////////////////////////
//选择排序算法
void SelectSortMethod( int &sm)
{
	cout << endl << endl << endl;
	cout << "\t||===============================================================||" << endl;
	cout << "\t||==========================选择排序算法=========================||" << endl;
	cout << "\t||---------------------------------------------------------------||" << endl;
	cout << "\t||                     可选择的排序算法<1--7>:                   ||" << endl;
	cout << "\t||                           1: 冒泡排序                         ||" << endl;
	cout << "\t||                           2: 选择排序                         ||" << endl;
	cout << "\t||                           3: 插入排序                         ||" << endl;
	cout << "\t||                           4: 堆排序                           ||" << endl;
	cout << "\t||                           5: 希尔排序                         ||" << endl;
	cout << "\t||                           6: 归并排序                         ||" << endl;
	cout << "\t||                           7: 快速排序                         ||" << endl;
	cout << "\t||---------------------------------------------------------------||" << endl;
	cout << "\t||                        0: 返回上一级菜单                      ||" << endl;
	cout << "\t||===============================================================||" << endl;	
	string str;
	cin >> str;
	sm = atoi(str.c_str());
	if (sm < 0 || sm>7)SelectSortMethod(sm);
}
//设置排序的方式(升序或降序)
void SetSortMode(char& SortMode)
{
	cout << endl << endl << endl;
	cout << "\t||===============================================================||" << endl;
	cout << "\t||==========================设置排序方式=========================||" << endl;
	cout << "\t||---------------------------------------------------------------||" << endl;	
	cout << "\t||                        1: 升序(从小到大)                      ||" << endl;
	cout << "\t||                        2: 降序(从大到小)                      ||" << endl;	
	cout << "\t||---------------------------------------------------------------||" << endl;	
	cout << "\t||===============================================================||" << endl;		
	string str;
	cin >> str;
	int ad = atoi(str.c_str());
	if (ad < 1 || ad > 2)SetSortMode(SortMode);
	if (ad == 1)SortMode = '<';
	else        SortMode = '>';
}