#pragma once
#include<string>
using namespace std;
#include "Student.h"

//显示主窗口
void ProgramMainWindow();
//程序操作窗口
void ProgramManipWindow();
//学生程序操作窗口
void ProgramStudentManipWindow();
//选择获取数据的方法
void GetDataMethod(int&);

//输入随机数的个数
void InputRandomNum(int& n);
//输入保存随机数的文件名
void InputRandomFileName(string& str);
//输入排序结果的文件名
void InputSortResultFileName(string& str);
//选择排序方法
void SelectSortMethod(int&);
//选择排序字段
void SelectSortField(SortFld&);
//设置排序的方式(升序或降序)
void SetSortMode(char& SortMode);
//调用所有排序算法
void AllSortMethod(string FileName, string* ra,int rn,char SortMode);
